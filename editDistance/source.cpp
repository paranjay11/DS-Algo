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


// int editDistance(string str1,string str2,int i,int j){
// 	// this is when str1 has eneded and the remaining length of the str2 is to be added to str1
// 	if(i==0){
// 		return j;
// 	}

// 	if(j==0){
// 		return i;
// 	}

// 	if(str1[i]==str2[j]){
// 		return editDistance(str1,str2,i-1,j-1);
// 	}
// 	else{
// 		return 1+min(min(editDistance(str1,str2,i,j-1),editDistance(str1,str2,i-1,j)),editDistance(str1,str2,i-1,j-1));
// 	}

// }

int32_t main(){
	c_p_c();

	string str1="geek";
	string str2="gesek";
	int arr[str1.length()][str2.length()];
	for(int i=0;i<str2.length();i++){
		arr[0][i]=i;
	}

	for(int i=0;i<str1.length();i++){
		arr[i][0]=i;
	}
	int sum=0;
	int i,j;
	for(i=1;i<str1.length();i++){
		for(j=1;j<str2.length();j++){
			if(str1[i]==str2[j]){
				arr[i][j]=arr[i-1][j-1];
			}
			else{
				arr[i][j]=1+min(min(arr[i][j-1],arr[i-1][j]),arr[i-1][j-1]);
			}
		}
	}

	cout<<arr[i-1][j-1];

	// cout<<editDistance(str1,str2,str1.length()-1,str2.length()-1);


	return 0;
}