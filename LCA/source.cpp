// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
Node * lca(Node* root,int n1,int n2);
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int main() {
    c_p_c();

    // string s;
    // getline(cin,s);
    // cout<<s;
    char ws;
    int t;
    // scanf("%d",&t);
    cin>>t;
    // cout<<t<<endl;
    // int ws;
    ws=cin.get();
    // cin>>ws;
    // cout<<ws<<endl;
    // string s;
    // getline(cin,s);
    // cout<<s;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        // scanf("%d %d ",&a,&b);
        // cout<<a<<b<<endl;
        ws=cin.get();
        string s;
        // cin>>s;
        getline(cin,s);
        // cout<<s<<endl;
        Node* root = buildTree(s);
        // cout<<"Till here"<<endl;
        // if(root) cout<<"it not empty"<<endl;
        // else cout<<"its empty"<<endl;
        // printInorder(root);
        Node *node=lca(root,a,b);
        if(node) cout<<"is Valid"<<endl;
        else cout<<"it isn't valid"<<endl;
       // cout<<lca(root,a,b)->data<<endl;
    }
    return 0;
}
// } Driver Code Ends

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

/* If n1 and n2 are present, return pointer
   to LCA. If both are not present, return 
   NULL. Else if left subtree contains any 
   of them return pointer to left.*/


Node* lcaUtil(Node* root ,Node *node,int n1 ,int n2 )
{
    if(root==NULL) return NULL;
    cout<<"reached 0 :"<<root->data<<endl;
    
    // cout<<"reached 1 :"<<root->data<<endl;
    Node *left=lcaUtil(root->left,node,n1,n2);
    Node *right=lcaUtil(root->right,node,n1,n2);
    Node *tis=(n1==root->data || n2==root->data)?root:NULL;
    
    if(left&&right || (left&&tis) || (right&&tis)) {
        node->data=root->data;
        cout<<"has entered once: "<<root->data<<endl;
        return NULL;
    }
    if(n1==root->data || n2==root->data){
        return root;
    }
    else return left==NULL?right:left;
   //Your code here 
}

Node *lca(Node *root,int n1,int n2){
    Node *nodeAns=newNode(-1);
    cout<<"lcs reached "<<root->data<<endl;
    Node* k=lcaUtil(root,nodeAns,n1,n2);
    cout<<"ANS = "<<nodeAns->data<<endl;
    return nodeAns;
}
