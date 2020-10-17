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


// struct Node{
// 	int date;
// 	int key;
// };


// class compare{
// public:
// 	bool operator()(const Node &a,const Node &b){
// 		if(a.date == b.date){
// 			if(a.key <b.key){
// 				return true;
// 			}
// 			else return false;
// 		}

// 		return a.date<b.date;
// 	}
// };

// // key val date
// // 1    a  20180101
// // 1    b  20200101
// // 2    c  20180101

// // void inorder(int key,int date,map){

// // }




// int main(){
// 	map<Node,char,compare> m;

// 	Node n;
// 	n.date=20170101;
// 	n.key=1;

// 	m[n]='a';

	
// 	n.date=20200101;
// 	n.key=1;

// 	m[n]='b';

// 	n.date=20200102;
// 	n.key=1;

// 	m[n]='c';

// 	n.date=20200103;
// 	n.key=1;

// 	m[n]='d';

// 	n.date=20170102;
// 	n.key=1;

// 	m[n]='e';

// 	n.date=20180101;
// 	n.key=1;

// 	m[n]='f';

	
// 	n.date=20180101;
// 	n.key=2;

// 	m[n]='g';

// 	map<Node,char>::iterator it=m.begin();

// 	int k=1;
// 	int time=2019;

// 	for(;it!=m.end();it++){
// 		if(it->first.date/10000 < time && it->first.key==k)
// 			cout<<"key = "<<it->first.key<<" , val = "<<it->second<<" , date = "<<it->first.date<<endl;
// 	}


// 	return 0;
// }


void swapVal(int *a,int *b){
     int temp=*b;
     *b=*a;
     *a=temp;
 }
 
 void heapify(int *arr,int len,int i){
     int largest = i;
     int l = 2*i+1;
     int r = 2*i+2;
     
     if(l<len && arr[l] > arr[largest]){
         largest = l;
     }
     
     if(r<len && arr[r] > arr[largest]){
         largest = r;
     }
    
    if(largest != i){
        // int temp = arr[i];
        // arr[i]=arr[largest];
        // arr[largest] = temp;
        swapVal(&arr[i],&arr[largest]);
        heapify(arr,len,largest);
    }

 }
 
 void heapSort(int *arr,int len){
     for(int i=len-1;i>=0;i--){
         heapify(arr,len,i);
     }
     
     for(int i=len-1;i>0;i--){
         swapVal(&arr[0],&arr[i]);
         heapify(arr,i,0);
     }
 }
 
 
int solution(int A[], int N) {
    // write your algorithm in C
    heapSort(A,N);
    for(int i=0;i<N;i++){
        printf("%d\t",A[i]);
    }
    return -1;
}


int main(){
	int arr[]={5,4,3,2,1};
	solution(arr,5);
	return 0;
}


// void sorted_stack(stack<int> &ss,int temp){
// 	if(!ss.empty() && ss.top() <temp){
// 		int temp2=ss.top();
// 		ss.pop();
// 		sorted_stack(ss,temp);
// 		ss.push(temp2);
// 	}
// 	else{
// 		ss.push(temp);
// 	}
// }


// void sort(stack<int> &ss){
// 	int temp = ss.top();
// 	ss.pop();
// 	if(!ss.empty()) sort(ss);
// 	sorted_stack(ss,temp);
// }

// void print_stack(stack<int> &ss){
// 	while(!ss.empty()){
// 		cout<<ss.top()<<endl;
// 		ss.pop();
// 	}
// }


// int main(){
// 	stack<int> ss;

// 	ss.push(17);
// 	ss.push(12);
// 	ss.push(19);
// 	ss.push(20);

// 	sort(ss);
// 	print_stack(ss);

// }


























// struct coord{
// 	int x,y;
// };


// int dx[4]={0,-1,0,1};
// int dy[4]={-1,0,1,0};

// bool fun(int **arr,int k,int n,int sum,bool **visited,coord cell){
// 	// stack<cell> s;
// 	coord ck;
// 	bool val=false;
// 	if(sum==k){
// 		cout<<sum<<endl;
// 		return true;
// 	}
// 	else if( sum>k ) return false;
// 	// if(!visited[cell.x][cell.y]){
// 		visited[cell.x][cell.y]=true;
// 		for(int i=0;i<4;i++){

// 			int X= cell.x+dx[i];
// 			int Y =cell.y+dy[i];

// 			if(X>=0 && X<n && Y>=0 && Y<n && !visited[X][Y] && arr[X][Y]){
// 				// visited[X][Y]=true;
// 				ck.x=X;
// 				ck.y=Y;
// 				val = fun(arr,k,n,sum+1,visited,ck);
// 			}
// 			if(val) return true;

			
// 		}
// 		visited[cell.x][cell.y]=false;
	
