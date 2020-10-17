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

class Edge{
	public:
	int source;
	int destination;
	int weight;
};

class Graph{
public:
	int V;
	int E;
	Edge *edge;

	Graph(int V,int E){
		this->V=V;
		this->E=E;
		edge=new Edge[E];
	}
	void addEdge(int s,int d,int w,int e);

};

void Graph::addEdge(int s,int d,int w ,int e){
	this->edge[e].source=s;
	this->edge[e].destination=d;
	this->edge[e].weight=w;
}

int find(int i,int *arr){
	if(arr[i]==-1)
		return i;
	return find(arr[i],arr);
}

void unionArr(int i,int j,int *arr){
	int x=find(i,arr);
	int y=find(j,arr);

	if(x!=y) 
		arr[x]=y;
}

bool isCycle(Graph &graph){
	int *arr=new int(graph.V);
	memset(arr,-1,sizeof(int)*graph.V);

	for(int i=0;i<graph.E;i++){
		int x=find(graph.edge[i].source,arr);
		int y=find(graph.edge[i].destination,arr);

		if(x==y) {
			return true;
		}

		unionArr(x,y, arr);
	}

	return false;
}

int32_t main(){
	c_p_c();
	int V,E;
	cin>>V>>E;

	Graph g(V,E);

	int s,d,w;
	for(int i=0;i<E;i++){
		cin>>s>>d>>w;
		g.addEdge(s,d,w,i);
	}

	cout<<isCycle(g);
	return 0;
}