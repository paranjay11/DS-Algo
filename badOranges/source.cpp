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

class cell{
public:
	int i,j;
	int val;
	cell(int i,int j,int val){
		this->i=i;
		this->j=j;
		this->val=val;
	}
};

int daysToConvert(int *arr,int R,int C){
	queue<cell> q;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(arr[i*C+j]){
				q.push(cell(i,j,arr[i*C+j]));
			}
		}
	}

	int x[]={0,-1,0,1};
	int y[]={-1,0,1,0};
	int count=0;
	bool *visited=new bool[R*C];
	memset(visited,false,sizeof(bool)*R*C);

	while(!q.empty()){
		cell c=q.front();
		visited[c.i*C+c.j]=true;
		if(count<c.val) count=c.val;
		q.pop();

		for(int kk=0;kk<4;kk++){
			int X=c.i+x[kk];
			int Y=c.j+y[kk];
			if(X>=0 && X<R && Y>=0 && Y<C){
				if(!visited[X*C+Y]){
					int valNew=c.val+1;
					q.push(cell(X,Y,valNew));
				}
			}
		}
	}
	return count;
}

int32_t main(){
	c_p_c();
	int *arr;
	int R,C;
	
	cin>>R>>C;
	arr=new int[R*C];
	for(int i=0;i<R*C;i++){
		cin>>arr[i];
	}

	// for(int i=0;i<R;i++){
	// 	for(int j=0;j<C;j++){
	// 		cout<<arr[i*C+j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }

	cout<<daysToConvert(arr,R,C);

	return 0;
}