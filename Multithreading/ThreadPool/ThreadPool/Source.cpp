#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <functional>
#include <queue>
//#include <function>
using namespace std;

class myThreadPool {
private:
	queue<function<void()>> q;
	int threadsRequired;
	bool isWorkFinished=false;
	vector<thread> m_workers;
	mutex mu;
	condition_variable condVar;

public:

	void Submit(function<void()>&& f) {
		cout << "Submit happenend" << endl;
		unique_lock<mutex> lck(mu);
		q.push(move(f));
		condVar.notify_all();
	}

	myThreadPool(int threadsRequired = 0) {
		m_workers.reserve(threadsRequired);
		cout << "constructor called : "<<threadsRequired<<"\n";

		for (int i = 0; i < threadsRequired; i++) {
			m_workers.push_back(thread([this]() {
				cout << "Inside for loop of constructor\n";

				while (!isWorkFinished) {
					
					function<void()> job;
					cout << "getting job\n";
					{
						unique_lock<mutex> lck(mu);
						condVar.wait(lck, [this]() {
								
							if (true == isWorkFinished) {
								return true;
							}

							if (q.empty() && isWorkFinished==false)
								return false;	
							else
								return true;

						});

						if (!q.empty()) {
							job = move(q.front());
							q.pop();
						}
						
					}

					if (job != NULL) {
						cout << "implemented by thread : " << this_thread::get_id()<<"\n";
						job();
					}

				}
			}));
		}
	}

	~myThreadPool() {
		isWorkFinished = true;
		condVar.notify_all();
		cout << "<<<<<<<<<<<<reached here<<<<<<<<";
		for (auto& k : m_workers) {
			if (k.joinable()) {
				k.join();
			}
		}
	}

	//void joinALL() {
	//	cout << "joinALL called\n";
	//	for (auto& k : m_workers) {
	//		k.join();
	//	}
	//	cout << "exiting joinALL\n";
	//}

	//void setIsFinished() {
	//	isWorkFinished = true;
	//}


};


int main() {
	// using only lambda functions as the jobs that are submitted to threadPool
	auto f1 = []() {
		cout << "f1 says hello!!\n";
		this_thread::sleep_for(chrono::milliseconds(100));
	};

	auto f2 = []() {
		cout << "f2 says hello!!\n";
		this_thread::sleep_for(chrono::milliseconds(100));
	};

	auto f3 = []() {
		cout << "f3 says hello!!\n";
		this_thread::sleep_for(chrono::milliseconds(100));
	};

	auto f4 = []() {
		cout << "f4 says hello!!\n";
		this_thread::sleep_for(chrono::milliseconds(100));
	};
	auto f5 = []() {
		cout << "f5 says hello!!\n";
		this_thread::sleep_for(chrono::milliseconds(100));
	};

	auto f6 = []() {
		cout << "f6 says hello!!\n";
		this_thread::sleep_for(chrono::milliseconds(100));
	};
	auto f7 = []() {
		cout << "f7 says hello!!\n";
		this_thread::sleep_for(chrono::milliseconds(100));
	};

	auto f8 = []() {
		cout << "f8 says hello!!\n";
		this_thread::sleep_for(chrono::milliseconds(100));
	};
	auto f9 = []() {
		cout << "f9 says hello!!\n";
		this_thread::sleep_for(chrono::milliseconds(100));
	};

	auto f10 = []() {
		cout << "f10 says hello!!\n";
		this_thread::sleep_for(chrono::milliseconds(100));
	};
	
	std::vector<std::function<void()>> vec;
	vec.push_back(f1);
	vec.push_back(f2);
	vec.push_back(f3);
	vec.push_back(f4);
	vec.push_back(f5);
	vec.push_back(f6);
	vec.push_back(f7);
	vec.push_back(f8);
	vec.push_back(f9);
	vec.push_back(f10);
	
	myThreadPool tp(3);

	for (auto k : vec) {
		tp.Submit(move(k));
	}

	
	this_thread::sleep_for(chrono::seconds(2s));

	cout << "program concluded\n";




	return 0;
}