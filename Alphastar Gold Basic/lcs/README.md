# lcs
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
string str1, str2;
int dp[2][10001];
// declare any functions
void initialize(){
    cin >> str1 >> str2;
}
void solve_dp(){
    for(int i=1; i<=str1.size(); i++){
        for(int j=1; j<=str2.size(); j++){
            if(str1[i-1]==str2[j-1]) dp[1][j] = dp[0][j-1]+1;
            else dp[1][j]= max(dp[0][j],dp[1][j-1]);
        }
        swap(dp[0],dp[1]);
    }
}
int main() {
    // declare any local variables
    initialize();
    solve_dp();
    cout<<dp[0][str2.size()];
    // output
    
    return 0;
}

```