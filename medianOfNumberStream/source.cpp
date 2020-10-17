#include <bits/stdc++.h>
using namespace std;

#define w(x) 			int x; cin>>x; while(x--)
#define mk(arr,n,type)  type *arr=new type[n];
#define vii 			vector<int>
#define ll 				long long
#define mii 			map<int,int>
#define pb 				push_back
#define pq				priority_queue
#define ff 				first
#define ss 				second
#define pii 			pair<int,int>
#define inf 			1e18
void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

double medianVal(int *arr,int len){
	pq<double> s;
	pq<double,vector<double>,greater<int>> g;

	double mid=arr[0];
	s.push(arr[0]);

	for(int i=1;i<len;i++){
		double x=arr[i];
		if(s.size() > g.size()){
			if(mid > x){
				g.push(s.top());
				s.pop();
				s.push(x);
			}
			else{
				g.push(x);
			}
			mid=(s.top()+g.top())/2.0;
		}
		else if(s.size()==g.size()){
			if(mid > x){
				s.push(x);
				mid=s.top();
			}
			else{
				g.push(x);
				mid=g.top();
			}
		}
		else{
			if(mid < x){
				s.push(g.top());
				g.pop();
				g.push(x);
			}
			else{
				g.push(x);
			}
			mid=(s.top()+g.top())/2.0;
		}
	}
	return mid; 
}


int32_t main(){
	c_p_c();
	int n;
	cin>>n;
	mk(arr,n,int);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<medianVal(arr,n);

	return 0;
}