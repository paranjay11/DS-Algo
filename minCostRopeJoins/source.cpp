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
		swapVal(&arr[i],&arr[largest]);
		heapify(arr,len,largest);
	}
}

void heapSort(int *arr,int len){
	for(int i=len-1;i>=0;i--){
		heapify(arr,len,i);
	}

	for(int i=len-1;i>=0;i--){
		swapVal(&arr[i],&arr[0]);
		heapify(arr,i,0);

	}
}

int32_t main(){
	c_p_c();
	mk(arr,4,int);
	// lenght of the array is hardcoded
	for(int i=0;i<4;i++){
		cin>>arr[i];
	}
	int a,b;
	int sum=0;
	for(int i=0;i<3;i++){
		heapSort(arr+i,4-i);
		a=arr[i];
		b=arr[i+1];
		// cout<<a<<" "<<b<<"\t";
		sum+=a+b;
		// cout<<sum<<endl;
		arr[i+1]=a+b;
	}
	cout<<sum;

	return 0;
}