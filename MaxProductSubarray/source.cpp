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


int maxProduct(int *arr,int len){
	int max_curr=1;
	int min_curr=1;
	int max_so_far=1;

	int flag=0;

	/* Traverse through the array. Following values are  
    maintained after the i'th iteration:  
    max_ending_here is always 1 or some positive product  
                    ending with arr[i]  
    min_ending_here is always 1 or some negative product  
                    ending with arr[i] */

	for(int i=0;i<len;i++){
		/* If this element is positive, update max_ending_here.  
        Update min_ending_here only if min_ending_here is  
        negative */
		if(arr[i]>0){
			max_curr = max(max_curr * arr[i] ,1);
			min_curr = min(min_curr , 1);
			flag=1;
		}
		/* If this element is 0, then the maximum product  
        cannot end here, make both max_ending_here and  
        min_ending_here 0  
        Assumption: Output is alway greater than or equal  
                    to 1. */
		else if( arr[i]==0){
			max_curr=1;
			min_curr=1;
		}

		/* If element is negative. This is tricky   
        max_ending_here can either be 1 or positive.   
        min_ending_here can either be 1 or negative.   
        next max_ending_here will always be prev.   
        min_ending_here * arr[i] ,next min_ending_here   
        will be 1 if prev max_ending_here is 1, otherwise   
        next min_ending_here will be prev max_ending_here *   
        arr[i] */
		else{
			int temp = max_curr;// this is importtant
			max_curr = max(min_curr*arr[i],1);
			min_curr = min(temp*arr[i],1);
		}

		if(max_so_far < max_curr){
			max_so_far=max_curr;
		}
	}

	if(flag ==0 && max_so_far == 1){
		return 0;
	}

	return max_so_far;

}

int32_t main(){
	c_p_c();
	int arr[] = { 6, -3, -10, 0, 2}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Maximum Sub array product is "
         << maxProduct(arr, n); 
    return 0; 
}