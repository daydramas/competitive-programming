# hps
```cpp
//============================================================================
// Name        : cpp_template.cpp
// Author      : Dong Liu
// Website     : dongliu.template.com
//============================================================================

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

// declare any structures

// declare any global variables
int N, K;
int move1[100001];
int dp[100001][21][4];
// declare any functions
bool win(int a, int b){
    if(a==2 and b==1) return true;
    if(a==3 and b==2) return true;
    if(a==1 and b==3) return true;
    return false;
}
void initialize(){
    cin >> N >> K;
    char read_move;
    for(int i=1; i<=N; i++){
        cin >> read_move;
        if(read_move=='H') move1[i] = 3;
        else if (read_move=='S') move1[i] = 2;
        else if (read_move=='P') move1[i] = 1;
    }
    for(int i=1; i<=N; i++){
        for(int j=0; j<=K; j++){
            for(int k=1; k<=3; k++){
                dp[i][j][k] = -1*(N+1);
            }
        }
    }
}
void solve(){
    dp[0][0][1] = dp[0][0][2] = dp[0][0][3] = 0;
    for(int i=0; i<=N; i++){
        for(int j=0; j<=K; j++){
            for(int m=1; m<=3; m++){
                if(win(m, move1[i+1])){
                    if(i+1 <= N) dp[i+1][j][m] = max(dp[i+1][j][m],dp[i][j][m]+1);
                } else {
                    if(i+1 <= N) dp[i+1][j][m] = max(dp[i+1][j][m],dp[i][j][m]);
                }
                for(int n=1; n<=3; n++){
                    if(n==m) continue;
                    if(win(n, move1[i+1])){
                        if(i+1 <= N && j-1 >= 0) dp[i+1][j-1][n] = max(dp[i+1][j-1][n],dp[i][j][m]+1);
                    } else {
                        if(i+1 <= N && j-1 >= 0) dp[i+1][j-1][n] = max(dp[i+1][j-1][n],dp[i][j][m]);
                    }
                }
            }
        }
    }
}
void print_ans(){
    cout<<max(dp[N][0][3],max(dp[N][0][1],dp[N][0][2]));
}
int main() {
    
    // input
    initialize();
    // main
    solve();
    // output
    print_ans();
    
    return 0;
}

```