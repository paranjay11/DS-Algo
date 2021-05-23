#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>

using namespace std;

mutex mutex_;
condition_variable condVar;

bool dataReady{false};

void doTheWork(){
	cout<<"processing shared data"<<endl;
}

void waitingForWork(){
	cout<<"worker: waiting for work"<<endl;
	unique_lock<mutex> lck(mutex_);
	condVar.wait(lck,[]{
		return dataReady;
	});

	doTheWork();
	cout<<"Work Done"<<endl;
}

void setDataReady(){
	{
		lock_guard<mutex> lck(mutex_);
		dataReady=true;
	}

	cout<<"sender Data is ready"<<endl;
	condVar.notify_one();
}

int main(){
	thread t1(waitingForWork);
	thread t2(setDataReady);

	t1.join();
	t2.join();

	cout<<endl;
}