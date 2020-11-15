# change
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
long long V, N, currency[11];
long long dp[1001];
// declare any functions
void initialize(){
    cin >> N >> V;
    for(int i=1; i<=V; i++){
        cin >> currency[i];
    }
    for(int i=1; i<=N; i++) dp[i]=100000000;
}
void solve_dp(){
    dp[0] = 0;
    for(int i=1; i<=V; i++){
        for(int j=0; j<=N; j++){
            if(j+currency[i] <= N) dp[j+currency[i]] = min(dp[j+currency[i]], dp[j]+1);
        }
    }
}
int main() {
    // declare any local variables
    
    initialize();
    solve_dp();
    
    cout<<dp[N]<<endl;
    return 0;
}

```