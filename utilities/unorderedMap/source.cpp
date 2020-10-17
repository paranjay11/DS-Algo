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

//https://www.geeksforgeeks.org/overlapping-sum-two-array/?ref=rp
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
	int n;
	cin>>n;
	mk(arr1,n,int);
	mk(arr2,n,int);
	for(int i=0;i<n;i++){
		cin>>arr1[i];
	}
	for(int i=0;i<n;i++){
		cin>>arr2[i];
	}

	unordered_map<int,int> hash;
	for(int i=0;i<n;i++){
		hash[arr1[i]]++;
		hash[arr2[i]]++;
	}
	int sum=0;
	for(auto x:hash){
		if(x.second==1)
			sum+=a.first;	
	}
	cout<<sum;
	return 0;
}