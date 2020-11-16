# bullcow
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

// declare any functions

int main() {
    // declare any local variables
    int N, K;
    long DP[100001];
    // input
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        DP[i]=0;
    }
    // main
    //    DP[1]=2;
    for(int i=1; i<=N; i++){
        if(i-1 >= 1){
            DP[i] += DP[i-1];
        } else {
            DP[i] += 1;
        }
        if(i-K-1 >= 1){
            DP[i] += DP[i-K-1];
        } else {
            DP[i] += 1;
        }
        DP[i] %= 5000011;
    }
    // output
    cout << DP[N]<<endl;
    return 0;
}

```