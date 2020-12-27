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

int minCoinChange(int *values,int len,int val){
	int **dp;
	dp=new int*[len+1];

	for(int i=0;i<len+1;i++){
		dp[i] = new int[val+1];
		for(int j=0;j<val+1;j++){
			if(i==0 ) dp[i][j]=INT_MAX-1;// this is very important because if 
										//we have to add 1 to this then the int variable will overflow and it will be 
										//assigned -ve value and this ruins our logic for keeping it a largest value 
										//when the solution doestn exist
			if(j==0) dp[i][j]=0;
			// this code is for initializing it the i==1 row because IDK , ididnt find it necessary. It got explained in the video
			//https://www.youtube.com/watch?v=I-l6PBeERuc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=16&pbjreload=101
			// else dp[i][j]=INT_MAX;
			// if(i==1){
			// 	if(j%values[i]==0) dp[i][j]=j/values[i];
			// 	else dp[i][j]=INT_MAX-1;
			// }
		}
	}

	for(int i=1;i<len+1;i++){
		for(int j=1;j<val+1;j++){
			if(values[i-1]<=j){
				dp[i][j]=min(dp[i][j-values[i-1]]+1,dp[i-1][j]); // only when we select a coin we add a 1 or else we are just 
																//movinf on to another coin hence we do not add 1 to dp[i-1][j]
			}
			else{
				dp[i][j]=dp[i-1][j];// 1 not added to this because we are just moving to another coin denomination
			}
		}
	}


	return dp[len][val];

}

int func(int *values,int len,int val){
	if(len==0||val==0){
		return 0;
	}

	int a=INT_MAX-1;
	int b=INT_MAX-1;
	if(values[len-1]<=val){
		a=func(values,len,val-values[len-1])+1;
	}
	else{
		b=func(values,len-1,val);
	}

	return min(a,b);
}

int32_t main(){
	c_p_c();

	int values[]={5,6,7};
	// cout<<minCoinChange(values,3,5);
	cout<<minCoinChange(values,3,14);

	return 0;
}