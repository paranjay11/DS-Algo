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
#define debug 0

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

struct Node{
	int val;
	Node *left,*right;
};

Node *newNode(int val){
	Node *temp=new Node();
	temp->val=val;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

int neg=-1;

Node *traverse(Node *node){
	if(node==NULL) return NULL;

	node->left=traverse(node->left);
	if(node->left){
		node->left->right=node;
#if debug
		cout<<"Node : " <<node->val<<" , "<<"node->left : "<<node->left->val <<endl;
		cout<<node->left->val<<"'s next is "<<node->val<<endl;
#endif
	}
#if debug
	else{
		cout<<"Node : " <<node->val<<" , "<<"node->left : "<<neg <<endl;
	}
#endif

	node->right=traverse(node->right);
	if(node->right){
		node->right->left=node;
#if debug
		cout<<"Node : " <<node->val<<" , "<<"node->right : "<<node->right->val<<endl;
		cout<<node->right->val<<"'s prev is "<<node->val<<endl;
#endif	
	}
#if debug	
	else{
		cout<<"Node : " <<node->val<<" , "<<"node->right : "<<neg <<endl;
	}
#endif

	if(node->left && node->right) return node->right;
	else if(node->left || node->right) {
		return node->left==NULL ? node->right:node->left;
	}
	return node;
}

void inorderTraversal(Node *node){
	if(node==NULL) return;

	inorderTraversal(node->left);
	cout<<node->val<<" ";
	inorderTraversal(node->right);
}


int32_t main(){
	c_p_c();
	Node *head=newNode(10);
	head->left=newNode(12);
	head->right=newNode(15);
	head->left->left=newNode(25);
	head->left->right=newNode(30);
	head->right->left=newNode(36);

	//inorderTraversal(head);
	 Node *kk=traverse(head);
	Node *temp=kk;
	while(temp->left){
		//cout<<temp->val<<" ";
		temp=temp->left;
	}

	while(temp){
		cout<<temp->val<<" ";
		temp=temp->right;
	}

	return 0;
}