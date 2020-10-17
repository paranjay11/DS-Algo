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

void swapVal(int *a,int *b){
	int temp=*b;
	*b=*a;
	*a=temp;
}

void heapify(int *arr,int len,int i){
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;

	if(arr[l]>arr[largest] && l<len){
		largest=l;
	}
	if(arr[r]>arr[largest] && r<len){
		largest=r;
	}

	if(largest!=i){
		swapVal(&arr[largest],&arr[i]);
		heapify(arr,len,largest);
	}
}


void heapSort(int *arr,int len){
	for(int i=len-1;i>=0;i--){
		heapify(arr,len,i);
	}

	for(int i=len-1;i>=0;i--){
		swapVal(&arr[0],&arr[i]);
		heapify(arr,i,0);
	}
}


int32_t main(){
	c_p_c();
	// int arr[7]={2,4,6,1,5,8,9};
	int len;
	cin>>len;
	int *arr=new int(len);
	for(int i=0;i<len;i++) 
		cin>>arr[i];
	// cout<<"Hello there";
	heapSort(arr,len);
	for(int i=0;i<len;i++){
		for(int j=i;j<len;j++){
			cout<<arr[j]<<"\t";
		}
		cout<<"\n";
	}
	return 0;
}