#include <bits/stdc++.h>
using namespace std;

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

template<class T>
class mySharedPointer{
private:
	T* m_ptr;
	int* m_count;
public:
	mySharedPointer(T* ptr=NULL){
		m_ptr=ptr;
		m_count=new int(0);
		if(ptr){
			(*m_count)++;
		}
	}

	int use_count(){
		return *m_count;
	}

	// copy constructor
	mySharedPointer(mySharedPointer<T> &val){
		m_ptr = val.m_ptr;
		m_count = val.m_count;
		(*m_count)++;
	}

	// mySharedPointer& operator=(mySharedPointer<T> &&A) = delete;

	~mySharedPointer(){
		(*m_count)--;
		if(*m_count<=0){
			delete m_ptr;
			delete m_count;
		}
	}

	T& operator*(){
		return *m_ptr;
	}

	T* operator->(){
		return m_ptr;
	}

	// move operator
	mySharedPointer& operator=(mySharedPointer &&a){
		if(&a==this){
			return *this;
		}

		delete m_ptr;
		delete m_count;

		m_ptr=a.m_ptr;
		a.m_ptr=NULL;

		m_count=a.m_count;
		a.m_count=NULL;

		return *this;
	}
};

class ABC{
public:
	void show(){
		cout<<"ABC:show()"<<endl;
	}
};


int32_t main(){
	c_p_c();

	mySharedPointer<ABC> chk(new ABC());
	chk->show();
	cout<<chk.use_count()<<endl;
	mySharedPointer<ABC> chk2(chk);
	chk2->show();
	cout<<chk.use_count()<<endl;
	chk.~mySharedPointer();
	cout<<chk2.use_count()<<endl;

	return 0;
}