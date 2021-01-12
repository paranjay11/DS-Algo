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

// the argument is a string and to find a palindrome we can use the reverse of the argument and then use it 
// to find a LCS among the two strings. The LCS will be the longest palindrome in the string
string palindrome(string a){
	int **dp;
	int len=a.length();
	dp=new int*[len+1];
	int pp=len-1;
	string b="";
	while(pp>=0){
		b+=a[pp];
		pp--;
	}
	// cout<<a<<"      "<<b<<endl;
	for(int i=0;i<len+1;i++)
	{
		dp[i]=new int[len+1];
		for(int j=0;j<len+1;j++){
			dp[i][j]=-1;
			if(i==0||j==0){
				dp[i][j]=0;
			}
		}
	}

	for(int i=1;i<len+1;i++){
		for(int j=1;j<len+1;j++){
			if(a[i-1]==b[i-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}


	// cout<<dp[len][len]<<"       <<<<<<<<<< longest palindrome"<<endl;
	string ans="";
	int i=len,j=len;
	int oct=1;
	while(i>0 && j>0){
		if(a[i-1]==b[j-1]){
			ans+=a[i-1];
			// cout<<"dp[i][j] = "<<dp[i][j]<<" , count "<<oct++<<"   "<<ans<<endl;
			i--,j--;
		}
		else{

		
			if( dp[i-1][j] >= dp[i][j-1])
				i--;
			else
				j--;
			
		}
		
	}

	return ans;

}


int32_t main(){
	c_p_c();

	string str;
	getline(cin,str);

	cout<<palindrome(str);

	return 0;
}