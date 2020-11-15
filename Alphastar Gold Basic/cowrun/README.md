# cowrun
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
int N, M;
int dist[10001];
int dp[2][501][2];
//map<int, map<int, map<int, int> > > dp;
// declare any functions
void initialize(){
    cin >> N >> M;
    for(int i=1; i<=N; i++) cin >> dist[i];
}
void solve(){
    for(int i=1; i<=N; i++){
        for(int j=0; j<=M; j++){
            for(int k=0; k<2; k++){
                if(k==0){
                    if(i-1 >= 1 and j+1 <= M){
                        dp[1][j][0] = max(dp[0][j+1][0], dp[0][j+1][1]);
                    }
                    if(j==0){
                        dp[1][j][0] = max(dp[1][j][0],dp[0][j][0]);
                    }
                } else if (k==1){
                    if(i-1 >=1 and j-1 >= 0){
                        dp[1][j][1] = dp[0][j-1][1]+dist[i];
                    }
                    if(j==1){
                        dp[1][j][1] = max(dp[1][j][1], dp[0][j-1][0]+dist[i]);
                    }
                }
            }
        }
        //        swap(dp[1],dp[0]);
        for(int j=0; j<=M; j++){
            for(int k=0; k<2; k++){
                dp[0][j][k]=dp[1][j][k];
                dp[1][j][k]=0;
            }
        }
    }
}
void print_ans(){
    cout<< dp[0][0][0];
}
int main() {
    
    // input
    initialize();
    // main
    solve();
    // output
    print_ans();
    
    //close
    return 0;
}

```