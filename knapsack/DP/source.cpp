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

int dp[L][W];

int func(int *weights,int *values,int len,int weight){
	// The base condition in recursion gets converted in dp matrix initialization 
	for(int i=0;i<=len;i++){
		for(int j=0;j<=weight;j++){
			if(i==0||j==0){
				dp[i][j]=0;
			}
		}
	}
	

	// recursion part is converted to iterative code

	// now convert the len->i and weight->j
	// in matrix rows denote the length of the items array 
	// matrix column denotes the weight of the knapsack
	// since we start i=1 & j=1 in values[i-1](line:39), denotes the correct index in values array
	// same for weights array 
	for(int i=1;i<=len;i++){
		for(int j=1;j<=weight;j++){
			if(weights[i-1]<=j){ // when it is eligible to be kept in knapsack
				dp[i][j]=max(values[i-1]+dp[i-1][j-weights[i-1]],
								dp[i-1][j]);
			}
			else{// not keeping in knapsack
				dp[i][j]=dp[i-1][j];
			}
		}
	}

	return dp[len][weight];
}


int32_t main(){
	c_p_c();
	int weights[]={10,10,3,4,2};
	int values[]={5,50,26,25,2};
	int weight=10;
	cout<<func(weights,values,5,weight);
	return 0;
}