#include <iostream>
#include <thread>
#include <condition_variable> 
#include <mutex>
#include <queue>
#include <string>
#include <cstdlib>
#include <chrono>

using namespace std;

#define DEBUG 0
// Consumer and producer class ( I will be using token and product interchangeably ,  queue and bucket intechangeably) 
class RateLimiter {
private:
	queue<int> q;
	int MAX_SIZE;
	int N;
	int cnt;
	condition_variable condVar;
	mutex mu;
	bool flag;;
	bool flag2;

public:
	RateLimiter(int maxSize, int N) {
		MAX_SIZE = maxSize;
		this->N = N;
		cnt = 1;
		flag = true;
		flag2 = true;
	}

	// This method produces 1 product every 1 second : Rate limiting producer
	// it has 2 things to take care:
	// The bucket size : N 
	// The max quantity of threads it will create : MAX_SIZE
	
	// When producer reaches N , it needs to stop producing more products as the bucket size is full, this is controlled by variable 'return q.size() < N ' (inside the lambda function of condVar).
	// >>>>> the if condition inside the lambda function for the condVar is there because when the total number of products produced has reached MAX_SIZE.
	// >>>>> we require that if condition becasue it returns true , that is required because the thread needs to end itself with the first if condition : if(cnt > MAX_SIZE)
	// >>>>> it releases the mutex and the condition variable notifies all , before it returns.


	void producer2(string kk) {
		while (cnt <= MAX_SIZE) { // if in this while loop we put '<' instead of '<=' then the condition never reaches the cnt==MAX_SIZE and the consumer 
			                      // does not starve to death , they keep on waiting because they wait for the product numbered as MAX_SIZE in the queue 
			                      // from which they consume. If they find that numebr then all the other waiting threads starve to death. 
		unique_lock<mutex> locker(mu);
#if DEBUG
		cout << kk << " started... with cnt = " << cnt << endl;
#endif
		condVar.wait(locker, [&] {
			if (!flag) return true;
			return q.size() < N ? true : false;
			});
#if DEBUG
		cout << kk << " came out of waiting... " << endl;
#endif
		if (cnt > MAX_SIZE) { 
			locker.unlock();
			condVar.notify_all();
			return; }
		q.push(cnt);
		cout << "produced = " << cnt << endl;
		cnt++;
		if (cnt > MAX_SIZE) flag = false;
#if DEBUG
		cout << kk << " exiting..." << endl;
#endif
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		locker.unlock();
		condVar.notify_all();
		
		}
	}

	// This method consumes whenever there is a product available in the queue(bucket). When there is none in the bucket , there are two conditions:
	// 1. Either the bucket is about to get filled i.e. after everysecond there will be a new procut avaialble in the queue(bucket
	//    In this case the threads will wait.
	// 2. The number of products have exhausted and cnt>=MAX_SIZE
	//    In this case the threads will go to if condition inside the lambda function of condVar and continue its operatiom until they exit 
	//    from the if condition : if(!flag2)
	//    >>>>> flag2 is set when the current consumer thread encounters the last produced product in the bucket and then when it exits it notifies all the waiting condumer 
	//    >>>>> thread to starve and finish their execution.

	void consumer(string kk) {
		unique_lock<mutex> locker(mu);
#if DEBUG
		cout << kk << " started..." << endl;
#endif
		condVar.wait(locker, [&] {
			if (!flag2) return true;
			return q.size() > 0 ? true :false;
			});
#if DEBUG
		cout << kk << " csme out of waiting.." << endl;
#endif
		if (!flag2) {
			cout << "starved to death.....  " <<kk<< endl;
			locker.unlock();
			condVar.notify_all();
			return;
		}
		int temp = q.front();
		if (temp == MAX_SIZE) flag2 = false;

		cout <<kk<< " Consumed = " << temp << endl;
		q.pop();
#if DEBUG
		cout << kk << " exiting..." << endl;
#endif
		locker.unlock();
		condVar.notify_all();
	}
};


