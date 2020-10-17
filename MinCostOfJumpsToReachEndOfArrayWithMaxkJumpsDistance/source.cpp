#include <bits/stdc++.h>
using namespace std;

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
void printVector(vector<int> &s){
	for(int i=0;i<s.size();i++){
		cout<<s[i]<<"\t";
	}
	cout<<endl;
}

int32_t main(){
	c_p_c();
	int k;// max jumps
	cin>>k;
	int num;//number of elements
	cin>>num;
	vector<int> arr;
	int temp;
	for(int i=0;i<num;i++){
		cin>>temp;
		arr.push_back(temp);
	}

	//printVector(arr);
	//cout<<k<<endl;
	vector<int> dp(arr.size(),INT_MAX);
	dp[0]=0;
	for(int i=0;i<arr.size();i++){
		for(int j=i+1;j<=i+k && j<arr.size() ;j++){
			dp[j]=min(dp[j],abs(arr[i]-arr[j])+dp[i]);
		}
	}


// this apporach was from the back of the array but i wasnt using a dp array along with it
	// i wasusing only one value whcih was the minimum among the 3 comparioson but then I was also skipping directly to the 
	// node which had that minimum value

	// I had to iterate through whole array for it and store the minimum at every node till the end from the starting 
																							// start from the end
																								 

	// int i=arr.size()-1;
	// int count=0;
	// int mini;
	// int pos=i;
	// int sum=0;
	// while(i>0){
	// 	mini=INT_MAX;
	// 	count=1;
	// 	while(count<=k && i-count>=0){
	// 		cout<<"count: "<<count<<" "<<"i: "<<i<<endl;
	// 		if(abs(arr[i]-arr[i-count])<mini){
	// 			mini=abs(arr[i]-arr[i-count]);
	// 			pos=i-count;
	// 		}
	// 		count++;
	// 	}
	// 	cout<<"pos: "<<pos<<"\t";
	// 	i=pos;
	// 	cout<<"min: "<<mini<<endl;
	// 	sum+=mini;
	// }

	
	//sum+=mini;

	// cout<<sum;
	cout<<dp[arr.size()-1];

	return 0;
}