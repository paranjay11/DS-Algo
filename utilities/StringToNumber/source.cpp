#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;




int main(){

	string s="123 12 44 254 22 5534 233 3 12 1 8 -1 -34";
	stringstream my_ss(s);
	vector<int> v;
	int temp;
	while(my_ss>>temp){
		v.push_back(temp);
	}

	vector<int>::iterator it=v.begin();
	for( ;it!=v.end();it++){
		cout<<*it<<"\t";
	}
cout<<endl;

	sort(v.begin(),v.end());

	for(it=v.begin() ;it!=v.end();it++){
		cout<<*it<<"\t";
	}

	int ser=12;
	it=find(v.begin(),v.end(),ser);
	if(it!=v.end()) cout<<"we found it!";
	return 0;
}