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

int targetSum(int *arr,int len,int val){
	int sum=0;
	for(int i=0;i<len;i++){
		sum+=arr[i];
	}

	int k=(sum+val)/2;

	int **dp;

	dp=new int*[len+1];

	for(int i=0;i<=len;i++){
		dp[i]=new int[sum+1];
		for(int j=0;j<sum+1;j++){
			if(i==0) dp[i][j]=0;
			if(j==0) dp[i][j]=1;
		}
	}


	for(int i=1;i<=len;i++){
		for(int j=1;j<=k;j++){
			if(arr[i-1]<=j){
				dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
			}
			else
				dp[i][j]=dp[i-1][j];
		}
	}

	return dp[len][k];
}

int32_t main(){
	c_p_c();
	int arr[]={1,1,2,3};
	int ans = targetSum(arr,4,1);
	cout<<ans;
	return 0;
}