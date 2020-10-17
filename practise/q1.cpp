// https://www.geeksforgeeks.org/cadence-interview-experience-software-developer-c/?ref=lbp

#include <bits/stdc++.h>
using namespace std;

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input_q1.txt", "r", stdin);
	freopen("output_q1.txt", "w", stdout);
#endif
}


int32_t main(){
	c_p_c();

	queue<int> s;
	int len;
	cin>>len;
	int *arr=new int[len];
	int k,i;
	for(i=0;i<len;i++){
		cin>>arr[i];
	}

	i=0;
	int *res=new int[len];
	int pos=0;
	int flag=0;
	while(i<len && pos<len){
		int ind=pos%2;
		int val=arr[i]%2;
		if(val==ind){
			res[pos]=arr[i];
			i++;
			pos++;
			if(flag && !s.empty()){
				res[pos]=s.front();
				s.pop();
				pos++;
				flag=0;
			}
		}
		else{
			s.push(arr[i]);
			i++;
			flag=1;
		}
	}

	while(!s.empty()){
		res[pos++]=s.front();
		s.pop();
	}


	for(i=0;i<len;i++){
		cout<<res[i]<<"\t";
	}



	return 0;
}