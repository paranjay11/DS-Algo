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

bool visited[100][100];
// int arr[100][100];


int findIslands(vector<int> A[],int N,int M){
	int x[]={-1,0,1,0};
	int y[]={0,-1,0,1};
	int countIsland=0;
	memset(visited,0,sizeof(visited));
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){

			if(!visited[i][j] && A[i][j]){
				queue<pii> q;
				pii p;
				p.ff=i;
				p.ss=j;
				// cout<<p.ff<<" "<<p.ss<<endl;
				q.push(p);
				while(!q.empty()){
					pii k;
					k=q.front();
					if(!visited[k.first][k.second]){
						visited[k.first][k.second]=true;
						for(int m=0;m<4;m++){
							int X=k.first+x[m];
							int Y=k.second+y[m];
							//cout<<X<<" "<<Y;
							if(X>=0 && X<N && Y>=0 && Y<M){
								if(A[X][Y] && !visited[X][Y]){
									q.push(make_pair(X,Y));
								}
								// cout<<X<<" "<<Y<<"\t";
							}
						}
						// cout<<endl;
					}
					q.pop();
				}
				
				countIsland++;
			}
		}
	}
	return countIsland;
	

}

int32_t main(){
	c_p_c();
	//vii<vii> A;
int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}