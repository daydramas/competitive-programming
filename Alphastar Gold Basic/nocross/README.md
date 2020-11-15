# nocross
```cpp
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
int left1[1001],right1[1001];
int DP[1001][1001];
int ans = 0;
// declare any functions
int connected(int l, int r){
    if(abs(left1[l]-right1[r]) <= 4) return 1;
    return 0;
}
int main() {
    // declare any local variables
    
    // input
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> left1[i];
    }
    for(int j=1; j<=N; j++){
        cin >> right1[j];
    }
    // main
    for(int i=1; i<=N; i++){
        DP[i][1] = connected(i,1);
    }
    for(int i=1; i<=N; i++){
        DP[1][i] = connected(1,i);
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i==1 or j==1) continue;
            DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            DP[i][j] = max(DP[i][j], DP[i-1][j-1]+connected(i,j));
        }
    }
    // output
    cout<<DP[N][N]<<endl;
    return 0;
}

```