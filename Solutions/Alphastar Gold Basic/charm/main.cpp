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
struct point{
    int t, p;
    point(int t, int p) : t(t),p(p) {}
};

// declare any global variables
long t[3403],p[3403];
long dp[2][12881];
long max0(long a, long b){
    if(a>b) return a;
    return b;
}
int main() {
    // declare any local variables
    int N,C;
    
    // input
    cin >> N >> C;
    for(int i=1; i<=N; i++){
        cin >> t[i] >> p[i];
    }
    // main
    
    for(int i=1; i<=N; i++){
        for(int j=0; j<=C; j++){
            if(j-t[i] < 0) dp[1][j] = dp[0][j];
            else dp[1][j] = max0(dp[0][j-t[i]]+p[i],dp[0][j]);
        }
        swap(dp[1],dp[0]);
    }
    // output
    cout<<dp[0][C];
    return 0;
}
