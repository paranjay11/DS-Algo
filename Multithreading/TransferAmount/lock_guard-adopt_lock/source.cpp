#include <bits/stdc++.h>
#include <mutex>
#include <thread>

using namespace std;

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


class BankAccount{
private:
	mutex m;
	int balance;
public:
	explicit BankAccount(int _balance): balance(_balance){}
	int getBalance(){return balance;}
	friend void transfer(BankAccount *b1,BankAccount *b2,int amount);
};

void transfer(BankAccount *b1,BankAccount *b2,int amount){
	lock(b1->m,b2->m);
	// std::lock_guard with std::adopt_lock strategy assumes the mutex is already acquired.
	lock_guard<mutex> guard1(b1->m,adopt_lock);
	lock_guard<mutex> guard2(b2->m,adopt_lock);

	b1->balance = b1->balance - amount;
	b2->balance = b2->balance + amount;
}


int32_t main(){
	c_p_c();

	BankAccount b1(500);
	BankAccount b2(400);

	cout<<"Bank balance of b1 before : "<<b1->balance<<endl;
	cout<<"Bank balance of b2 before : "<<b2->balance<<endl;

	thread t1(transfer,&b1,&b2,50);
	thread t2(transfer,&b2,&b1,33);

	if(t1.joinable()) t1.join();
	if(t2.joinable()) t2.join();

	cout<<"Bank balance of b1 after : "<<b1->balance<<endl;
	cout<<"Bank balance of b2 after : "<<b2->balance<<endl;	

	return 0;
}