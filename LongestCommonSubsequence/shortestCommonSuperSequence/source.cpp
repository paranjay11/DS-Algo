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

int LCS(string a,string b,int lenA,int lenB){
	int **dp;

	dp=new int*[lenA+1];

	// the subsequence between 2 strings in which one of them is a 0 lenght string is 0.
	// hence the initializzation for i==0 || j==0 is 0

	for(int i=0;i<lenA+1;i++){
		dp[i]=new int[lenB+1];
		for(int j=0;j<lenB+1;j++){
			// dp[i][j]=-1;
			// if(i==0 || j==0){
				dp[i][j]=0;
			// }
		}
	}

	for(int i=1;i<lenA+1;i++){
		for(int j=1;j<lenB+1;j++){
			if(a[i-1]==b[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}

	return dp[lenA][lenB];


}


int superSubSequence(string a,string b,int lenA,int lenB){
	int k;
	k=LCS(a,b,lenA,lenB);
	// cout<<k<<endl;

	return lenA+lenB-k;
}



int32_t main(){
	c_p_c();

	string a,b;


	getline(cin,a);
	getline(cin,b);

	
	cout<<superSubSequence(a,b,a.length(),b.length());


	return 0;
}