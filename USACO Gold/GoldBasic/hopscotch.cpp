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
    int N, M, K;
    int matrix[101][101];
    int DP[101][101];
    
    // input
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> matrix[i][j];
            DP[i][j] = 0;
        }
    }
    // main
    DP[1][1] = 1;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            for(int x=i+1; x<=N; x++){
                for(int y=j+1; y<=M; y++){
                    if(matrix[i][j]!=matrix[x][y]){
                        DP[x][y] += DP[i][j];
                        DP[x][y] %= 1000000007;
                    }
                }
            }
        }
    }
    // output
    cout<<DP[N][M];
    
    return 0;
}
