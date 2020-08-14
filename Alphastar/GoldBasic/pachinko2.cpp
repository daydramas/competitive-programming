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
int N;
int points[101][101];
int DP[101][101];
// declare any functions
void solve(int i, int j){
    //    cout<<"DP["<<i<<"]["<<j<<"] = "<<DP[i][j]<<endl;
    if(i==N) return;
    DP[i+1][j] = max(DP[i+1][j],DP[i][j]+points[i+1][j]);
    solve(i+1, j);
    DP[i+1][j+1] = max(DP[i+1][j+1],DP[i][j]+points[i+1][j+1]);
    solve(i+1, j+1);
}
int main() {
    // declare any local variables
    
    // input
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=i; j++){
            DP[i][j]=0;
            int read_points;
            cin >> read_points;
            points[i][j] = read_points;
        }
    }
    // main
    DP[1][1] = points[1][1];
    for(int i=2; i<=N; i++){
        for(int j=1; j<=i; j++){
            if(j==1){
                DP[i][j] = DP[i-1][j]+points[i][j];
            } else DP[i][j] = max(DP[i-1][j]+points[i][j],DP[i-1][j-1]+points[i][j]);
        }
    }
    //    solve(1,1);
    // output
    int maxn = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=i; j++){
            maxn = max(maxn, DP[i][j]);
        }
    }
    cout<<maxn<<endl;
    return 0;
}
