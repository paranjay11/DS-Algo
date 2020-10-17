#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/longest-common-substring-dp-29/

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

int subString(string A,string B){
	int lenA=A.length();
	int lenB=B.length();


	int arr[lenA+1][lenB+1];

	for(int i=0;i<lenB;i++){
		arr[0][i]=0;
	}

	for(int j=0;j<lenA;j++){
		arr[j][0]=0;
	}

	int res=0;

	for(int i=1;i<=lenA;i++){
		for(int j=1;j<=lenB;j++){
			if(A[i-1]==B[j-1]){
				arr[i][j]=arr[i-1][j-1]+1;
				res=max(res,arr[i][j]);
			}
			else
				arr[i][j]=0;
		}
	}

	return res;
}



int32_t main(){
	c_p_c();
	string a="GeeksForGeeks";
	string b="GeeksQuiz";

	cout<<subString(a,b);

	return 0;
}