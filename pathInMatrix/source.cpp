#include <bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/path-in-matrix/0
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

// struct Node{
// 	int i;
// 	int j;
// };

int sum_max;
int arr[100][100];



int x[]={1,1,1};
int y[]={-1,0,1};


int32_t main(){
	c_p_c();
	w(T){
		int n;
		cin>>n;
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>arr[i][j];
			}
		}

		for(int i=n-2;i>=0;i--){
			for(int j=n-1;j>=0;j--){
				int val2=arr[i][j];
				for(int m=0;m<3;m++){
					int X=i+x[m];
					int Y=j+y[m];

					if(X>=0 && X<n && Y>=0 && Y<n){
						int val=arr[X][Y];
						
						arr[i][j]=max(arr[i][j],val2+val);
					}
				}
			}
		}

		sum_max=-1;
		for(int i=0;i<n;i++){
			// for(int j=0;j<n;j++){
			// 	//DFS(0,i,j);
			// }
			sum_max=max(sum_max,arr[0][i]);

		}
		cout<<sum_max;
	}
	return 0;
}