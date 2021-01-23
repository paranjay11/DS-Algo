/*

A person starts from 1,1 and has to reach X,Y on a grid
There are only two ways a person can move
 (x,x+y) or (x+y,y) , if that person is on (x,y)

 We have to tell if that person can reach X,Y when that person starts from 1,1

 Input:
 1st line -> number of test cases
 Following the number of lines equal to the number of test cases are 2 spaced integers speciafying 
 destination X,Y

 example:
 3
 2 3  // true
 1 4  // true
 4 4  // false


*/



#include <bits/stdc++.h>
using namespace std;

struct Coords{
	int x;
	int y;
};


bool isPossible(int x,int y){

	// if(x==1 && y==1) return true;

	queue<Coords *> q;
	Coords *temp=new Coords();
	temp->x=1;
	temp->y=1;



	q.push(temp);

	while(!q.empty()){
		temp=q.front();
		q.pop();

		if(temp->x==x && temp->y==y){
			return true;
		}

		int opt1x=temp->x;
		int opt1y=temp->y+temp->x;

		int opt2x=temp->x+temp->y;
		int opt2y=temp->y;

		// cout<<"current : x="<<temp->x<<" , y="<<temp->y<<endl;
		// cout<<"opt1 : x="<<opt1x<<" , y="<<opt1y<<endl;
		// cout<<"opt2 : x="<<opt2x<<" , y="<<opt2y<<endl;

		// if((opt1x==x && opt1y==y) || (opt2x==x && opt2y==y)){
		// 	return true;
		// }

		if(opt1x<=x && opt1y<=y){
			Coords *opt1=new Coords();
			opt1->x=opt1x;
			opt1->y=opt1y;
			q.push(opt1);
		}

		if(opt2x<=x && opt2y<=y){
			Coords *opt2=new Coords();
			opt2->x=opt2x;
			opt2->y=opt2y;
			q.push(opt2);
		}
	}

	return false;
}

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


int32_t main(){
	c_p_c();

	cout<<isPossible(4,4);
	return 0;
}