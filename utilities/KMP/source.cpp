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


// see tushar roy's video and his solution in github

int *create_lsp(char *A,int len){
	int *lsp=new int[len];
	int i=0;
	int j=1;
	memset(lsp,0,sizeof(int)*len);
	while(i<len && j<len){
		if(A[i]==A[j]){
			lsp[j]=i+1;
			i++;
			j++;
		}
		else{
			if(i>0){
				i=lsp[i-1];
			}
			else{
				i=0;
				j++;
			}
		}
	}
	// for(int i=0;i<len;i++){
	// 	cout<<lsp[i]<<" ";
	// }

	// cout<<endl;
	return lsp;
}


int KMP(char *text,int lenText,char *pattern,int lenPattern){
	int *lsp=create_lsp(pattern,lenPattern);
	int i=0;
	int j=0;
	int index;
	while(i<lenText && j<lenPattern){
		if(text[i]==pattern[j]){
			if(j==lenPattern-1) index=i; 
			i++;
			j++;
		}
		else{
			if(j>0){
				j=lsp[j-1];
			}
			else{
				i++;
			}
		}
	}
	if(j==lenPattern){
		return index-lenPattern+1;
	}
	return -1;


}


int32_t main(){
	c_p_c();

	string text="abababcabc";
	string pattern="abc";

	int lenText=text.length();
	int lenPattern=pattern.length();

	char *textChar=new char[lenText+1];
	char *patternChar=new char[lenPattern+1];

	strcpy(textChar,text.c_str());
	strcpy(patternChar,pattern.c_str());

	cout<<KMP(textChar,lenText,patternChar,lenPattern);

	return 0;
}