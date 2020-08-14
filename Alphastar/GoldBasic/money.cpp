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
long long V, N, currency[26];
long long dp[10001];
// declare any functions
void initialize(){
    cin >> V >> N;
    for(int i=1; i<=V; i++){
        cin >> currency[i];
    }
}
void solve_dp(){
    dp[0] = 1;
    for(int i=0; i<=V; i++){
        for(int j=0; j<=N; j++){
            if(i+1 <= V) if (j+currency[i+1] <= N) dp[j+currency[i+1]] += dp[j];
        }
    }
}
int main() {
    // declare any local variables
    
    initialize();
    solve_dp();
    
    cout<<dp[N]<<endl;
    return 0;
}
