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

// declare any functions

int main() {
    // declare any local variables
    int N, DP[50][400];
    // input
    cin >> N;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=(N*(N+1)/2); j++)
            DP[i][j] = 0;
    // main
    DP[0][0] = 1;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=(N*(N+1)/4); j++){
            DP[i][j] += DP[i-1][j] + DP[i-1][j-i];
        }
    }
    // output
    if((N*(N+1)%4)!=0 || DP[N][(N*(N+1)/4)]==0) cout<<"0"<<endl;
    else cout<<DP[N][(N*(N+1)/4)]<<endl;
    return 0;
}
