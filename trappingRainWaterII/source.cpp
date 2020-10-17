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

struct Node{
	int val;
	int x,y;
};

struct Compare{
	bool operator()(Node const& left, Node const& right){
		return left.val>right.val?true:false;
	}
};



bool *visited;

int32_t main(){
	c_p_c();
	int R,C;
	cin>>R>>C;
	visited=new bool(R*C);
	
	Node *arr=new Node[R*C];// for dynami array of your own structure we need Node[R*C] not Node(R*C). 
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			visited[i*C+j]=false;
			cin>>arr[i*C+j].val;
			arr[i*C+j].x=i;
			arr[i*C+j].y=j;
		}
	}

	priority_queue<Node,vector<Node>,Compare> pq;

	for(int i=0;i<C;i++){// arr[0][0....C-1]
			pq.push(arr[i]);
	}

	for(int i=1;i<R;i++){// arr[0....R-1][C-1]
			pq.push(arr[i*C+C-1]);
	}

	for(int i=0;i<C-1;i++){// arr[R-1][0....C-1]
			pq.push(arr[(R-1)*C+i]);
	}

	for(int i=1;i<R-1;i++){// arr[0......R][0]
			pq.push(arr[i*C]);
	}

	Node kk;
	int sum=0;

	// queue<Node> q;
	int x[4] = {0 , -1 , 0 , 1};
	int y[4] = {-1 , 0 , 1 , 0};
	int max_val=-1;
	// pq.push(pq.top());
	while(!pq.empty()){
		kk=pq.top();
		pq.pop();
		 if(!visited[kk.x*C+kk.y]){
		 	visited[kk.x*C+kk.y]=true;
		 	// cout<<kk.val<<" "<<kk.x<<" "<<kk.y<<endl;
			if(max_val<kk.val) 
				max_val=kk.val;
			// cout<<"max_val :"<<max_val<<endl;
			int X,Y;
			for(int m=0;m<4;m++){
				X=kk.x+x[m];
				Y=kk.y+y[m];
				if( X>0 && X<R-1 && Y>0 && Y<C-1 ){
					if(!visited[X*C+Y]){
						if(arr[X*C+Y].val < max_val) {
							sum+=max_val-arr[X*C+Y].val;
						}
						pq.push(arr[X*C+Y]);
					}
				}
			}
		 }
	}
	cout<<sum;

	// while(!pq.empty()){
	// 	kk=pq.top();
	// 	pq.pop();
	// 	cout<<kk.val<<" "<<kk.x<<" "<<kk.y<<endl;
	// }


	return 0;
}