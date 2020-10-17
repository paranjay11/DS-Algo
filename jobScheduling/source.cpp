#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

class emp{
public:
	int id;
	int deadline;
	int profit;
	// emp(int id,int deadline,int profit){
	// 	this->id=id;
	// 	this->deadline=deadline;
	// 	this->profit=profit;
	// }
};

bool compareThis(const emp job1,const emp job2){
	return job1.profit>job2.profit;
}


int main(){

c_p_c();

	int T;
	cin>>T;
	int id,deadline,profit;
	for(int i=0;i<T;i++){
		int numJobs;
		cin>>numJobs;
		// vector<emp> jobs;
		emp *jobs=new emp[numJobs];
		for(int j=0;j<numJobs;j++){
			cin>>id>>deadline>>profit;
			//emp job(id,deadline,profit);
			// jobs.push_back(job);
			jobs[j].id=id;
			jobs[j].deadline=deadline;
			jobs[j].profit=profit;
		}
		// sort(jobs.begin(),jobs.end(),compareThis);
		sort(jobs,jobs+numJobs,compareThis);
// 		cout<<jobs.size()<<endl;

		// vector<bool> ids(jobs.size(),false);
		bool *ids=new bool[numJobs];
		memset(ids,false,sizeof(ids));
		int count;
		int countJobs=0;
		int sum=0;
		for(int k=0;k<numJobs;k++){
// 			id=jobs[k].id;
            profit=jobs[k].profit;
			deadline=jobs[k].deadline;
			count=deadline-1;
			
			///cout<<id<<"\t"<<deadline<<"\t"<<jobs[k].profit<<endl;
			while(count>=0){
				if(ids[count]==false){
					ids[count]=true;
				    countJobs++;
				    sum+=profit;
					//cout<<id<<"<<<<<<<<"<<endl;
					break;
				}
				count--;
			}
		}
		cout<<countJobs<<" "<<sum<<endl;
		
	}


}