int main() {

	RateLimiter* prog = new RateLimiter(10,4);

	thread c1(&RateLimiter::consumer, prog, "consumer1");
	thread c2(&RateLimiter::consumer, prog, "consumer2");
	thread p1(&RateLimiter::producer2, prog,"producer");
	// breaking the initialization of the cumsumer threads with a sleep will make the producer to produce products until the bucket is full
	// and when the bucket is full the producer thread will stop and wait for the consumer thread to consume.
	cout << "waiting for 5 seconds" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(15000));
	// throwing all the consumer threads all at once will only make them wait until they get a product from the queue
	// if the products finish then the consumer thread will starve and exit.
	thread c4(&RateLimiter::consumer, prog, "consumer4");
	thread c3(&RateLimiter::consumer, prog, "consumer3");
	thread c6(&RateLimiter::consumer, prog, "consumer6");
	thread c5(&RateLimiter::consumer, prog, "consumer5");
	thread c8(&RateLimiter::consumer, prog, "consumer8");
	thread c7(&RateLimiter::consumer, prog, "consumer7");
	thread c21(&RateLimiter::consumer, prog, "consumer21");
	thread c22(&RateLimiter::consumer, prog, "consumer22");
	thread c23(&RateLimiter::consumer, prog, "consumer23");
	thread c25(&RateLimiter::consumer, prog, "consumer25");
	thread c28(&RateLimiter::consumer, prog, "consumer28");
	thread c27(&RateLimiter::consumer, prog, "consumer27");

	
	c21.join();
	c22.join();
	c23.join();
	c25.join();
	c28.join();
	c27.join();
	
	c1.join();
	c2.join();
	p1.join();
	
	
	c3.join();
	c8.join();
	c7.join();
	c6.join();
	c5.join();
	c4.join();


	cout << "program is concluded" << endl;
	return 0;
	

}



/*
	Inside the int main , I tried the initialization like below.
	I was doing 2 things:
	1. The producder thread were many and they were called after every second. I was joining them immediately after their initialization.
	   According to me this should have worked (but it didnt as the program used to get stuck after the 1st producer produced. And after the first consumer (either 1 or 2) consumed , it stopped)
	   (maybe because the variables that the producer method was using werent static and at every producer entry & exit the state of the variables reset------ IDK)
	2. ---- the same thing in 1st point only. The 2 points kinda got mixed in the first point.



	thread c1(&RateLimiter::consumer, prog, "consumer1");
	thread c2(&RateLimiter::consumer, prog, "consumer2");
	thread p1(&RateLimiter::producer, prog,"producer1");

	cout << "1 sec wait....." << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	c1.join();
	c2.join();
	p1.join();

	thread p2(&RateLimiter::producer, prog,"producer2");
	p2.join();
	cout << "2nd sec wait....." << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));



	thread p3(&RateLimiter::producer, prog,"producer3");
	p3.join();
	cout << "3rd sec wait....." << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));



	thread p4(&RateLimiter::producer, prog,"producer4");
	p4.join();
	cout << "4th sec wait....." << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	thread c4(&RateLimiter::consumer, prog, "consumer4");
	thread c3(&RateLimiter::consumer, prog, "consumer3");
	thread c6(&RateLimiter::consumer, prog, "consumer6");
	thread c5(&RateLimiter::consumer, prog, "consumer5");
	thread c8(&RateLimiter::consumer, prog, "consumer8");
	thread c7(&RateLimiter::consumer, prog, "consumer7");
	c3.join();
	c8.join();
	c7.join();
	c6.join();
	c5.join();
	c4.join();

	thread p5(&RateLimiter::producer, prog,"producer5");
	p5.join();
	cout << "5th sec wait....." << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));



	thread p6(&RateLimiter::producer, prog,"producer6");
	p6.join();
	cout << "6th sec wait....." << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));



	thread p7(&RateLimiter::producer, prog,"producer7");
	p7.join();
	cout << "7th sec wait....." << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	thread p8(&RateLimiter::producer, prog,"producer8");
	p8.join();
	cout << "8th sec wait....." << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	thread p9(&RateLimiter::producer, prog,"producer9");
	p9.join();
	cout << "9th sec wait....." << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));


	thread p10(&RateLimiter::producer, prog,"producer10");
	p10.join();
	cout << "10-14th sec wait....." << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	thread c21(&RateLimiter::consumer, prog, "consumer21");
	thread c22(&RateLimiter::consumer, prog, "consumer22");
	thread c23(&RateLimiter::consumer, prog, "consumer23");
	thread c25(&RateLimiter::consumer, prog, "consumer25");
	thread c28(&RateLimiter::consumer, prog, "consumer28");
	thread c27(&RateLimiter::consumer, prog, "consumer27");

	c21.join();
	c22.join();
	c23.join();
	c25.join();
	c28.join();
	c27.join();

*/