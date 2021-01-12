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

int dp[1001][1001];

int mcm_dp(int *arr,int len,int i,int j){
	if(i>=j)
		return 0;

	if(dp[i][j]!=-1)
		return dp[i][j];

	int temp=0;
	int min_val=INT_MAX;

	for(int k=i;k<=j-1;k++){
		temp=mcm_dp(arr,len,i,k)+mcm_dp(arr,len,k+1,j)+arr[i-1]*arr[k]*arr[j];
		min_val=min(min_val,temp);
	}
	dp[i][j]=min_val;
	return dp[i][j];
}

int32_t main(){
	c_p_c();
	memset(dp,-1,sizeof(dp));
	int arr[]={40,20,30,10,30};
	cout<<mcm_dp(arr,5,1,4);
	return 0;
}