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
		locker.unlock();
		condVar.notify_all();
	}

	void release(string str) {
		unique_lock<mutex> locker(mu);
		condVar.wait(locker, [=] {
			return countOfPermits == 0 ? false : true;
			});
		//this_thread::sleep_for(std::chrono::seconds(2));
		cout << str << " running, permit released " << endl;
		countOfPermits--;
		cout<<"------------remaining :" << MAX_PERMITS - countOfPermits << endl;
		cout << endl;
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