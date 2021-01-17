#include <bits/stdc++.h>
using namespace std;


struct Node{
	int val;
	Node *left,*right;
};

int bfsIterative(Node *node){
	queue<Node*> q;
	q.push(node);

	int height=0;
	while(!q.empty()){
		// Node *temp=q.front();
		// q.pop();

		height++;

		int size=q.size();
		for(int i=0;i<size;i++){
			Node *temp=q.front();
			q.pop();

			if(temp->left){
				q.push(temp->left);
			}

			if(temp->right){
				q.push(temp->right);
			}
		}
	}
	return height;
}
void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

Node* newnode(int val)
{
    Node* temp = new Node;
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}



int32_t main(){
	c_p_c();

	Node* root = newnode(20);
    root->left = newnode(8);
    root->right = newnode(22);
    root->right->left = newnode(5);
    root->right->right = newnode(8);
    root->left->left = newnode(4);
    root->left->left->left = newnode(25);
    root->left->right = newnode(12);
    root->left->right->left = 
                   newnode(10);
    root->left->right->left->left = 
                   newnode(15);
    root->left->right->left->right = 
                   newnode(18);
    root->left->right->left->right->right = 
                   newnode(23);
    root->left->right->right = 
                   newnode(14);
    // Node* target = root->left->right;
    
    cout<<bfsIterative(root->left->right);

	return 0;
}