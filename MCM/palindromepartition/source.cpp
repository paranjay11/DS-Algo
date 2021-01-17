#include <bits/stdc++.h>
using namespace std;


void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


bool isPlaindrome(string a,int i,int j){
	int len=j-i+1;
	int strLen=a.length();
	if(len<2) return true;
	
	while(i<j){
		if(a[i]!=a[j]) return false;
		i++,j--;
	}

	return true;
}

int palindromepartition(string a,int i,int j){
	if(i>=j)
		return 0;

	if(isPlaindrome(a,i,j))
		return 0;

	int temp=0;
	int min_val=INT_MAX;

	for(int k=i;k<j;k++){
		temp=palindromepartition(a,i,k)+palindromepartition(a,k+1,j)+1;
		min_val=min(min_val,temp);
	}
	return min_val;
}


int32_t main(){
	c_p_c();

	string str="abcdefg";
	cout<<palindromepartition(str,0,str.length()-1);



	return 0;
}
