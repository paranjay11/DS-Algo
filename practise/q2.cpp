// https://www.geeksforgeeks.org/cadence-interview-experience-software-developer-c/?ref=lbp
#include <bits/stdc++.h>
using namespace std;


void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input_q2.txt", "r", stdin);
	freopen("output_q2.txt", "w", stdout);
#endif
}

void swapVal(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void heapify(int *arr,int len,int i){
	int largest = i;
	int left=2*i+1;
	int right = 2*i+2;

	if(left<len && arr[left] < arr[largest]){
		largest=left;
	}

	if(right<len && arr[right] < arr[largest]){
		largest=right;
	}


	if(largest!=i){
		swapVal(&arr[i],&arr[largest]);
		heapify(arr,len,largest);
	}
}

void heapSort(int *arr,int len){
	for(int i=(len-1)/2;i>=0;i--){
		heapify(arr,len,i);
	}

	for(int i=len-1;i>0;i--){
		swapVal(&arr[0],&arr[i]);
		heapify(arr,i,0);
	}
}



int32_t main(){
	c_p_c();
	// priority_queue<int> q;
	int len;
	int k;
	cin>>len;
	cin>>k;
	int *arr=new int[k];
	// int *res=new int[k];
	int i=0;
	int j=0;
	for(i;i<k;i++){
		cin>>arr[i];
	}
	heapSort(arr,k);
	int temp;
	for(i=k;i<len;i++){
		cin>>temp;
		if(temp > arr[k-1]){
			arr[k-1]=temp;
			heapSort(arr,k);
		}
	}

	cout<<"kth Largest = "<<arr[0]; 

	return 0;
}