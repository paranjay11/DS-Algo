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


int LCSubstring(string a,string b,int lenA,int lenB){
	int max=-1;
	int **dp;
	dp=new int*[lenA+1];
	for(int i=0;i<lenA+1;i++){
		dp[i]=new int[lenB+1];
		for(int j=0;j<lenB+1;j++){
			dp[i][j]=-1;
			if(i==0||j==0){
				dp[i][j]=0;
			}
		}
	}

	for(int i=1;i<lenA+1;i++){
		for(int j=1;j<lenB+1;j++){
			if(a[i-1]==b[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
				if(dp[i][j]>=max){
					max=dp[i][j];
				} 
			}
			else{
				dp[i][j]=0;
			}
		}
	}

	return max;

}


int32_t main(){
	c_p_c();

	string strA;
	getline(cin,strA);
	string strB;
	getline(cin,strB);

	cout<<strB<<endl;
	cout<<strA<<endl;

	cout<<LCSubstring(strA,strB,strA.length(),strB.length());

	return 0;
}