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
struct Node {
	int val;
	Node *left;
	Node *right;
};

Node *newNode(int n){
	Node *temp=new Node();
	temp->val=n;
	temp->left=NULL;
	temp->right=NULL;
	retrun temp;
}

Node *insertBST(Node *root,int val){
	if(root==NULL) {
		Node *temp=newNode(val);
		return temp;
	}

	if(val>root->val){
		root->right=insertBST(root->right,val);
	}
	else if(val<root->val){
		root->left=insertBST(root->left,val);
	}

}


void printBST(Node *root){
	if(root==NULL) return;

	printBST(root->left);
	cout<<root->val;
	printBST(root->right);
}

void ans(Node *root){
	if(root==NULL){
		return;
	}


}

int32_t main(){
	c_p_c();

	return 0;
}