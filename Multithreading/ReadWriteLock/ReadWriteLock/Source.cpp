#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;

class ReadWriteLock {

private:
	mutex mu;
	condition_variable condVar;
	int readers; // to count readers 
	int writer; // to count writers , only one is allowed at a time
	bool firstReader;
	
public:

	ReadWriteLock() {
		this->readers = 0;
		this->writer = 0;
	}
	// In read lock we have to take care that only readers are inside the critical section 
	// condtions are like this:
	// Before entering the critical section by any reader , it has to check if there is any writer inside the critical section
	// If yes then wait OR
	// it has to make sure that no other writer thread enters the critical section hence it increases the writer count and sets the firtReader flag (line 42) which tells that 
	// it is done by the reader as a security against writer thread and not done by writer itself for writerLock
	
	void acquireReadLock(string str) {
		unique_lock<mutex> lck(mu);
		condVar.wait(lck, [=] {
			if (writer > 0) {
				if (firstReader == true) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				firstReader = true;
				return true;
			}
		});

		std::cout << str << " reader Allowed" << endl;
		readers++;
		lck.unlock();
		// we dont need to notify anybody
	}

	void releaseReadLock(string str) {
		unique_lock<mutex> lck(mu);
		readers--;
		if (readers == 0) {
			firstReader = false;
		}
		std::cout << str << " out of reader section" << endl;
		lck.unlock();
		condVar.notify_all(); // here we need to notify because there may be a writer waiting for the reader thread to be 0
	}

	void acquireWriteLock(string str) {
		unique_lock<mutex> lck(mu);
		condVar.wait(lck, [=]() {
			if (writer > 0 || readers > 0) return false;
			else {
				writer = 1;
				return true;
			}
			});
		cout << str << " acquired the critical Section for updation" << endl;
		lck.unlock();


	}

	void releaseWriteLock(string str) {
		unique_lock<mutex> lck(mu);
		writer = 0;
		cout << str <<" released the lock" << endl;
		lck.unlock();
		condVar.notify_all();
	}

};


int main() {

	ReadWriteLock *rw = new ReadWriteLock();


	thread tWriter1([=] {
		rw->acquireWriteLock("writer1");
		this_thread::sleep_for(std::chrono::seconds(2));
		rw->releaseWriteLock("writer1");
		});
	thread t1([=] {
		rw->acquireReadLock("reader1");
		this_thread::sleep_for(std::chrono::seconds(7));
		rw->releaseReadLock("reader1");
		});

	/*thread t2([=] {
		rw->acquireReadLock("reader2");
		this_thread::sleep_for(std::chrono::seconds(6));
		rw->releaseReadLock("reader2");
		});

	thread t3([=] {
		rw->acquireReadLock("reader3");
		this_thread::sleep_for(std::chrono::seconds(5));
		rw->releaseReadLock("reader3");
		});
	*/
	thread t4([=] {
		rw->acquireReadLock("reader4");
		this_thread::sleep_for(std::chrono::seconds(1));
		rw->releaseReadLock("reader4");
		});

	/*thread t5([=] {
		rw->acquireReadLock("reader5");
		this_thread::sleep_for(std::chrono::seconds(2));
		rw->releaseReadLock("reader5");
		});*/
	
	thread tWriter3([=] {
		rw->acquireWriteLock("writer3");
		this_thread::sleep_for(std::chrono::seconds(5));
		rw->releaseWriteLock("writer3");
		});
	/*thread t6([=] {
		rw->acquireReadLock("reader6");
		this_thread::sleep_for(std::chrono::seconds(2));
		rw->releaseReadLock("reader6");
		});*/
	
	thread t7([=] {
		rw->acquireReadLock("reader7");
		this_thread::sleep_for(std::chrono::seconds(3));
		rw->releaseReadLock("reader7");
		});

	thread tWriter2([=] {
		rw->acquireWriteLock("writer2");
		this_thread::sleep_for(std::chrono::seconds(4));
		rw->releaseWriteLock("writer2");
		});


	
	tWriter1.join();
	tWriter2.join();
	tWriter3.join();
	t1.join();
	/*t2.join();
	t3.join();*/
	t4.join();
	//t5.join();
	//t6.join();
	t7.join();

		cout << "program concluded" << endl;


		return 0;

}