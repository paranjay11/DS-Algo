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
	string val;
	Node *left,*right;
};

Node *newNode(string val){
	Node *temp=new Node ();
	temp->val=val;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

Node *buildTree(vector<string> &arr){
	queue<Node*> q;
	Node *head=newNode(arr[0]);
	int len=arr.size();
	q.push(head);
	int i=1;

	while(!q.empty() && i<len){
		Node* temp=q.front();
		// cout<<"node = "<<temp->val<<" , ";
		q.pop();
		
		if(arr[i]!="N"){
			temp->left=newNode(arr[i]);
			// cout<<"left = "<<temp->left->val<<" , ";
			q.push(temp->left);
			
		}else{
			temp->left=NULL;
		}
		i++;
		
		if(arr[i]!="N"){
			temp->right=newNode(arr[i]);
			// cout<<"right = "<<temp->right->val;
			q.push(temp->right);
			
		}
		else{
			temp->right=NULL;
		}
		i++;
		// cout<<endl;
	}

	return head;
}

void inorder(Node *node){
	if(node){
		inorder(node->left);
		// if(node->val!="N"){
			cout<<node->val<<" ";
		// }
		inorder(node->right);
	} 
}

int32_t main(){
	c_p_c();


	vector<string> arr={"1","2","3","4","N","5","6","7","8","N","N","N","20"};
	Node *head=buildTree(arr);
	inorder(head);

	return 0;
}