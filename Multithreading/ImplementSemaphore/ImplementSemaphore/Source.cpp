/*
Semaphores solve the critical section problem by using two atomic 
operations, wait() and signal().

wait operation: if the value of the semaphore s is negative or zero, 
				operation is performed. If the value of s is positive, 
				it is decremented. The pseudocode for wait operation 
				is as follows:

				wait(s)
				{
					while(s<=0);
					s--;
				}

signal operation: This operation is used to increase the value of 
				  the semaphore s. The pseudocode for signal operation 
				  is as follows:

				  signal(s)
				  {
					s++
				  }

 **** Since the wait(s) and signal() are atomic operations because
      it deals with a shared data 's' . Hence the inside implementation 
	  of these functions need to be atomic too. The atomic behavious is
	  implemented using mutx and conditionvariable.

	  acquire() // -> similar to wait()
	  //critical section
	  release() // -> similar to release
*/


#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;

class SemaphoreImpl {
private:
	int countOfPermits;
	int MAX_PERMITS;
	condition_variable condVar;
	mutex mu;
public:
	SemaphoreImpl(int a) {
		countOfPermits = 0;
		MAX_PERMITS = a;
	}

	void acquire(string str) {
		unique_lock<mutex> locker(mu);
		condVar.wait(locker, [=] {
			return countOfPermits < MAX_PERMITS ? true : false;
			});
		cout << str << " running, permit acquired " << endl;
		countOfPermits++;
		cout << "------------remaining :" << MAX_PERMITS - countOfPermits << endl;
		cout << endl;
		// Unlock call is not required , it will get release when it exits the 
		// acquire function's scope. But I let it be there anyways.....
		locker.unlock();

		// We dont need to call notify over here is because we dont need to notify 
		// any thread which is waiting (in waiting queue of condVar) for not getting
		// to release the semaphore (according to previous commented out implementation
		// in release function ).
		// For the threads that are waiting in the waiting queue of condVar because of
		// unavaiabillity of permits ( in the acquire function ) , they are being signalled
		// by release function's notify call and not from acquire function notify call.

		//condVar.notify_all();
	}

	void release(string str) {
		unique_lock<mutex> locker(mu);

		// We dont need this because making a thread wait on a condition that
		// there are no permits given yet , is not logically correct
		// and even if any thread calls a release before actually acquiring it
		// we need to check if the countOfPermits is less than 0 or not
		// if it is then simply discard this and reset the value of countOfPermits
		// to zero.

		/*condVar.wait(locker, [=] {
			return countOfPermits == 0 ? false : true;
			});*/
		//this_thread::sleep_for(std::chrono::seconds(2));
		countOfPermits--;
		if (countOfPermits < 0) {
			countOfPermits = 0;
		}
		else {
			cout << str << " running, permit released " << endl;

			cout << "------------remaining :" << MAX_PERMITS - countOfPermits << endl;
			cout << endl;
		}
		
		locker.unlock();
		condVar.notify_all();
	}
};


int main() {

	SemaphoreImpl* si = new SemaphoreImpl(3); // we send in the maximum number of permits a semaphore can have

	/*thread t1(&SemaphoreImpl::acquire, si);
	thread t2(&SemaphoreImpl::release, si);*/

	// We are simulating the behavior when there are many threads which acquire a semaphore's permit and then it releases it after the thread;s work is done
	// A particular thread is trying to acquire the permit again and again.


	thread t1([=]() {
		for (int i = 0; i < 5; i++) { // thread tries to acquire the permit again and again
			si->acquire("thread1"); // tries acquiring the permit
			// does some work;
			this_thread::sleep_for(std::chrono::seconds(2));
			si->release("thread1"); // releases the permit after the thread's work is done
		}
		});

	thread t3([=]() {
		for (int i = 0; i < 6; i++) {
			si->acquire("thread3");
			// does some work;
			this_thread::sleep_for(std::chrono::seconds(2));
			si->release("thread3");
		}
		});

	thread t4([=]() {
		for (int i = 0; i < 4; i++) {
			si->acquire("thread4");
			// does some work;
			this_thread::sleep_for(std::chrono::seconds(2));
			si->release("thread4");
		}
		});

	thread t5([=]() {
		for (int i = 0; i < 7; i++) {
			si->acquire("thread5");
			// does some work;
			this_thread::sleep_for(std::chrono::seconds(2));
			si->release("thread5");
		}
		});
	/*thread t2([=]() {
		for (int i = 0; i < 15; i++) {
			si->release("therad2");
		}
		});*/



	t3.join();
	t1.join();
	t4.join();
	t5.join();
	//t2.join();

	cout << "the program concluded" << endl;
	return 0;

}