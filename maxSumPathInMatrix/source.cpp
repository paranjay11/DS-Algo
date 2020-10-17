#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/maximum-sum-path-in-a-matrix/

#define w(x) 			int x; cin>>x; while(x--)
#define mk(arr,n,type)  type *arr=new type[n];
#define vii 			vector<int>
#define ll 				long long
#define mii 			map<int,int>
#define pb 				push_back
#define pq				priority_queue
#define ff 				first
#define ss 				second
#define pii 			pair<int,int>
#define inf 			1e18
void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


int dist(int **arr,int i,int j,vector<vector<bool>> &visited,vector<vector<int>> &dp,int size){

	if(i==size-1 && j==size-1){ // if the end point has been reached then return the value at the end point
		return arr[size-1][size-1]; 
	}

	if(visited[i][j]==true){// if the cell is visited before then return dp value at that i,j
		return dp[i][j];
	}

	visited[i][j]=true;

	int &temp = dp[i][j];// this way we will automatically update the values in temp to its reference pointed dp[i][j]

	if(i<size-1 && j<size-1){ // if it is somewhere in the middle 
		int current_sum = max(dist(arr,i+1,j,visited,dp,size),
							  max(dist(arr,i,j+1,visited,dp,size),
							  	  dist(arr,i+1,j+1,visited,dp,size)));
		temp = current_sum;
	}
	else if(i==size-1){
		temp = dist(arr,i,j+1,visited,dp,size);
	}
	else{
		temp = dist(arr,i+1,j,visited,dp,size);
	}

	temp+=arr[i][j];

	return temp;


}


int32_t main(){
	c_p_c();

	int size;
	cin>>size;
	int **arr=new int*[size];
	for(int i=0;i<size;i++){
		arr[i]=new int[size];
		for(int j=0;j<size;j++){
			cin>>arr[i][j];
		}
	}

	vector<vector<int>> dp(size,vector<int>(size,0));
	vector<vector<bool>> visited(size,vector<bool>(size,0));

	cout<<dist(arr,0,0,visited,dp,size);

	// for(int i=0;i<size;i++){
	// 	for(int j=0;j<size;j++){
	// 		cout<<arr[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	return 0;
}