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
	int dest;
	int weight;
	Edge(int d,int w){
		this->dest=d;
		this->weight=w;
	}
};

class Graph{
public:
	int V;
	int E;

	multimap<int , Edge> edgeMap;

	Graph(int V,int E){
		this->V=V;
		this->E=E;
	}

	void addEdge(int s,int d,int w){
		pair<int,Edge> p = make_pair(s,Edge(d,w));
		this->edgeMap.insert(p);
		// Edge edge;

		// edge.dest=d;
		// edge.weight=w;
		// pair<int,Edge> p;
		// p=make_pair(s,edge);
		// this->edgeMap.insert(p);
		// this->edgeMap[s].dest=d;
		// this->edgeMap[s].weight=w;
	}
};
int find(int i,int *arr){
	if(arr[i]==-1){
		//cout<<"i : "<<i<<" ,if  arr[i] : "<<arr[i]<<endl;
		//cout<<"i: "<<i<<endl;
		return i;
	}
		
	//cout<<"i : "<<i<<" , else arr[i] : "<<arr[i]<<endl;
	return find(arr[i],arr);
}

void unionArr(int i,int j, int *arr){
	int x=find(i,arr);
	int y=find(j,arr);

	if(x!=y)
		arr[x]=y;
}

bool isCycle(Graph &graph){
	int *arr=new int[graph.V];
	memset(arr,-1,sizeof(int)*graph.V);

	multimap<int,Edge>::iterator it=graph.edgeMap.begin();
	for( ;it!=graph.edgeMap.end();it++){
		//cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		//cout<<"it->first: "<<it->first<<" , "<<"it->second.dest: "<<it->second.dest<<endl;
		int x=find(it->first,arr);
		//cout<<"x after find : "<<x<<endl;
		//cout<<"it->first: "<<it->first<<" "<<"x:"<<x<<endl;
		int y=find(it->second.dest,arr);
		//cout<<"y after find : "<<y<<endl;
		
		//cout<<"it->second.dest: "<<it->second.dest<<" "<<"y:"<<y<<endl;
		if(x==y) 
			return true;

		unionArr(x,y,arr);
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
		g.addEdge(s,d,w);
	}

	// multimap<int,Edge>::iterator it=g.edgeMap.begin();
	// for( ;it!=g.edgeMap.end();it++){
	// 	cout<<it->first<<" "
	// 		<<it->second.dest<<" "
	// 		<<it->second.weight<<endl;
	// }

	cout<<isCycle(g);
	return 0;
}