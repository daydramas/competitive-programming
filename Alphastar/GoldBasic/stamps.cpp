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
int K, N, stamp[51];
int dp[2000010];
int maxn = 0;
int total = 0;
// declare any functions
void initialize(){
    cin >> K >> N;
    for(int i=1; i<=N; i++){
        cin >> stamp[i];
        total = max(total, stamp[i]);
    }
    total *= K;
    for(int j=0; j<=total; j++) dp[j]=201;
}
void solve_dp(){
    dp[0] = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<=total; j++){
            if(dp[j]+1 <= K)
                dp[j+stamp[i+1]] = min(dp[j+stamp[i+1]], dp[j]+1);
        }
    }
}
int main() {
    // declare any local variables
    
    initialize();
    solve_dp();
    
    int max_s = 0;
    int streak = 0;
    for(int i=1; i<=total; i++){
        if(dp[i] <= K){
            streak++;
            max_s = max(max_s, streak);
        } else{
            streak = 0;
        }
    }
    cout<<max_s<<endl;
    return 0;
}
