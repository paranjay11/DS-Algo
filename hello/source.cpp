#include<iostream>

using namespace std;


int fun(int *arr,int len){


	// cout<<len<<endl;
	

	if(len<2){
		return 1;
	}



	int val=0;

	int k=arr[len-2]*10+arr[len-1];

	if(k<=26 && k>0){
		// cout<<k<<endl;
		val=fun(arr,len-2); // 1 21 - 2

	}
		// 121       
	return fun(arr,len-1)+val; // 12 
}



int fun2(int *arr,int len){
	if(len<2) return 1;
	// int sum=1;
	int *v=new int[len];

	// memset(v,0,sizeof(int)*len);
	for(int i=0;i<len;i++){
		v[i]=1;
	}


	if(arr[len-1]==0 && arr[len-2]==0) return 0;
	v[len-1]=1;
	

	for(int i=len-2;i>=0;i--){
		int k=arr[i]*10+arr[i+1];
		if(k<=26 && k>9){
			v[i]=v[i+1]+1;
		}
		else if(k>0 && k<10) v[i] =0;
		else if(k==0) return 0;
	}

	return v[0];
}




int main(){
	int arr[]={1,0,1};

	int val=fun2(arr,4);

	cout<<"\n"<<val;
	return 0;
}