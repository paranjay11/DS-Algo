//https://www.geeksforgeeks.org/boggle-find-possible-words-board-characters/
#include <iostream>
#include <string>
#include <set>
#include <sstream>
using namespace std;

void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}


struct Node{
    Node *children[26];
    bool isLeaf;
};

Node *newNode(){
    Node *temp=new Node();
    for(int i=0;i<26;i++){
        temp->children[i]=NULL;
    }
    temp->isLeaf=false;
    return temp;
}

Node *head;
void insertWord(string str){
    int len=str.length();
    
    Node *temp=head;
    int pos;
    for(int i=0;i<len;i++){
        pos=str[i]-'a';
        if(!temp->children[pos]){
            temp->children[pos]=newNode();
        }
        temp=temp->children[pos];
        if(i==len-1) temp->isLeaf=true;
    }
}

bool isWord(string str){
     int len=str.length();
    
    Node *temp=head;
    int pos;
    for(int i=0;i<len;i++){
        pos=str[i]-'a';
        if(!temp->children[pos]){
            return false;
        }
        temp=temp->children[pos];
    }
    return (temp->isLeaf==true)?true:false;
}

struct StackNode{
    int x,y;
};

    int dx[8]={-1,-1,-1, 0, 1, 1, 1, 0};
    int dy[8]={-1, 0, 1, 1, 1, 0,-1,-1};


void searchWords(char *boggle,int M,int N,bool *visited,StackNode current ,string &str,set<string> &res){
    // cout<<"hellor";
    int x=current.x;
    int y =current.y;

    visited[x*N+y]=true;

    str+=boggle[x*N+y];

    if(isWord(str)){
        res.insert(str);
    }

    for(int p=0;p<8;p++){
        int X=x+dx[p];
        int Y=y+dy[p];
        
        if(X>=0 && X<M && Y>=0 && Y<N){
            StackNode nxt;
            nxt.x=X;
            nxt.y=Y;
            if(!visited[X*N+Y])
                searchWords(boggle,M,N,visited,nxt,str,res);
        }
    }

    str.erase(str.length()-1);
    visited[x*N+y]=false;
    
}


// Node *head;

int main() {
	//code
	c_p_c();
	int T;
	int N,M;
	// cin>>T;
    // scanf("%d",T);
    cin>>T;
    for(int i=0;i<T;i++){

        int numWords;
        cin>>numWords;

        // cout<<numWords;
        head = new Node();
        string n;// for taking in the space or the '\n' new line after the integer
        getline(cin,n);
        cout<<n;

        getline(cin,n);// this actually reads the string even with the spaces
        // cout<<n;
        // breaking the string into words
        stringstream my_str(n);
        string k;
        // cout<<endl;
        while(my_str>>k){
            // cout<<k<<endl;
            insertWord(k);
        }
        
        
        // char kk[1000];
        string str="";

        // cout<<"her";
        cin>>M;
        cin>>N;
        // cout<<"jeelo therererrerere"<<M<<"\t"<<N;
        char *boggle=new char[M*N];
        bool *visited=new bool[M*N];
        for(int ii=0;ii<M;ii++){
            for(int jj=0;jj<N;jj++){
                // cout<<"kindea there";
                cin>>boggle[ii*N+jj];
                visited[ii*N+jj]=false;
            }
        }

        set<string> res;
        StackNode nxt;
        str="";
        for(int ii=0;ii<M;ii++){
            for(int jj=0;jj<N;jj++){
                nxt.x=ii;
                nxt.y=jj;
                // cout<<"jere";
                searchWords(boggle,M,N,visited,nxt,str,res);
            }
        }

       set<string>::iterator it=res.begin();
        for(it;it!=res.end();it++){
            cout<<*it<<"\t";
        }
    }
	
	return 0;
}