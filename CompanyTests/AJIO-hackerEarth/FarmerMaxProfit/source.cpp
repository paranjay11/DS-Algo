/*

One array represnting the profits per village.
INPUT:
1st line -> number of villages
2nd line -> equally spaced numbers equal to the number of villages depicting profits per village

We have to find the max profit when a person goes to all the villages following the below condition
1. A person may only move from village 'i' to village 'j', when i<j , &&
2. the profit in 'jth' village is a multiple of 'ith' village

6
1 2 3 4 9 8 => 15

taking 0,1,3,5 terms i.e. 1+2+4+8=15

*/


#include <bits/stdc++.h>
using namespace std;


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

	return 0;
}