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

// from len-1 to zero
int func(int *weights,int *values,int len,int weight,int sum){
	if(weight<=0 || len<=0){
		return sum;
	}

	int temp1=INT_MIN;
	int temp2=INT_MIN;
	// if(weights[len-1]>weight){
		temp1=func(weights,values,len-1,weight,sum);
	// }
	if(weights[len-1]<=weight){
		temp2=func(weights,values,len-1,weight-weights[len-1],sum+values[len-1]);
	}
	

	return max(temp1,temp2);
}

// from len-1 to zero
int func2(int *weights,int *values,int len,int weight){
	if(weight<=0||len<=0){
		return 0;
	}

	if(weights[len-1]<=weight){
		return max((values[len-1]+func2(weights,values,len-1,weight-weights[len-1])),
					func2(weights,values,len-1,weight));
	}
	else {
		return func2(weights,values,len-1,weight);
	}

}

// from 0 to len-1
int func3(int *weights,int *values,int len,int weight,int sum,int i){
	if(weight<=0 || i==len){
		return sum;
	}

	int temp1=INT_MIN;
	int temp2=INT_MIN;
	// Here we are sending the sum in the function func .
	// hence the sum goes on increasing till the end while exhausting the whole bag weight limit 
	// At the base condition it returns the sum till yet because whatever is the value has to be the total sum yet
	// or else the below part of the code says:
	// 

	// we have to take two possibility if we include the item or not...

	// this takes responsibility of not incluing the item
	// if(weights[i]>weight){
		temp1=func3(weights,values,len,weight,sum,i+1);
	// }
	// this takes the responsiblity of including the item in the bag only and only if it is having the waight lesses than present weight
	if(weights[i]<=weight){
		temp2=func3(weights,values,len,weight-weights[i],sum+values[i],i+1);
	}
	

	return max(temp1,temp2);
}

// from 0 to len-1
int func4(int *weights,int *values,int len,int weight,int i){
	if(weight<=0||i==len){
		return 0;
	}

	// Here we are reaching the end of the recursion without sending the sum in the function func
	// Hence we are only exhausting the weight limit.
	// at each stage we are keeping the values[i] & waiting for the values returned from the rest of the recursion.
	if(weights[i]<=weight){
		return max((values[i]+func4(weights,values,len,weight-weights[i],i+1)),
					func4(weights,values,len,weight,i+1));
	}
	else {
		return func4(weights,values,len,weight,i+1);
	}

}

int32_t main(){
	c_p_c();
	int weights[]={10,10,3,4,2};
	int values[]={5,50,26,25,2};
	int weight=10;
	cout<<func(weights,values,5,weight,0)<<endl;
	cout<<func2(weights,values,5,weight)<<endl;
	cout<<func3(weights,values,5,weight,0,0)<<endl;
	cout<<func4(weights,values,5,weight,0)<<endl;

	return 0;
}
