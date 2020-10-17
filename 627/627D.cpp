#include <bits/stdc++.h>
using namespace std;

#define w(x) 			int x; cin>>x; while(x--)
#define mk(arr,n,type)  type *arr=new type[n];
#define vii 			vector<int>
#define ll 				long long
#define mii 			map<int,int>
#define pb 				push_back
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
	mk(arr,9,int);
	for (int i = 0; i < 9; ++i)
	{
		cin>>arr[i];
	}

	auto it=lower_bound(arr+10,arr+100,900);
	cout<<it-arr;

	// int n;
	// cin>>n;
	// mk(a,n,int);
	// mk(b,n,int);

	// for(int i=0;i<n;i++){
	// 	cin>>a[i];
	// }

	// for(int i=0;i<n;i++){
	// 	cin>>b[i];
	// }

	// mk(c,n,int);
	// for(int i=0;i<n;i++){
	// 	c[i]=b[i]-a[i];
	// }

	// sort(c,c+n);
	// for (int i = 0; i < 5; ++i)
	// {
	// 	cout<<c[i];
	// }
	// cout<<"\n";
	// int sum=0;	
	// for(int i=0;i<n;i++){
	// 	// have to find cj<-ci
	// 	// so we get cj>=ci becasue there can be many same c[i] hence we need to fing 
	// 	//the one value befpre the number greater than -ci
	// 	// the values in a sorted array will have -ve and +ve values 
	// 	// since for any ci we will have all the values less than this 
	// 	//already a possibility but something greater than this till the value that is just before greater than -c1 is what we need
	// 	auto it=lower_bound(c+i+1,c+n,-c[i]);
	// 	int id=it-c;
	// 	cout<<id<<"\t"<<id-(i+1)<<"\n";
	// 	sum+=id-(i+1);

	// }
	// cout<<sum<<"\n";

	return 0;;
}