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

int minVertex(int *arr,bool *visited,int len){
		int minVal=INT_MAX;
		int index=0;
		//for(int k=0;k<len;k++) cout<<arr[k]<<" ";

		//cout<<endl;
	for(int i=0;i<len;i++){
		if(minVal>arr[i] && !visited[i]){
			minVal=arr[i];
			//cout<<"INside minVertex:"<<minVal<<endl;
			index=i;
		}
	}
	return index;
}

int *primm(int **graph,int V){
	int *parent=new int[V];// this will be used to save parent of every vertex from the graph which has the lowest weight
	bool *visited=new bool[V];
	memset(visited,false,sizeof(bool)*V);
	int *weight=new int[V];
	for(int i=0;i<V;i++){
		weight[i]=INT_MAX;
	}
	weight[0]=0;
	parent[0]=-1;
	//memset(weight,,sizeof(bool)*V); // thiswont work because we cannot set the vallue of arr anything other than 0 or -1
// for(int k=0;k<V;k++) cout<<weight[k]<<" ";
// 	weight[0]=0;


	for(int i=0;i<V;i++){

		int u=minVertex(weight,visited,V);
		//cout<<u<<" +++++++++++"<<endl;
		visited[u]=true;

		for(int j=0;j<V;j++){
			
			if(graph[u][j] && !visited[j] && weight[j]>graph[u][j]){
				parent[j]=u;
				//cout<<j<<" -> "<<parent[j]<<" , weight before change: "<<weight[j]<<endl;
				weight[j]=graph[u][j];
				//cout<<j<<" -> "<<parent[j]<<" , weight after change: "<<weight[j]<<endl;
			}
		}
	}
return parent;

}


int32_t main(){
	c_p_c();
	// int graph[9][9]={
	// 	0,4,0,0,0,0,0,8,0,
	// 	4,0,8,0,0,0,0,11,0,
	// 	0,8,0,7,0,4,0,0,2,
	// 	0,0,7,0,9,14,0,0,0,
	// 	0,0,0,9,0,10,0,0,0,
	// 	0,0,4,14,0,0,2,0,0,
	// 	0,0,0,10,0,2,0,1,6,
	// 	8,11,0,0,0,0,1,0,7,
	// 	0,2,0,0,0,0,6,7,0
	// };

	int **graph;
	int V;
	cin>>V;
	graph=new int*[V];
	for(int i=0;i<V;i++){
		graph[i]=new int[V];
		for(int j=0;j<V;j++){
			cin>>graph[i][j];
		}
	}
	//cout<<graph[3][5];
	int *res=primm(graph,V);

	// for(int i=0;i<V;i++){
	// 	for(int j=0;j<V;j++){
	// 		cout<<graph[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// if(res!=NULL) cout<<"its not null";
	cout<<"-----------------"<<endl;
	for(int i=0;i<V;i++){
		cout<<i<<" -> "<<res[i]<<" , weight : "<<graph[i][res[i]]<<endl;
	}
	// for(int i=0;i<9-1;i++){
	// 	cout<<i<<" -> "<<res[i]<<" : "<<graph[i][res[i]]<<endl;
	// }

	return 0;
}