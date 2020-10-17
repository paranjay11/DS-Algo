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

void nextPermutation(int *arr,int len){
	if(len ==0 || arr==NULL) return;

	priority_queue<int,vector<int>,greater<int>> q;
	int i=len-2;
	q.push(arr[len-1]);
	while(i>=0){
		if(arr[i]<arr[i+1]){
			break;
		}
		q.push(arr[i--]);
	}

	int k=q.top();
	//cout<<k<<endl;
	q.pop();
	q.push(arr[i]);
	arr[i]=k;
	for( i=i+1;i<len;i++){
		arr[i]=q.top();
		q.pop();
	}
}

int32_t main(){
	c_p_c();
	int arr[]={2,1,8,7,6,5};
	for(auto k:arr){
		cout<<k<<" ";
	}
	cout<<endl;
	cout<<"+++++++++++++++++"<<endl;
	nextPermutation(arr,6);
	for(auto k:arr){
		cout<<k<<" ";
	}
	return 0;
}