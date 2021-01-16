#include <bits/stdc++.h>
using namespace std;


/*
problem statement: Here we have to check if there is any possibility of getting a 'True'
				   from forming a pair of brackets in the equation.
				   example : T&T^F|T
				   1st possibility : T&(T^F)|T	=> T&T|T  => T
				   2nd possibility : T&T^(F|T)  => T&T^T  => F
				   
				   since 1st one is a possibility that return a true for the entire equation, 
				   hence this is returns true. 

consider a possibility : equation =  (left hand statement: LHS) XOR (right hand statement: RHS)
						 Just to make the equation to return true there are two possibility
						 1st: LHS=true & RHS=false
						 2nd: LHS=false & RHS=true
						 hence when we want LHS to be True/False , we need to send that information also
						 as an argument(isTrue)
						 similarly for RHS to be True/False


	if we converge to i==j
	this means we are are the Character T or F , because k will always point at operator
	At this cond. we need to check what we need from this function call i.e.
	if this solve function call is for LHS to be true solve(str,i,k-1,true)
							 .. or for LHS to be false solve(str,i,k-1,false)

	this tell us if we want LHS to be false i.e. if there is a possibility of LHS to be false
	if yes then the solve(str,i,k-1,false) will return true. -> this means LHS can be false.


*/ 


bool solve(string str,int i,int j,int isTrue){
	if(i>j) return false;

	if(i==j){
		if(isTrue==true){
			return str[i]=='T'?true:false;
		}
		else{
			return str[i]=='F'?true:false;
		}
	}

	bool mm=0;
	bool lFalse,lTrue;
	bool rFalse,rTrue;
	for(int k=i+1;k<=j-1;k++){
		// calculate LHS/RHS for true and false
		// lFalse = can LHS be false(does possibility exist) ? true:false;
		// lTrue = can LHS be true(does possibility exist) ? true:false;
		// similarly for RHS 
		lFalse=solve(str,i,k-1,false);
		lTrue=solve(str,i,k-1,true);
		rFalse=solve(str,k+1,j,false);
		rTrue=solve(str,k+1,j,true);

		if(str[k]=='^'){
			if(isTrue==true){
				mm=mm+lFalse*rTrue + lTrue&rFalse;// <<<<<< change | -> + answer changes??? operator precedence 
			}
			else{
				mm=mm+lFalse*rFalse + lTrue*rTrue;
			}
		}

		if(str[k]=='|'){
			if(isTrue==true){
				mm=mm+lTrue*rTrue + lTrue*rFalse + lFalse*rTrue;
			}
			else{// mm will be true for if lFalse=true && rFalse=true (and also mm=true), this means that we want to find a possiblity of 
				 // LHS to be false, which comes out to be true and same for RHS.
				mm=mm+lFalse*rFalse;
			}
		}

		if(str[k]=='&'){
			if(isTrue==true){
				mm=mm+lTrue*rTrue ;
			}
			else{
				mm=mm+lFalse*rTrue + lTrue*rFalse + lFalse*rFalse;
			}
		}
	}
	return mm;
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

	string str;
	getline(cin,str);

	cout<<solve(str,0,str.length()-1,true);

	return 0;
}