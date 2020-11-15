# buyhay
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
#define MAXN_N 101

// declare any global variables
int N, H;
int P[MAXN_N], C[MAXN_N];
int DP[60001];
int maxn = 0;
int max_p = 0;
// declare any functions
void initialize(){
    cin >> N >> H;
    for(int i=1; i<=N; i++){
        cin >> P[i] >> C[i];
        max_p = max(max_p, P[i]);
    }
    for(int i=1; i<=H+max_p; i++) DP[i] = 500001;
}
void solve_DP(){
    DP[0] = 0;
    for(int i=1; i<=N; i++){
        for(int j=0; j<=H; j++){
            //            if(j+P[i] <= H){
            DP[j+P[i]] = min(DP[j+P[i]], DP[j]+C[i]);
            //            }
        }
    }
}
int main() {
    
    //code here
    initialize();
    solve_DP();
    // output
    int ans = 500001;
    for(int i=H; i<=H+max_p; i++){
        ans = min(ans, DP[i]);
    }
    cout<<ans<<endl;
    return 0;
}

```