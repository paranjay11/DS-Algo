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

class flyBehavior{
public:
	virtual void fly()=0;
	// virtual functions need to be intialized in the base class
	// either we make them pure virtual or
	// we define them in bas class only
	// if not done it throws undefined reference to vtable
};

class straightFlyBehaviour:public flyBehavior{
public:
	void fly(){
		cout<<"I am flying straight\n";
	}
};

class upDownFlyBehaviour:public flyBehavior{
public:
	void fly(){
		cout<<"I am flying Up and down\n";
	}
};

class walkBehaviour{
public:
	virtual void walk()=0;
};

class straightWalkBehaviour:public walkBehaviour{
public:
	void walk(){
		cout<<"straight walking \n";
	}
};

class jayWalkBehaviour:public walkBehaviour{
public:
	void walk(){
		cout<<"Jay walking \n";
	}
};

class Duck{
private:
	flyBehavior *flyB;
	walkBehaviour *walkB;
public:
	Duck(flyBehavior *a,walkBehaviour *b){
		this->flyB=a;
		this->walkB=b;
	} 

	void flyStyle(){
		flyB->fly();
	}

	void walkStyle(){
		walkB->walk();
	}

};


int32_t main(){
	c_p_c();

	straightFlyBehaviour f1;
	jayWalkBehaviour j1;

	// flyBehavior *f1=new straightFlyBehaviour();
	// walkBehaviour *j1=new jayWalkBehaviour();

	Duck d1(&f1,&j1);

	d1.flyStyle();
	d1.walkStyle();

	return 0;
}