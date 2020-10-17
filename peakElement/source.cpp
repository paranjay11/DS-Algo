//https://www.geeksforgeeks.org/find-a-peak-in-a-given-array/
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


// concept
// (in an array if we use binary search we assume it to be sorted but we can use it without a sorted one).
// we take a middle element and then see if it is the peak element, if yes then return arr[mid]
// else see if left of mid is greater then the mid element , if yes then we assume the peak is going to be on the left
// orl else we go to the element which to the right of mid , if that is bigger than mid then that side may have peak.



int peakElement(int *arr,int i,int j,int n){
	int mid=i+(j-i)/2;
	// if(j>=i){
		if(arr[mid]>=arr[mid-1] && arr[mid]>=arr[mid+1] || mid==0 || mid== n-1){ //if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1] || mid==0 || mid== n-1){ <<<<< this gives a problem because in the case of 20,1,1,1,1,20 it gives 20 as an answer which is correct but if we use 20,21,21,21,21,20 we  will get 20 which is incorrect hence we have to use <= and >= in the if(condition)
			// cout<<mid<<endl;
			return arr[mid];
		}
		else if(arr[mid]<arr[mid-1]){
			// cout<<mid<<endl;
			return peakElement(arr,i,mid-1,n);
		}
		else {
			// cout<<mid<<endl;
			return peakElement(arr,mid+1,j,n);
		}
	// }
}

int32_t main(){
	c_p_c();
	int arr[] = { 20, 1, 1, 1, 1, 20 }; 
	cout<<peakElement(arr,0,5,6);

	return 0;
}