// https://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/

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

string findStr(string str,string pattern){
	int len1=str.length();
	int len2=pattern.length();

	if(len1<len2){
		cout<<"na mila kuch!!!";
		return "";
	}


	int hash_str[256]={0};
	int hash_ptr[256]={0};

	for(int i=0;i<len2;i++){
		hash_ptr[pattern[i]]++;
	}

	int start=0;// starting point of the matched pattern , it keeps changingas we reduce the matched pattern
	int min_len=len1;//the length of the shortest window
	int start_index=-1;// starting index of the matched final pattern
	int len_window=0;
	for(int i=0;i<len1;i++){

		hash_str[str[i]]++;

		if(hash_ptr[str[i]]!=0 && has_str[str[i]]<hash_ptr[str[i]]){
			count++;// this is this length of the matched part of the string
			// 1. aaaaaaaaaaaaaeidjwecjnewcnwjkcnwkjn : str & aaaaaawec : pattern , in this case it will increase the count to a point 
			//    that is making the pattern's character less than the frequency of character occuring in the string.
			//    if the frequecy increases then it wont increase the count. 
			// Either it will exhaust before it matches the length of the pattter like
			// aaaaaaaaaaaaaaaaaaaa : str & aaaaaaaawec: pattern

			// Or it will start increasing the value of count when it encounters another character from the pattern
			// 

			// 2. if it increases 
		}

		// if all the characters are matched from the pattern
		// but the length of the pattern under which these matched characters lie is j-start+1 and it is 
		// greater than len2, hence we need to reduce it
		if(len2==count){ 

			// 
			while(hash_str[str[start]]=>hash_ptr[str[start]] || hash_ptr[str[start]]==0){
				if(hash_ptr[str[start]] < hash_str[str[start]] ){
					hash_str[str[start]]--;
				}
				start++;
			}

			len_window=i-start+1;
			if(min_len > len_window){
				min_len=len_window;
				start_index=start;
			}
		}
	}

	if(start_index==-1){
		cout<<"na mila kuch";
		return "";
	}

	return str.substr(start_index,min_len);

}



int32_t main(){
	c_p_c();
	int T;
	string str;
	string pattern;
	
	cin>>T;
	for(int i=0;i<T;i++){
	    cin>>str;
	    cin>>pattern;
	    cout<<findStr(str,pattern)<<endl;
	}
	return 0;
}