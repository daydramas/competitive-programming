# diet
```cpp
//============================================================================
// Name        : cpp_change.cpp
// Author      : Dong Liu
// Website     :
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

// declare any structures

// declare any global variables
int N, H, W[501];
bool DP[501][45001];
// declare any functions
int main() {
    // declare any local variables
    
    // fstream
    
    // input
    cin >> H >> N;
    for(int i=1; i<=N; i++) cin >> W[i];
    
    
    // main
    for(int i=1; i<=N; i++){
        for(int j=0; j<=H; j++){
            DP[i][j]=false;
        }
    }
    DP[0][0]=true;
    for(int i=1; i<=N; i++){
        for(int j=0; j<=H; j++){
            if(j-W[i]<0) DP[i][j] = (DP[i][j] || DP[i-1][j]);
            else DP[i][j] = (DP[i-1][j-W[i]] || DP[i][j] || DP[i-1][j]);
        }
    }
    // output
    //    cout<<DP[N][H];
    for(int i=H; i>=0; i--){
        if(DP[N][i]){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}

```