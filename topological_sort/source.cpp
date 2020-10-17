#include <bits/stdc++.h>
using namespace std;

#define w(x) 			int x; cin>>x; while(x--)
#define mk(arr,n,type)  type *arr=new type[n];
#define vii 			vector<int>
#define ll 				long long
#define mii 			map<int,int>
#define pb 				push_back
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

stack<int> s;
map<int,bool> visited;
void topoSort(map<int,vii> g,int val){
	if(!visited[val]){
		visited[val]=true;
		if(g[val].size()>0){
			for(int i=0;i<g[val].size();i++){
				//if(!visited[g[val][i]]){
					//visited[g[val][i]]=true;
					topoSort(g,g[val][i]);
					//s.push(g[val][i]);
					//cout<<g[val][i];
				//}
			}
		}
		s.push(val);
	}

}

int32_t main(){
	c_p_c();

	map<int,vii> g;
	int a,b;
	for(int i=0;i<12;i++){
		cin>>a;
		cin>>b;
		if(b==-1){
			g.insert(pair<int,vector<int>>(a,{}));
		}
		else{
			g[a].push_back(b);
		}
	}

	// for(auto kk:g){
	// 	cout<<kk.first;
	// 	for(auto dd:kk.second){
	// 		cout<<dd;
	// 	}
	// 	cout<<endl;
	// }
	
	// map<int,vii>::iterator it=g.begin();

	for(auto kk:g){
		topoSort(g,kk.first);
	}
	int k=s.size();
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}

	return 0;
}

//test case 
// 2 3
// 3 8
// 4 8
// 4 9
// 5 2
// 5 9
// 8 -1
// 9 -1
