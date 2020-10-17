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


int lowestPowerOf2(int n){
	int x=0;
	while((1<<x) <=n){
		x++;
	}
	return x-1;
}

int solution(int n){
	if(n==0) return 0;
	int x= lowestPowerOf2(n);
	int bits1to2x = x * (1<<(x-1));
	int diffNto2x = n-(1<<x)+1;
	int remaining = n - (1<<x);

	return bits1to2x + diffNto2x + solution(remaining);
}


int32_t main(){
	// c_p_c();
	cout<<solution(35);
	return 0;
}