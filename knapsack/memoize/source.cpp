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
// the dp which we create is dependent on:
// since in a recursice call of a function there are changes in some arguments in the argument list
// in this example we see the changes in len & weight. So if we imagine a dp matrix we can see that 
// at a particular cell is represented by a specific function recursive call corresponding to a 
// particular value set of len and weight.
// hence the row or column of dp matrix will be of len & weight
int dp[L][W];

int func(int *weights,int *values,int len,int weight){
	if(weight<=0||len<=0){
		return 0;
	}

	if(dp[len][weight]!=-1){
		return dp[len][weight];
	}

	if(weights[len-1]<=weight){
		return dp[len][weight]=max(values[len-1]+func(weights,values,len-1,weight-weights[len-1]),func(weights,values,len-1,weight));
	}
	else{
		return dp[len][weight]=func(weights,values,len-1,weight);
	}
}

int32_t main(){
	c_p_c();
	memset(dp,-1,sizeof(dp));
	int weights[]={10,10,3,4,2};
	int values[]={5,50,26,25,2};
	int weight=10;
	cout<<func(weights,values,5,weight);

	return 0;
}