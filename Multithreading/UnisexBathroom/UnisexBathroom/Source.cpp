#include<iostream>
#include<thread>
#include<queue>
#include<condition_variable>
#include<mutex>
#include <chrono>
#include<ctime>
using namespace std;

// this problem is based on Reader and Writer problem 
// Since there is only one washroom and that is the critical section 
// Only one twist is there : the number is fixed for each type of employee : male or female
// Maximum number of employees(of only one type) that can use the washroom is MAX_NUM
// when males are using the washroom then females cant use it.

class protectedWashroom {

private:
	int MAX_NUM;
	//int empCount;
	int femEmp;
	int maleEmp;
	int flagm;
	int flagf;
	condition_variable condVar;
	mutex mu;
public:
	protectedWashroom(int m) {
		MAX_NUM = m;
		femEmp = 0;
		maleEmp = 0;
		flagm = 0;
		flagf = 0;
	}

	void occupyByMale(string str) {
		unique_lock<mutex> lck(mu);
		condVar.wait(lck, [=]() {
			if (femEmp > 0) {
				if (flagm && maleEmp < MAX_NUM) { // this new check is there that helps limit the number of employees using the washoom at a time.
					return true;
				}
				return false;
			}
			else {
				flagm = 1; // instead of usinf firstReader , we are using flagm = first male entered the washroom when the washroom was empty
				femEmp = 1;
				return true;
			}
			});
		cout << str << " occupied washroom" << endl;
		maleEmp++;
		lck.unlock();
	}

	void FreedByMale(string str) {
		unique_lock<mutex> lck(mu);
		maleEmp--;
		if (maleEmp == 0) {
			femEmp = 0;
			flagm = 0;
		}
		cout << str << " freed the washroom" << endl;
		lck.unlock();
		condVar.notify_all();
	}


	void occupyByFemale(string str) {
		unique_lock<mutex> lck(mu);
		condVar.wait(lck, [=]() {
			if (maleEmp > 0) {
				if (flagf && femEmp < MAX_NUM) {
					return true;
				}
				return false;
			}
			else {
				flagf = 1;
				maleEmp = 1;
				return true;
			}
			});
		cout << str << " occupied washroom" << endl;
		femEmp++;
		lck.unlock();
	}

	void FreedByFemale(string str) {
		unique_lock<mutex> lck(mu);
		femEmp--;
		if (femEmp == 0) {
			maleEmp = 0;
			flagf = 0;
		}
		cout << str << " freed the washroom" << endl;
		lck.unlock();
		condVar.notify_all();
	}

};

int main() {
	protectedWashroom* ws = new protectedWashroom(3);

	thread m1([=]() {
		ws->occupyByMale("m1");
		this_thread::sleep_for(std::chrono::seconds(2));
		ws->FreedByMale("m1");
		});

	thread m2([=]() {
		ws->occupyByMale("m2");
		this_thread::sleep_for(std::chrono::seconds(2));
		ws->FreedByMale("m2");
		});

	thread w1([=]() {
		ws->occupyByFemale("w1");
		this_thread::sleep_for(std::chrono::seconds(5));
		ws->FreedByFemale("w1");
		});

	thread w2([=]() {
		ws->occupyByFemale("w2");
		this_thread::sleep_for(std::chrono::seconds(7));
		ws->FreedByFemale("w2");
		});

	thread w3([=]() {
		ws->occupyByFemale("w3");
		this_thread::sleep_for(std::chrono::seconds(2));
		ws->FreedByFemale("w3");
		});

	thread w4([=]() {
		ws->occupyByFemale("w4");
		this_thread::sleep_for(std::chrono::seconds(2));
		ws->FreedByFemale("w4");
		});

	thread w5([=]() {
		ws->occupyByFemale("w5");
		this_thread::sleep_for(std::chrono::seconds(2));
		ws->FreedByFemale("w5");
		});

	m1.join();
	m2.join();
	w1.join();
	w2.join();
	w3.join();
	w4.join();
	w5.join();


	cout << "program concluded" << endl;
		return 0;
}