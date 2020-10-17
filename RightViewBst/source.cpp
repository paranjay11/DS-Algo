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

struct Node{
	int val;
	struct Node *left,*right;
};

Node *newNode(int val){
	Node *temp=new Node();
	temp->val=val;
	temp->left=temp->right=NULL;
	return temp;
}

void printRightView(Node *node,int *maxVal,int val){
	if(node==NULL) return ;

	if(*maxVal<val){
		cout<<node->val<<endl;
		*maxVal=val;
	}

	printLeftView(node->right,maxVal,val+1);
	printLeftView(node->left,maxVal,val+1);

}


Node *insertNode(Node *node,int val){
	if(node==NULL){
		return newNode(val);
	}

	if(node->val>val){
		// cout<<"came here for val = "<<val<<endl;
		node->left=insertNode(node->left,val);

	}
	else{
		node->right=insertNode(node->right,val);
	}
	return node;
}


int32_t main(){
	c_p_c();

	Node *root =newNode(7);
	root=insertNode(root,3);
	// if(root->left==NULL) cout<<"it is NULL"<<endl;
	// cout<<root->left->val;
	root=insertNode(root,14);
	root=insertNode(root,15);
	root=insertNode(root,13);
	root=insertNode(root,12);
	root=insertNode(root,11);
	root=insertNode(root,10);
	root=insertNode(root,9);
	root=insertNode(root,8);

	// cout<<root->right->val<<endl;
	int maxVal=-1;
	printRightView(root,&maxVal,0);




	return 0;
}