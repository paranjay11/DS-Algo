/* Algorithm

1. Since in the worst case the Binary search Tree may become a scewed Binary search tree.
	we change the binary tree by making it a balanced tree , So that the time complexity 
	reduces to logN


*/


#include <bits/stdc++.h>
using namespace std;


struct Node{
	int val;
	Node *left,*right;
};

Node *newNode(int x){
	Node* temp=new Node();
	temp->val=x;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}


void inorderTraversal(Node *node){
	if(node==NULL)
		return ;

	inorderTraversal(node->left);
	cout<<node->val;
	inorderTraversal(node->right);

}


void preorderTraversal(Node *node){
	if(node==NULL)
		return ;

	cout<<node->val;
	inorderTraversal(node->left);
	inorderTraversal(node->right);

}


void inorderStore(Node *node,vector<Node*> &storageVector){
	if(node==NULL)
		return ;

	inorderStore(node->left,storageVector);
	storageVector.push_back(node);
	inorderStore(node->right,storageVector);
}

Node *balanceBSTUtil(int start,int end,vector<Node *> &storageVector){
	if(start>end)
		return NULL;

	int mid=(start+end)/2;
	Node *node=storageVector[mid];

	node->left=balanceBSTUtil(start,mid-1,storageVector);
	node->right=balanceBSTUtil(mid+1,end,storageVector);

	return node;
}

Node* balanceBST(Node *node){
	vector<Node*> storageVector;

	inorderStore(node,storageVector);
	// return NULL;
	return balanceBSTUtil(0,storageVector.size()-1,storageVector);
}


int32_t main(){

	Node *root=newNode(1);
	root->right=newNode(2);
	root->left=NULL;
	root->right->right=newNode(3);
	root->right->left=NULL;
	root->right->right->right=newNode(4);
	root->right->right->left=NULL;

	preorderTraversal(root);

	root = balanceBST(root);
	cout<<endl;
	preorderTraversal(root);

	return 0;
}