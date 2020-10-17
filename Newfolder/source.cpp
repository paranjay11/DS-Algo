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



// class A{
// 	virtual void f11(){
// 		cout<<"hello from A"<<endl;
// 	}
// 	// public:
// 		virtual void f1(){
// 			cout<<"hello from A"<<endl;
// 		}
// };
// class B:private A{
// 	virtual void f2(){
// 		cout<<"Hello from B"<<endl;
// 	}
// };

// int main(){
// 	cout<<"sizeof A= "<<sizeof(A)<<endl;
// 	cout<<"sizeof B= "<<sizeof(B)<<endl;
// 	// int **a;
// 	// cout<<"size of **a = "<<sizeof(**a)<<endl;
// 	return 0;
// }
// class A{
// 	int a;
// 	bool b;
// 	public:
// 	virtual void f1(){
// 		cout<<"in Class A"<<endl;
// 	}
// };

// class B:public A{
// 	int a;
// public:
// 	void f1(){
// 		cout<<"in class B"<<endl;
// 	}
// 	virtual void f2(){// try removing virtual from here
// 		cout<<"hello"<<endl;
// 	}
// };

// class C:public B{
// public:
// 	void f2(){
// 		cout<<"hello from C"<<endl;
// 	}

// };

// int main() {
// 	cout<<"sizeof C ="<<sizeof(C)<<endl;
// 	cout<<"sizeof A ="<<sizeof(A)<<endl;
// 	cout<<"sizeof B ="<<sizeof(B)<<endl;

// 	// cout<<""
// 	A *ptr;
// 	B b;
// 	B *bc;
// 	C c;
// 	cout<<"size of ptr ="<<sizeof(ptr)<<endl;
// 	cout<<"size of ptr ="<<sizeof(*ptr)<<endl;
// 	cout<<"size of b = "<<sizeof(b)<<endl;
// 	bc=&c;
// 	ptr=&b;
// 	b.f2();
// 	bc->f2();
// 	ptr=&c;
// 	ptr->f1();
// 	bc->f1();
// 	// ptr->f1();
	
// 	// your code goes here
// 	return 0;
// }

// int repeatedNumber(const vector<int> &A) {
//     // // int maxVal=-1;
//     int len=A.size();
//     if(len==0) return -1;
//     int l=sqrt(len)+1;
//     int *arr=new int(l);
//     // arr[18]=0;
//     // memset(arr,0,sizeof(int)*l);
//     for(int i=0;i<l;i++){
//     	cout<<i<<endl;
//     	arr[i]=0;
//     }
//     int k=0;
//     // for(int i=0;i<len;i++){
//     // 	cout<<A[i]/l<<endl;
//     //     // arr[A[i]/l]++;
//     // }
//     // int i=0;
//     // int flag=0;
//     // for(i=0;i<l;i++){
//     //     if(arr[i]>l){
//     //         flag=1;
//     //         break;
//     //     }
//     // }
//     // if(flag==0) return -1;
    
//     // k=i;
//     // cout<<k<<" "<<l<<" "<<len<<endl;
//     map<int,int> m;
//     // m[0]=879;
//     // mll[k*l+0]=0;
//     // m[k+l+1]=0;
//     // m[k+l+2]=0;
//     // for(i=0;i<l;i++){
//     // 	// cout<<k*l+i<<endl;
//     // 	int ml=k*l+i;
//     // 	cout<<ml<<endl;
//     // 	m[ml]=0;
//     // 	cout<<"input happenend"<<endl;
//     //     // m[k*l+i]=0;
//     // }
    
//     // for(int i=0;i<len;i++){
//     //     if(A[i]>=k*l && A[i]<l*(k+1)){
//     //         m[A[i]]++;
//     //         if(m[A[i]]>1){
//     //             return A[i];
//     //         }
//     //     }
//     // }
    
//     return -1;
    
// }


// int main() {
// 	int len;
// 	cin>>len;
// 	vector<int> v;
// 	int a;
// 	map<int,int>m;
// 	for(int i=0;i<len;i++){
// 		cin>>a;
// 		v.push_back(a);
// 	}
	
// 	// m[sqrt(len)+1]=3;
// 	// m[sqrt(len)+10]=len;
// 	// // m[0]=735;
// 	// int k=9;
// 	// int l=sqrt(len)+1;
// 	// for(int i=0;i<10;i++){
// 	// 	m[k*l+i]=i;
// 	// }
// 	// map<int,int>::iterator it=m.begin();
// 	// while(it!=m.end()){
// 	// 	cout<<it->first<<"->"<<it->second<<endl;
// 	// 	it++;
// 	// }
	
	
	
// 	// cout<<repeatedNumber(v);
// 	// your code goes here
// 	return 0;
// }


// class sol{
// public:
// 	bool operator()(const string& a,const string& b){
// 		string aNew,bNew;
//        int i;
//         for( i=0;i<a.length();i++){
//             if(a[i]==' ') break;
//         }
//        aNew=a.substr(++i);
       
//         i=0;
//         for( i=0;i<b.length();i++){
//             if(b[i]==' ') break;
//         }
//        bNew=b.substr(++i);
       
//        return lexicographical_compare(aNew.begin(),aNew.end(),bNew.begin(),bNew.end());
// 	}
// 	vector<string> doSort(vector<string>& log){
// 		sort(log.begin(),log.end(),*this);
// 		return log;
// 	}
// };

// int32_t main(){
// 	c_p_c();
// 	vector<string> vec{
// 		{"itr1 ak"},
// 		{"itr35 a"},
// 		{"itr1 aaa"}};

// 	for(auto a:vec){
// 		cout<<a<<endl;
// 	}

// cout<<"\n++++++++++++++++++++++++++"<<endl;
// 	sol kk;
// 	vector<string> vec2=kk.doSort(vec);

// 	for(auto a:vec2){
// 		cout<<a<<endl;
// 	}


// 	return 0;
// }