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

int valOfRod(int *values,int *weights,int len,int weight){
	if(len==0||weight==0){
		return 0;
	}

	if(weights[len-1]<=weight){
		return max(values[len-1]+valOfRod(values,weights,len,weight-weights[len-1]),
					valOfRod(values,weights,len-1,weight));
	}
	else{
		return valOfRod(values,weights,len-1,weight);
	}
}

int valOfRodDP(int *values,int *weights,int len,int weight){
	int **dp;

	dp=new int*[len+1];

	for(int i=0;i<len+1;i++){
		dp[i]=new int[weight+1];
		for(int j=0;j<weight+1;j++){
			if(i==0) dp[i][j]=0;
			if(j==0) dp[i][j]=0;
		}
	}

	for(int i=1;i<len+1;i++){
		for(int j=1;j<weight+1;j++){
			if(weights[i-1]<=j){
				dp[i][j]=max(dp[i][j-weights[i-1]] + values[i-1],dp[i-1][j]);
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}

	return dp[len][weight];
}

int32_t main(){
	c_p_c();
	int weights[]={1,2,3,4,5,6};
	int values[]={1,4,3,10,11,2};

	cout<<valOfRodDP(values,weights,6,6);
	return 0;
}