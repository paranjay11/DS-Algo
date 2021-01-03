#include <bits/stdc++.h>
using namespace std;


void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

string printLCS(string a,string b,int lenA,int lenB){
	int **dp;
	// for(int i=0;i<lenA+1;i++){


	dp=new int*[lenA+1];		
	for(int i=0;i<lenA+1;i++){
	dp[i]=new int[lenB+1];
		for(int j=0;j<lenB+1;j++){
			dp[i][j]=0;
		}
	}	

	string ans="";
	for(int i=1;i<lenA+1;i++){
		for(int j=1;j<lenB+1;j++){
			if(a[i-1]==b[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
				// ans+=a[i-1];
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}

	int i=lenA,j=lenB;
	// cout<<dp[lenA][lenB];
	while(i>0 && j>0){
		// cout<<"reached here >>>>"<<i<<" and "<<j<<endl;
		if(a[i-1]==b[j-1]){
			ans+=a[i-1];
			i--;
			j--;
		}
		else{
			if(dp[i-1][j]>dp[i][j-1]){
				ans+=a[i-1];
				i--;
			}
			else{
				ans+=b[j-1];
				j--;
			}
		}
	}

	// int lenAns=ans.length();
	i=0;
	j=ans.length()-1;

	char pp;
	while(i<j){
		pp=ans[j];
		ans[j]=ans[i];
		ans[i]=pp;
		i++;
		j--;
	}
	
	
	return ans;

}

int32_t main(){
	c_p_c();

	string a,b;
	getline(cin,a);
	getline(cin,b);

	cout<<printLCS(a,b,a.length(),b.length());


	return 0;
}