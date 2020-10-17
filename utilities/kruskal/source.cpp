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

class Edge{
public:
	int source,destination,weight;
};

class Graph{
public:
	int V,E;
	Edge *edge;

	Graph(int V,int E){
		this->V=V;
		this->E=E;
		this->edge=new Edge[E];
	}

	void addEdge(int s,int d,int w,int e){
		this->edge[e].source=s;
		this->edge[e].destination=d;
		this->edge[e].weight=w;
	}

};

int findArr(int i,int *arr){
	if(arr[i]==-1)
		return i;
	else return findArr(arr[i],arr);
}

void unionArr(int i,int j,int *arr){
	int x=findArr(i,arr);
	int y=findArr(j,arr);

	if(x!=y){
		arr[x]=y;
	}
}

bool mycompare(Edge &a,Edge &b){
	return a.weight<b.weight;
}

Edge *Kruskal(Graph &graph){
	Edge *result=new Edge[graph.V];// because we know in a MST we will have edges = Vertices-1
	sort(graph.edge,graph.edge+graph.E,mycompare);

	int *arr=new int[graph.V];
	memset(arr,-1,sizeof(int)*graph.V);

	int count=0;

	for(int i=0;i<graph.E && count<graph.V-1;i++){
		int x=findArr(graph.edge[i].source,arr);
		int y=findArr(graph.edge[i].destination,arr);

		if(x!=y){
			result[count++]=graph.edge[i];
			unionArr(x,y,arr);
		}
	}
	return result;
}

void printEdge(Edge *arr,int len){
	for(int i=0;i<len;i++){
		cout<<arr[i].source<<"->"<<arr[i].destination<<" : "<<arr[i].weight<<endl;
	}
}
int32_t main(){
	c_p_c();
	int V,E;
	cin>>V>>E;

	Graph graph(V,E);
	int s,d,w;

	for(int i=0;i<E;i++){
		cin>>s>>d>>w;
		graph.addEdge(s,d,w,i);
	}
	//printEdge(graph.edge,graph.E);

	Edge *res=Kruskal(graph);

	printEdge(res,graph.V-1);


	return 0;
}