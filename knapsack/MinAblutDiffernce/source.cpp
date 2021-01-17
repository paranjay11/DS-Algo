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

bool isSumPresent(int *arr,int len,int sum){
	bool **dp;
	dp=new bool*[len+1];

	for(int i=0;i<len+1;i++){
		dp[i]=new bool[sum+1];
		for(int j=0;j<sum+1;j++){
			if(i==0){
				dp[i][j]=0;
			}
			if(j==0){
				dp[i][j]=1;
			}
		}
	}

	for(int i=1;i<=len;i++){
		for(int j=1;j<=sum;j++){
			if(arr[i-1]<=j)
				dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
			else
				dp[i][j]=dp[i-1][j];
		}
	}


	return dp[len][sum];
}


int minDiff(int *arr,int len){
	int sum=0;
	for(int i=0;i<len;i++){
		sum+=arr[i];
	}

	int t=sum/2;
	int ans=INT_MAX;
	for(int i=0;i<=t;i++){
		if(isSumPresent(arr,len,i)){
			cout<<"true for "<<i<<endl;
			ans=min(ans,sum-2*i);
		}
	}

	return ans;
}



int32_t main(){
	c_p_c();

	int arr[3]={1,2,7};
	cout<<minDiff(arr,3);
	return 0;
}