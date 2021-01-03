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
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	string str="";
	int i=lenA,j=lenB;
	while(i>0 && j>0){
		if(a[i-1]==b[j-1]){
			str+=a[i-1];
			i--,j--;
		}
		else{
			if(dp[i-1][j]>dp[i][j-1]){
				i--;
			}
			else{
				j--;
			}
		}
	}

	int len=str.length();
	int k=len-1;
	i=0;
	char m;
	while(i<k){
		m=str[i];
		str[i]=str[k];
		str[k]=m;
		i++;
		k--;
	}

	return str;

}

int32_t main(){
	c_p_c();

	string a,b;
	getline(cin,a);
	getline(cin,b);

	string ans=printLCS(a,b,a.length(),b.length());

	cout<<ans<<endl;

	return 0;
}