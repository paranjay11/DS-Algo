#include <bits/stdc++.h>
using namespace std;
//https://www.geeksforgeeks.org/count-ways-reach-nth-stair/
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

// n is the target sum
// m the size of stair jumps allowed
ll int k[100];
ll int func(int n,int m){
	k[0]=1;
	k[1]=1;

	for(int i=2;i<=n;i++){
		k[i]=0;
		for(int j=1;j<=i && j<=m ;j++){
			k[i]+=k[i-j];
		}
	}
	return k[n];
}

int main() {
	//code
	c_p_c();
	int n;
	cin>>n;

	int m;
	cin>>m;

	cout<<func(n,m);
	return 0;
	
}