// 	return false;


// }


// int main(){

// 	int size=5;
// 	int **arr=new int*[size];
// 	bool **visited=new bool*[size];


// 	for(int i=0;i<size;i++){
// 		arr[i]=new int[size];
// 		visited[i]=new bool[size];
// 		for(int j=0;j<size;j++){
// 			arr[i][j]=1;
// 			visited[i][j]=false;
// 		}
// 	}
// 	coord cell;
// 	cell.x=0,cell.y=0;
// 	cout<<fun(arr,25,size,1,visited,cell);

// return 0;
// }































// char *tidyNum(char arr[],int len){
// 	for(int i=len-1;i>=0;i--){
// 		if(arr[i-1]>arr[i]){
// 			arr[i-1]--;
// 			for(int j=i;j<len;j++){
// 				arr[j]='9';
// 			}
// 		}
// 	}
// 	return arr;
// }


// int main(){
// 	char k[]="91234";
// 	char *arr=tidyNum(k,6);
// 	for(int i=0;i<6;i++){
// 		cout<<arr[i];
// 	}


// }






// struct retValue{
// 	int inc;
// 	int dec;
// };

// struct Node {
// 	int val;
// 	Node *left;
// 	Node *right;
// };

// Node * newNode(int val){
// 	Node *temp=new Node ();
// 	temp->val=val;
// 	temp->left=NULL;
// 	temp->right=NULL;
// 	return temp;
// }


// retValue func(Node* node){
// 	if(node==NULL){
// 		return {0,0};
// 	}

// 	retValue left = func(node->left);
// 	retValue right = func(node->right);

	
// }



// class base{
// public:
// 	base(){
// 		cout<<"constructing of base "<<endl;
// 	}
// 	void fun(){
// 		cout<<"base wala fun()"<<endl;
// 	}
// 	 ~base(){
// 		cout<<"Destructor of base called"<<endl;
// 	}
// };

// class derived:public base{
// public:
// 	derived(){
// 		cout<<"constructor of derived called"<<endl;
// 	}
// 	 void fun(){
// 		cout<<"derived wala fun()"<<endl;
// 	}
// 	~derived(){
// 		cout<<"destructor of derived called"<<endl;
// 	}
// };

// class C{

// };

// void printBinary(int decimal) {
//    // your logic goes here 
   
//    string s="";
//    while(decimal>0){
//    		int val=decimal%2;
//    		s+=to_string(val);
//    		decimal=decimal/2;
//    }

//    int len=s.length();
//    while(len--){
//    		cout<<s[len];
//    }
// }

// void inorder(Node* node){
// 	if(node!=NULL){
// 		inorder(node->left);
// 		cout<<node->val<<" ";
// 		inorder(node->right);
// 	}
// }



// int32_t main(){
// 	c_p_c();



// 	Node *head=newNode(71);
// 	head->left=newNode(20);
// 	head->right=newNode(90);
// //------------------------------
// 	Node *leftHead=head->left;
// 	Node *rightHead=head->right;

// 	leftHead->left=newNode(8);
// 	leftHead->right=newNode(19);

// 	rightHead->left=newNode(91);
// 	rightHead->right=newNode(97);
// // ----------------------------------
// 	leftHead=leftHead->right;
// 	leftHead->left=newNode(18);
// // ---------------------------------	
// 	leftHead=leftHead->left;
// 	leftHead->left=newNode(16);
// 	leftHead->right=newNode(17);
// // ---------------------------------

// 	leftHead=leftHead->left;
// 	leftHead->right=newNode(15);

// // -------------------------------
// 	leftHead=leftHead->right;
// 	leftHead->left=newNode(14);
// 	leftHead->right=newNode(13);

// // -------------------------------
// 	leftHead=leftHead->right;
// 	leftHead->left=newNode(22);
// 	leftHead->right=newNode(10);
// // ----------------------------------


// 	rightHead=rightHead->right;
// 	rightHead->left=newNode(98);
// 	rightHead->right=newNode(99);

// 	rightHead->right->right=newNode(100);
// 	rightHead->left->left=newNode(91);


// 	inorder(head);




	// int i=2*1000000000;
	// cout<<i<<endl;
	// long long int sum=i*25000;
	// cout<<sum;

	// derived *d=new derived();
	// base *b=d;

	// b->fun();

	// cout<<"sizeof(b) = "<<sizeof(base)<<endl;
	// cout<<"sizeof(d) = "<<sizeof(derived)<<endl;
	// cout<<"sizeof(C) = "<<sizeof(C)<<endl;
	// delete b;

	// printBinary(4);

// 	return 0;
// }