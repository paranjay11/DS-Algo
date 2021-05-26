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

class IObserver;

class IObservable{
public:
	vector<IObserver*> observers;
	virtual void addObserver(IObserver*) = 0;
	virtual void removeObserver(IObserver*) = 0;
	virtual void notify()=0;
};

class IObserver{

		
	public:
	// IObservable *toObserve;
	virtual void update()=0;
};

class WeatherStation:public IObservable{
public:
	void addObserver(IObserver *ob){
		observers.push_back(ob);
	}

	void removeObserver(IObserver *ob){
		for(int i=0;i<observers.size();i++){
			if(observers[i]==ob){
				observers.erase(observers.begin()+i);
				return;
			}
		}
	}

	void notify(){
		for(int i=0;i<observers.size();i++){
			observers[i]->update();
		}
	}

	int getTemprature(){
		return 45;
	}
};


class TVDisplay:public IObserver{
public:
	WeatherStation *ws;
	TVDisplay(WeatherStation *ob){
		this->ws=ob;
	}
	void update(){
		cout<<this->ws->getTemprature()<<endl;
	}

};



class MobileDisplay:public IObserver{
public:
	WeatherStation *ws;
	MobileDisplay(WeatherStation *ob){
		ws=ob;
	}
	void update(){
		cout<<ws->getTemprature()<<endl;
	}

};

int32_t main(){
	c_p_c();

	WeatherStation ws;
	MobileDisplay md(&ws);
	TVDisplay td(&ws);

	ws.addObserver(&md);
	ws.addObserver(&td);

	ws.notify();

	return 0;
}