//============================================================================
// Name        : cpp_change.cpp
// Author      : Dong Liu
// Website     :
//============================================================================

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

// declare any structures

// declare any global variables
int N; int condition[101];
int dp[101];
// declare any functions
void initialize(){
	cin >> N;
	for(int i=1; i<=N; i++) cin >> condition[i];
//	for(int i=1; i<=N; i++)  // max value
}
void solve_dp(){
	dp[0] = 0;
	for(int i=0; i<N; i++){
		if(i==0){
			if(condition[i+1]!=0) dp[1] = 0;
			else dp[1]=1;
		}
		else {
			if(condition[i]==condition[i+1] && (condition[i]==1 or condition[i]==2)){
//				cout<<"dp["<<i+1<<"] adding1 "<<dp[i]+1<<endl;
				dp[i+1] = dp[i]+1;
			} else if (condition[i+1]==0){
				dp[i+1] = dp[i]+1;
//				cout<<"dp["<<i+1<<"] adding2 "<<dp[i]+1<<endl;
			} else if (condition[i]==3 && (i-1>=1 and i <= N and ((condition[i-1]==1 && condition[i+1]==2)||(condition[i-1]==2 and condition[i+1]==1)))){
				dp[i+1] = dp[i]+1;
//				cout<<"dp["<<i+1<<"] adding3 "<<dp[i]+1<<endl;
			}  else{
				dp[i+1] = dp[i];
//				cout<<"dp["<<i+1<<"] adding4 "<<dp[i]<<endl;
			}
		}
//		cout<<"dp["<<i+1<<"] = "<<dp[i+1]<<endl;
	}
}
int main() {
	// declare any local variables

	initialize();

	solve_dp();

	// output
	cout<<dp[N]<<endl;
	return 0;
}
