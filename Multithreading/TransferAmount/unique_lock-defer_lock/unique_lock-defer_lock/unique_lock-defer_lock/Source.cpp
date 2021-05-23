#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
using namespace chrono;

class BankingAccount {
private:
	mutex m;
	int balance;
public:
	explicit BankingAccount(int _balance) : balance(_balance) {}
	int getBalance() { return balance; }
	friend void transfer(BankingAccount* b1, BankingAccount* b2, int amount);
};

void transfer(BankingAccount* b1, BankingAccount* b2, int amount) {
	// std::unique_lock doesn't always own the mutex, it's associated 
	// with. The 2nd argument std::defer_lock indiactes that mutex should remain
	// unlocked on construction. The lock can then be acquired later by calling
	// lock() on std::unique_lock object. 
	unique_lock<mutex> guard1(b1->m, defer_lock);
	this_thread::sleep_for(milliseconds(2));// putting using namespace chrono so that I dont use chrono::milliseconds
	unique_lock<mutex> guard2(b2->m, defer_lock);
	lock(guard1, guard2);
	b1->balance -= amount;
	b2->balance += amount;
}

int main() {
	BankingAccount b1(500);
	BankingAccount b2(300);

	cout << "B1 balance before transfer : " << b1.getBalance() << "\n";
	cout << "B2 balance before transfer : " << b2.getBalance() << "\n";

	thread t1(transfer, &b1, &b2, 30);
	thread t2(transfer, &b2, &b1, 50);

	if (t1.joinable()) t1.join();
	if (t2.joinable()) t2.join();

	cout << "B1 balance after transfer : " << b1.getBalance() << "\n";
	cout << "B2 balance after transfer : " << b2.getBalance() << "\n";

	return 0;
}