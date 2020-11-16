# marathon
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
int N, K;
int x[501], y[501];
// declare any functions


int dist_between (int i, int j){
    return abs(x[i]-x[j])+abs(y[i]-y[j]);
}

int main() {
    // declare any local variables
    
    // input
    cin >> N >> K;
    for(int i=1; i<=N; i++) cin >> x[i] >> y[i];
    
    // main
    int DP[501][501];
    for(int i=0; i<=K; i++){
        for(int j=1; j<=N; j++){
            DP[i][j] = 1000000000;
        }
    }
    
    DP[0][1] = 0;
    for(int i=0; i<=K; i++){
        for(int j=1; j<=N; j++){
            for(int l=j+1; l<=N && (i-j+l-1)<=K; l++){
                int X = i-j+l-1;
                int Y = l;
                DP[X][Y] = min(DP[X][Y], DP[i][j]+dist_between(j, l));
                //                cout<<"DP["<<X<<"]["<<Y<<"] = "<<DP[X][Y]<<endl;
            }
        }
    }
    // output
    cout<<DP[K][N];
    return 0;
}

```