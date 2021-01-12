#include <bits/stdc++.h>
using namespace std;


int mcm(int *arr,int len,int i,int j){
	if(i>=j){
		return 0;
	}

	int temp=0;
	int min_val=INT_MAX;
	for(int k=i;k<=j-1;k++){
		temp=mcm(arr,len,i,k)+mcm(arr,len,k+1,j)+arr[i-1]*arr[k]*arr[j];
		min_val=min(temp,min_val);
	}

	return min_val;
}


void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


int32_t main(){
	c_p_c();

	int *arr;
	int len;
	cin>>len;
	arr=new int[len];
	for(int i=0;i<len;i++){
		cin>>arr[i];
	}

	cout<<mcm(arr,len,1,len-1);

	return 0;
}