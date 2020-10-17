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


int32_t main(){
		c_p_c();

		int a;
		cin>>a;
		string s;
		getline(cin,s);// takes in the space or the next line after the number. 
		getline(cin,s);// to take in the input as a string


		cout<<a<<endl;
		cout<<s;

		cout<<endl;
		cout<<endl;
		// if we want to separate the words in the string
		string k;
		stringstream myStr(s);
		while(myStr>>k){
			cout<<k<<endl;
		}
		return 0;
}	