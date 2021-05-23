#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>

#define DEBUG 0


using namespace std;

class FizzBuzz{
private:

	int cnt;
	condition_variable condVar;
	mutex mu;
	int n;
	bool flag;
#if DEBUG
	int fizzCount, buzzCount, fizzbuzzCount, normalCount;
#endif

public:
	FizzBuzz(int val) {
		n = val;
		cnt = 1;
		flag = true;
#if DEBUG
		fizzCount = 0;
		buzzCount = 0;
		fizzbuzzCount = 0;
		normalCount = 0;
#endif
	}
	// at a time only one thread will be in running state  while other threads will be in waiting queue
	// This is because each thread will check its function's wait predicate 
	// condition before anything and on getting false it will wait or else run ahead


	void fizz() {
		while (flag) { // The while loop will run until the 'cnt' reaches 'n'
			unique_lock<mutex> locker(mu); // 'locker' is the unique lock that owns mutex 'mu'
#if DEBUG
			cout << "fizz thread start :  >> " <<++fizzCount<< endl;
#endif		
			// condition variable requires the predicate's value to decide the state of the thread.
			// if the predicate is false (in this case it is an anynomous function(lambda function)) , 
			// the thread will go into waiting state after the mutex that it owened is unlocked.
			// id the predicate is true , then the thread is allowed to run ahead.
			condVar.wait(locker, [&] {
				if (!flag) return true; 
				/* 
				 This has to be there which stops the condition variable wait for the current
				 thread when 'cnt' becomes greater than 'n' Earlier I did nto include this in 
				 the code , then the wait for the thread used to get triggered and it used to 
				 stay like this because the condition waited for (in this case) 'cnt' as a 
				 multiple of only 3, even when the 'cnt' had exceeded 'n'. Since the last 
				 function has already been implemented and all the other funtions are waiting 
				 till they find their required 'cnt'. deadlock occurs! So in whichever 
				 function the last thread implemented , we make sure flag=false , so that 
				 we stop the threads from waiting for a dreamy 'cnt'. And when they go ahead 
				 in the function , they encounter the break in " if (cnt > n) break; "
				 */
				return (cnt % 3 == 0 && cnt % 5 != 0) ? true : false;
				});
			if (cnt > n) {
				// since we are finished with the numbers , when we break the while loop
				// we need to unlock the locker and notify all the waiting threads.
				locker.unlock();
				condVar.notify_all();
				break;
			}
			cout << "fizz , " << endl;
			cnt++;
#if DEBUG
			cout << "fizz thread end :  >> " << fizzCount << " with cnt as : "<< cnt <<endl;
#endif
			if (cnt > n) flag = false; // this is where we wait for the 'cnt' to exceed the n , 
									   //this happens only when this function receives the cnt=n
									   // or else it simply unlocks the mutex and notifies the 
			                           // waiting threads

			locker.unlock();		// the order has to be unlock the mutex first and then notify all. 
									// This is because if we notify others and the mutex hasnt been 
			                        // released the threads wont be able to proceed because when 
			                        // coming out of wiaiting state they will again acquire the mutex 
			                        // which was revoked from them when they were being pushed into the 
									// waiting state 
			condVar.notify_all();
		}
	}

	void buzz() {
		while (flag) {
			unique_lock<mutex> locker(mu);
#if DEBUG
			cout << "buzz thread start :  >> " << ++buzzCount << endl;
#endif
			condVar.wait(locker, [&] {
				if (!flag) return true;
				return (cnt % 5 == 0 && cnt % 3 != 0) ? true : false;
				});
			if (cnt > n) {
				locker.unlock();
				condVar.notify_all();
				break;
			}
			cout << "buzz , "<<endl;
			cnt++;
#if DEBUG
			cout << "buzz thread end :  >> " << buzzCount << " with cnt as : " << cnt << endl;
#endif
			if (cnt > n) flag = false;
			locker.unlock();
			condVar.notify_all();
		}
	}

	void fizzbuzz() {
		while (flag) {
			unique_lock<mutex> locker(mu);
#if DEBUG
			cout << "fizzbuzz thread start :  >> " << ++fizzbuzzCount << endl;
#endif
			condVar.wait(locker, [&] {
				if (!flag) return true;
				return (cnt % 15 == 0) ? true : false;
				});
			if (cnt > n) {
				locker.unlock();
				condVar.notify_all();
				break;
			}
			cout << "fizzbuzz , "<<endl;
			cnt++;
#if DEBUG
			cout << "fizzbuzz thread end :  >> " << fizzbuzzCount << " with cnt as : " << cnt << endl;
#endif
			if (cnt > n) flag = false;
			locker.unlock();
			condVar.notify_all();
		}
	}

	void onlyNumber() {
		while (flag) {
			unique_lock<mutex> locker(mu);
#if DEBUG
			cout << "normal thread start :  >> " << ++normalCount << endl;
#endif
			condVar.wait(locker, [&] {
				if (!flag) return true;
				return (cnt % 3 != 0 && cnt % 5 != 0 && cnt % 15 != 0) ? true : false;
				});
			if (cnt > n) {
				locker.unlock();
				condVar.notify_all();
				break;
			}
			cout << cnt << " , "<<endl;
			cnt++;
#if DEBUG
			cout << "normal thread end :  >> " << normalCount << " with cnt as : " << cnt << endl;
#endif
			if (cnt > n) flag = false;
			locker.unlock();
			condVar.notify_all();
		}
	}
};


int main() {

	FizzBuzz *prog = new FizzBuzz(350);
	// non-static member function to be passed as the thread function 
	thread t1(&FizzBuzz::onlyNumber,prog);
	thread t2(&FizzBuzz::buzz,prog);
	thread t3(&FizzBuzz::fizz,prog);
	thread t4(&FizzBuzz::fizzbuzz,prog);

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	cout << "the program concluded" << endl;
	return 0;

}