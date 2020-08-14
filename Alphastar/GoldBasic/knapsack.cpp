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
long t[1001],p[1001];
long dp[1001][5001];
// declare any functions
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
    
    //    map<long, map<long, long> > dp;
    for(int i=0; i<=N; i++){
        for(int j=0; j<=C; j++){
            dp[i][j]=0;
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=0; j<=C; j++){
            if(j-t[i] < 0) dp[i][j] = max0(dp[i][j],dp[i-1][j]);
            else dp[i][j] = max0(dp[i-1][j-t[i]]+p[i],max0(dp[i][j],dp[i-1][j]));
        }
    }
    // output
    cout<<dp[N][C];
    return 0;
}
