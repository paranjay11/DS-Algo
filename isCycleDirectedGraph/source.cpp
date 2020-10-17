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

class Graph{
public:
	int V,E;
	vector<int> *nodes;
	Graph(int V,int E);
	void addEdge(int source,int dest);
};

Graph::Graph(int V,int E){
	this->V=V;
	this->E=E;
	nodes=new vector<int>[V+1];
}

void Graph::addEdge(int source,int dest){
	nodes[source].push_back(dest);
}

bool isCycle(Graph *g,int i){
	bool *visited=new bool[g->V];
	stack<int> s;
	s.push(i);
	while(!s.empty()){
		int k=s.top();
		cout<<k<<endl;
		s.pop();
		if(!visited[k]){
			visited[k]=true;
			for(int j=0;j<g->nodes[k].size();j++){
				s.push(g->nodes[k][j]);
			}
		}
		else {
			cout<<"yes a cycle is present in the graph at k = "<<k<<endl;
			return true;
		}
	}

	return false;
}


// this code works fine in ideone.com but here it crahses I dont know why.
int main(){
	Graph *g;
	g=new Graph(8,9);
	g->addEdge(1,2);
	g->addEdge(1,4);
	g->addEdge(2,4);

	g->addEdge(2,3);
	g->addEdge(3,7);
	g->addEdge(4,5);

	g->addEdge(8,5);
	g->addEdge(5,6);
	g->addEdge(6,8);

	for(int i=0;i<9;i++){
		bool val=isCycle(g,i);
		if(val){
			cout<<"is cycle from i= "<<i<<endl;
			// break;
		}
		else {
			cout<<"not present in i= "<<i<<endl;
		}
	}
	
	return 0;
}
