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

// in the worst case scenario we are left with 1 egg and in then we are forced to go from one step to another

// since we only need to have lowest cases for the worst cases , we try to get the minimum from below two cases:
//	a. when we drop an egg from a floor x and it does not break so we are going to use al the 'n' eggs for the remaining 'k-x' floors
//	b. when we drop an egg and that eegg breaks so we need to go with lower floors for n-1 eggs and k-1 floors.

// why do we itirate over all the floors is because if we consider all egss to be same in strength then the remaining upper floors 
// are just the same as the below ones hence if we take them one by one from k+1 then we can iterate over them?????????

// concept is :
// if we have 10 floors and 1 egg we need to check for each floor 
// but when we have 2 eggs we can be more adventurous in dropping an egg from any floor hence we iterate over every floor and 
// at every floor the above 2 possibilities


// recursive implementation - exponential complexity
int eggDrop(int eggs,int floors){

	//when eggs are 1 or 0
	if(eggs<2){
		return floors;
	}
	if(floors <2){// when there are only 
		return floors;
	}
	int res;
	int minVal=INT_MAX;
	for(int i=1;i<floors;i++){
		res=max(eggDrop(eggs-1,i-1),eggDrop(eggs,floors-i))+1;
		minVal=min(res,minVal);
	}
	return minVal;
}


// DP implementation - eggs*floors*floors complexity- because we iterate over floors and then iterate over each floor with 'x'
int eggDrop2(int eggs,int floors){
	int arr[eggs+1][floors+1];
	for(int i=1;i<=floors;i++){// whenever there is a single egg, we need to travel whole floors
		arr[1][i]=i;
	}

	for(int i=1;i<=eggs;i++){// whenever there is 1 floor, no matter what number of eggs are there, reult will be 1
		arr[i][1]=1;
	}

	int res;
	int minVal=INT_MAX;
	for(int i=2;i<=eggs;i++){// iterate through each number of eggs
		for(int j=2;j<=floors;j++){// iterate though each floor
			arr[i][j]=INT_MAX;
			for(int x=2;x<=j;x++){// iterate through each number of floors as we need to go through all possibility of through egg from each floor 
				res=max(arr[i-1][x-1],arr[i][j-x])+1;
				arr[i][j]=min(arr[i][j],res);
			}
		}
	}
	return arr[eggs][floors];

}


int32_t main(){
	c_p_c();

	int eggs;
	int floors;
	cin>>eggs>>floors;

	cout<<eggDrop2(eggs,floors);

	return 0;
}
