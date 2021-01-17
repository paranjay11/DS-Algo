//https://www.geeksforgeeks.org/print-all-nodes-at-distance-k-from-given-node-iterative-approach/
#include <bits/stdc++.h>
using namespace std;


struct Node{
	int val;
	Node *left,*right;
};

unordered_map<Node*,Node*> mp;

void fillMap(Node *node){
	queue<Node *> q;

	if(!node) return ;
	
	q.push(node);
	Node *temp;
	while(!q.empty())
	{	
		temp=q.front();
		q.pop();

		if(temp==node){
			mp[temp]=NULL;
		}

		if(temp->left){
			q.push(temp->left);
			mp[temp->left]=temp;
		}

		if(temp->right){
			q.push(temp->right);
			mp[temp->right]=temp;
		}


	}
}

void solve(Node *node,int k){
	unordered_set<Node *> s;
	s.insert(node);
	queue<Node *> q;
	q.push(node);

	int dist=0;
	while(!q.empty()){

		if(dist==k){
			while(!q.empty()){
				cout<<q.front()->val<<"\t";
				q.pop();
			}
		}

		int sze=q.size();
		for(int i=0;i<sze;i++){
			Node *curr=q.front();
			q.pop();

			if(curr->left && s.find(curr->left)==s.end()){
				q.push(curr->left);
				s.insert(curr->left);
			}

			if(curr->right && s.find(curr->right)==s.end()){
				q.push(curr->right);
				s.insert(curr->right);
			}

			if(mp[curr] && s.find(mp[curr])==s.end()){
				q.push(mp[curr]);
				s.insert(mp[curr]);
			}
		}
		dist++;
	}
}

Node* newnode(int val)
{
    Node* temp = new Node;
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}


void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
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
    Node* target = root->left->right;
    fillMap(root);
    solve(target, 3);

	return 0;
}