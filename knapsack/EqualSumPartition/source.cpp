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

int func(int *arr,int len){

	// sum of all the elemets in the array
	int addVal=0;
	for(int i=0;i<len;i++){
		addVal+=arr[i];
	}


	// chec kif the sum is an odd value then it is not possible to break the array in two equal subsets
	if(addVal%2==1) return false;
	// cout<<"it passed the threashold"<<endl;

	// treat half of the sum of array elements as the sum in the problem SubsetSum
	int target=addVal/2;
	// cout<<target<<endl;

	bool **dp=new bool*[len+1];


	for(int i=0;i<=len;i++){
		dp[i]=new bool[target+1];
		for(int j=0;j<=target;j++){
			if(i==0) dp[i][j]=false;
			if(j==0) dp[i][j]=true;
		}
	}

	// we only need to search one subset in the array because the rest of the elements will automatically be the half 
	// of sum of elements
	for(int i=1;i<=len;i++){
		for(int j=1;j<=target;j++){
			if(arr[i-1]<=j){
				dp[i][j]=dp[i-1][j-arr[i-1]] | dp[i-1][j]; 
			}
			else
				dp[i][j]=dp[i-1][j];
		}
	}

	// there is a possibility that we may not find the elements {1,5,13,5}
	// but we can find it in {1,5,11,5}
	if(dp[len][target]==true) return true;
	else return false;
}


int32_t main(){
	c_p_c();

	int arr[]={1,5,11,5};
	cout<<func(arr,4);
	return 0;
}