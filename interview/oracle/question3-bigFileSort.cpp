// algorithm
/*
A huge file cannot be acted upon in the main memory. So we partition it into many files.
1. We sort the partitioned files individually using mergeSort
2. Now we are left with individually sorted partitioned files
3. Now we can treat each partitioned files as arrays to be merged using mersort merge
	(But since we cannot merge it back to a big file in main memory , we use heapSort)
4. We create a minHeap of the first values of these partitioned files and among them the
	lowest/minimum gets saved in a file on external memory.
	After this the saved number needs to be replaced in the minHeap. The new number 
	comes from the same partitioned file to which this saved number belonged to.
5. Thia way the heap maintaines the minimum of all the files at a certain point without 
	overwhelming main memory.
Time complexity : mergeSort for sorting the values :allowedSize*log(allowedSize)
				  to Combine the partitioned files: N as all the values had to be used
				  total time complexity: N+allowedSize*log(allowedSize)

*/








#include <bits/stdc++.h>
using namespace std;

FILE* openFile(char* fileName,char* mode){
	FILE* fp =fopen(fileName,mode);
	if(fp==NULL){
		perror("cannot open file \n");
		exit(EXIT_FAILURE);
	}
	return fp;
}



struct Node{
	int val;
	int fileName;
};

void swapNode(Node *a,Node *b){
	Node temp=*a;
	*a=*b;
	*b=temp;
}

void heapify(Node *arr,int len,int i){
	int smallest =i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<len && arr[left].val < arr[smallest].val){
		smallest=left;
	}

	if(right<len && arr[right].val < arr[smallest].val){
		smallest=right;
	}

	if(smallest!=i){
		swap(arr[smallest],arr[i]);
		heapify(arr,len,smallest);
	}
}

//
void heapSort(Node *arr,int len){
	for(int i=(len-1)/2;i>=0;i--){
		heapify(arr,len,i);
	}
	// for(int i=len-1;i>0;i--){
	// 	swap(arr[0],arr[i]);
	// 	heapify()
	// }
}


void merge(int *arr,int l,int m,int r){
	int i,j,k;
	int ll=m-l+1;
	int rr=r-m;

	int L[ll],R[rr];

	for(i=0;i<ll;i++){
		L[i]=arr[l+i];
	}

	for(j=0;j<rr;j++){
		R[j]=arr[m+j+1];
	}

	i=0;
	j=0;

	k=l;

	while(i<ll && j<rr){
		if(L[i]<=R[j])
			arr[k++]=L[i++];
		else
			arr[k++]=R[j++];
	}

	while(i<ll){
		arr[k++]=L[i++];
	}

	while(j<rr){
		arr[k++]=R[j++];
	}
}


void mergeSort(int *arr,int l,int r){
	if(l<r){
		int mid= l + (r-l)/2;

		mergeSort(arr,l,mid);
		mergeSort(arr,mid+1,r);

		merge(arr,l,mid,r);
	}
}


// All the sorted partitioned Files will be merged here
void mergeFiles(char *outputFile,int n,int k){// k=numFiles , n=
	FILE* in[k];

	for(int i=0;i<k;i++){
		char fileName[2];
		snprintf(fileName,sizeof(fileName),"%d",i);
		in[i]=openFile(fileName,"r");
	}

	FILE* outFile=openFile(outputFile,"w");

	Node *arr=new Node[k];
	int i=0;
	// for reading the first number from each file
	for(i;i<k;i++){
		if(fscanf(in[i],"%d ",&arr[i].val)!=1)
			break;

		arr[i].fileName=i;
	}

	heapSort(arr,i);

	int count=0;

	while(count!=i){

		Node root = arr[0];
		fprintf(outFile,"%d ",root.val);// store the smallest element in the outputFile
		if(fscanf(in[root.fileName],"%d ",&root.val)!=1){// EOF gets reached and we start emptying the elements in the array
			// cout<<"count = "<<count<<endl;
			// cout<<"reached this error!!!!!!!!"<<endl;
			root.val=INT_MAX;
			count++;
		}

		arr[0]=root;
		heapify(arr,k,0);

	}
	// cout<<"count = "<<count<<endl;
	for(int m=0;m<k;m++){
		fclose(in[m]);
	}

	fclose(outFile);
}

// break the BIG input file in to many partitioned files to be sorted individually
void breakFile(char* inputFile,int allowedSize,int numFiles){
	FILE* in = openFile(inputFile,"r");

	FILE* out[numFiles];
	char fileName[2];
	for(int i=0;i<numFiles;i++){
		snprintf(fileName,sizeof(fileName),"%d",i);
		out[i]=openFile(fileName,"w");
	}

	int *arr=new int[allowedSize];
	bool moreInput=true;
	int nextOutputFile=0;

	int i=0;
	while(moreInput){
		for(i=0;i<allowedSize;i++){// break files in the allowedSize
			if(fscanf(in,"%d ",&arr[i])!=1){ // if the size of the file has been exhausted
				moreInput=false;
				break;
			}
		}

		mergeSort(arr,0,i-1);

		for(int j=0;j<i;j++){
			fprintf(out[nextOutputFile],"%d ",arr[j]);
		}

		nextOutputFile++;
	}

	for(int i=0;i<numFiles;i++){
		fclose(out[i]);
	}

	fclose(in);
}


void externalSort(char *inputFile,char *outputFile,int numFiles,int allowedSize){
	breakFile(inputFile,allowedSize,numFiles);
	mergeFiles(outputFile,allowedSize,numFiles);
}

int32_t main(){
	// c_p_c();
	int numFiles=10;

	int allowedSize=1000;
	char inputFile[]="input.txt";
	char outFile[]="output.txt";

	FILE* in = openFile(inputFile,"w");

	srand(time(NULL));

	for(int i=0;i<numFiles*allowedSize;i++){
		fprintf(in,"%d ",rand());
	}

	fclose(in);

	externalSort(inputFile,outFile,numFiles,allowedSize);

	return 0;
}