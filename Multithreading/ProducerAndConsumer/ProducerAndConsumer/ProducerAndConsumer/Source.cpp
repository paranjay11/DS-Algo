#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>


using namespace std;

condition_variable condVar;
//int currentSize;
queue<int> q;
mutex mu;
int MAX_SIZE = 10;
int TOTAL_PRODUCTS = 50;
int prodNum = 0;
bool val;


void producerPart() {
	
	while (prodNum < TOTAL_PRODUCTS) {
		unique_lock<mutex> locker(mu);
		condVar.wait(locker, [] {
			return q.size() < MAX_SIZE;
			});

		prodNum++;
		cout << "Product Produced = " << prodNum << endl;
		q.push(prodNum);
		locker.unlock();
		condVar.notify_one();
		
	}
	
}

void consumerPart() {

	while (!val) {
		unique_lock<mutex> locker(mu);
		condVar.wait(locker, [] {
			return q.size() > 0;
			});
		int k = q.front();
		cout << "Product Consumed = " << k << endl;
		if (k == TOTAL_PRODUCTS) val = true;
		q.pop();
		locker.unlock();
		condVar.notify_one();
		
	}
}


int main() {
	thread t1(consumerPart);
	thread t2(producerPart);

	t1.join();
	t2.join();

	cout << "program has concluded " << endl;

}