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
struct Node{
	int t1;
	int t2;
};

bool compare2(Node a,Node b){
	return a.t1<b.t1;
}
int32_t main(){
	c_p_c();
	int n;
	cin>>n;
	mk(arr,n,Node);
	// sort(arr,arr+n,compare);
	stack<Node> s;
	for(int i=0;i<n;i++){
		cin>>arr[i].t1>>arr[i].t2;
	}
	sort(arr,arr+n,compare2);
	// for(int i=0;i<n;i++){
	// 	cout<<arr[i].t1<<" ";
	// 	cout<<arr[i].t2<<endl;
	// }
	s.push(arr[0]);
	Node k;

	for(int i=1;i<n;i++){
		k=s.top();
		if(k.t2<arr[i].t2){
			if(k.t2>=arr[i].t1){
				s.pop();
				k.t2=arr[i].t2;
				s.push(k);
			}else{
				s.push(arr[i]);
			}
		}
	}

	while(!s.empty()){
		k=s.top();
		cout<<k.t1<<" "<<k.t2<<endl;
		s.pop();
	}

	return 0;
}