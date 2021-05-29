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

class ICommand{
public:
	virtual void execute()=0;
	virtual void unexecute()=0;
	virtual ~ICommand(){}
};


class Invoker1{ //  INvoker for light
private:
	ICommand *light1;
	ICommand *light2;

public:
	Invoker1(ICommand *light1,ICommand *light2){
		this->light1=light1;
		this->light2=light2;
	}

	void onButton(int val){
		if(val==1)
			light1->execute();
		else
			light2->execute();
	}

	void offButton(int val){
		if(val==1)
			light1->unexecute();
		else
			light2->unexecute();
		
	}
};

// class Invoker2{ // Invoker for dogdoor
// private:
// 	ICommand *doorFlap;

// public:
// 	Invoker2(ICommand *doorFlap){
// 		this->doorFlap=doorFlap;
// 	}

// 	void openDoor(){ // mapped to button openDoor
// 		this->doorFlap->execute();
// 	}

// 	void closeDoor(){ // mapped to button closeDoor
// 		this->doorFlap->unexecute();
// 	}
// };

class Light{
public:
	void switchedOn(){
		cout<<"light switched on\n";
	}

	void switchedOff(){
		cout<<"light switched off\n";
	}
};


class LightCommands:public ICommand{
public:
	Light *light;
	LightCommands(Light *ob): light(ob){}
	void execute(){
		light->switchedOn();
	}
	void unexecute(){
		light->switchedOff();
	}
};



int32_t main(){
	c_p_c();

	Light *l1=new Light();
	Light *l2=new Light();

	Invoker1 *lightRemoteController=new Invoker1(new LightCommands(l1),new LightCommands(l2));

	//  when we press the button on the remote controller for light2
	//  for switching it on or off respective call happens
	lightRemoteController->onButton(2);
	lightRemoteController->offButton(2);

	return 0;
}
