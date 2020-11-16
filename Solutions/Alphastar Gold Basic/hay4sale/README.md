# hay4sale
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
int C, H;
int V[5001]; bool DP[2][50001];
// declare any functions
void initialize(){
    cin >> C >> H;
    for(int i=1; i<=H; i++) cin >> V[i];
    for(int i=0; i<=C; i++) DP[0][i] = DP[1][i] = false;
}
void solve_DP(){
    DP[0][0] = true;
    for(int i=1; i<=H; i++){
        for(int j=0; j<=C; j++){
            if(j-V[i]<0) DP[1][j] = (DP[1][j] || DP[0][j]);
            else DP[1][j] = (DP[0][j-V[i]] || DP[1][j] || DP[0][j]);
        }
        for(int j=0; j<=C; j++){
            DP[0][j] = DP[1][j];
            DP[1][j] = false;
        }
    }
}
void cout_ans(){
    for(int i=C; i>=0; i--){
        if(DP[0][i]){
            cout<<i<<endl;
            break;
        }
    }
}
int main() {
    // declare any local variables
    
    initialize();
    solve_DP();
    cout_ans();
    
    return 0;
}

```