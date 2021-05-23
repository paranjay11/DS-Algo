#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

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
	// first two mutexes are locked
	lock(b1->m, b2->m);
	// two lock_guard instances are constructed, one for each mutex
	// std::adopt_lock parameter specifies that mutexes are already
	// locked, and they should just adopt the ownership  of the existing
	// lock on the mutex rather than attempt to lock the mutex in the
	// constructor.
	lock_guard<mutex> guard1(b1->m, adopt_lock);
	lock_guard<mutex> guard2(b2->m, adopt_lock);

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