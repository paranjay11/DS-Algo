#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <map>
#include <string>
#include <chrono>

using namespace std;

map<string, int> teleBook{
	{"Scott",1988},
	{"Paranjay",1993},
	{"Aaryaman",1993}
};

shared_mutex teleBookMutex;

// here we will use a lock_guard since we only need a single writer thread to enter in the critical section
void writeInTeleBook(const string str, int val) {
	lock_guard<shared_mutex> writeLock(teleBookMutex);
	cout << "Wriet mutex owned by the thread : " << this_thread::get_id() << "\n";
	this_thread::sleep_for(chrono::milliseconds(500));
	teleBook[str] = val;
	cout << "The value is written in the teleBook\n";
}

// shared mutex is used for multiple reader threads to enter the critical area at the same time
// since associative container like a map can insert a new entry on querying and give us a wrong output
// We need to check if a string is avaialble in the map before we simple query it
void printYearOfBirth(string str) {
	shared_lock<shared_mutex> readLock(teleBookMutex);
	if (teleBook.find(str) != teleBook.end()) {
		cout << "The year of birth of " << str << " is : " << teleBook[str] << " \n";
	}
	else {
		cout << "Name of the person not found\n";
	}
}

int main() {
	thread reader1([] {printYearOfBirth("Rishab"); });
	thread reader2([] {printYearOfBirth("Paranjay"); });
	thread writer3([] {writeInTeleBook("Rishab", 1992); });
	thread reader3([] {printYearOfBirth("Neetesh"); });
	thread reader4([] {printYearOfBirth("Scott"); });
	thread reader5([] {printYearOfBirth("Kumar"); });
	thread writer1([] {writeInTeleBook("Neetsh", 1994); });
	thread reader6([] {printYearOfBirth("Neetesh"); });
	thread reader7([] {printYearOfBirth("Aaryaman"); });
	thread reader8([] {printYearOfBirth("Rishab"); });
	thread writer2([] {writeInTeleBook("Rick", 1995); });
	thread reader9([] {printYearOfBirth("Rick"); });

	reader1.join();
	reader2.join();
	reader3.join();
	reader4.join();
	reader5.join();
	reader6.join();
	reader7.join();
	reader8.join();
	reader9.join();
	writer1.join();
	writer3.join();
	writer2.join();

	return 0;
	
}