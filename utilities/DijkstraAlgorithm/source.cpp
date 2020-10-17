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

int minArr(int *arr,bool *visited,int V){
	int index,minVal=INT_MAX;
	for(int i=0;i<V;i++){
		if(visited[i]==false && arr[i]<minVal){
			minVal=arr[i];
			index=i;
		}
	}
	return index;
}

class coord{
public:
	int i;
	int dist;
	coord(int i,int dist): i(i),dist(dist){}
};


bool operator<(const coord &a, const coord &b){
	return a.dist<b.dist;
}



void printArr(int *arr,int V){
	for(int i=0;i<V;i++){
		cout<<i<<" -> "<<arr[i]<<endl;
	}
}


void dijkstra(int **graph,int V,int source=1,int destination=6){
	int *parent=new int[V];// this is used to store the parent of each node and since source is going to the parent of some node
						   // as we start from it, hence  we can trace our destination to the source always
	// int *dist=new int[V];// this is used for storing parents of each vertex ... but in dijkstra it is a dist array from the origin
	set<*coord> dist;
	bool *visited=new bool[V]; // if it has been visited i.e. that vertex 
	//int *key=new int[V];// this is key walue pair for updating the distance value 
	// we wont be needing the parent aray as in primm algorithm because there we were finding and storing a spaaning tree 
	// but here we are just updating the distance value from the origin and that can change.

	for(int i=0;i<V;i++){
		// dist[i]=INT_MAX;
		dist.insert(new)
		//key[i]=INT_MAX;
		visited[i]=false;
	}
	dist[source]=0;
	for(int i=0;i<V;i++){
		int u=minArr(dist,visited,V);

		visited[u]=true;

		for(int v=0;v<V;v++){
			if(!visited[v] && graph[u][v] && dist[u]!=INT_MAX && (dist[u]+graph[u][v])<dist[v] ){ 
			// here we need to insure that we are not taking dist[u] as INT_MAX because this makes it unable to add anything to it
			// simce if distance of  source to u is INT_MAX then it is obviosly not the optimal one , hence we cannot have dist[u] as INT_MAX
				dist[v]=dist[u]+graph[u][v];
				parent[v]=u;
			}
		}
	}
	printArr(dist,V);
	////////////////////////////////// - this part prints the path frmo source to destination with the help of parent array
	cout<<"\n";
	int i=destination;
	stack<int> arr;// using a stack as we will start tracing the source from destination
	arr.push(destination);
	while(parent[i]!=source){
		arr.push(parent[i]);
		i=parent[i];
	}
	arr.push(parent[i]);
	while(!arr.empty()){
		cout<<arr.top()<<"-> ";
		arr.pop();

	}
}

int32_t main(){
	c_p_c();
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
	dijkstra(graph,V);

	// for(int i=0;i<V;i++){
	// 	for(int j=0;j<V;j++){
	// 		cout<<graph[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// if(res!=NULL) cout<<"its not null";
	// cout<<"-----------------"<<endl;
	// for(int i=0;i<V;i++){
	// 	cout<<i<<" -> "<<res[i]<<" , weight : "<<graph[i][res[i]]<<endl;
	// }
	// for(int i=0;i<9-1;i++){
	// 	cout<<i<<" -> "<<res[i]<<" : "<<graph[i][res[i]]<<endl;
	// }

	return 0;

	
}