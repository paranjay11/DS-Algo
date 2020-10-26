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

#define L 102
#define W 1002

bool dp[L][W];


// this is a problem which is based on knapsack problem
// here we dont have values array. But in terms of weight we have the array of integers
// we have to choose out of them if any subset emerges which is total to a sum
// so again we have a choice for each element in the array

bool func(int *arr,int len,int sum){
	for(int i=0;i<=len;i++){
		for(int j=0;j<=sum;j++){
			if(i==0){
				dp[i][j]=false;
			}
			if(j==0){
				dp[i][j]=true;
			}
			
		}
	}

	for(int i=1;i<=len;i++){
		for(int j=1;j<=sum;j++){
			if(arr[i-1]<=j){
				dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}

	return dp[len][sum];

}

int32_t main(){
	c_p_c();
	int arr[]={1,7,3,2,4};
	cout<<func(arr,5,11);

	return 0;
}