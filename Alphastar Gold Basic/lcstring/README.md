# lcstring
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
int dp[1001][1001];
// declare any functions
void initialize(){
    cin >> str1 >> str2;
}
void solve_dp(){
    for(int i=1; i<=str1.size(); i++){
        for(int j=1; j<=str2.size(); j++){
            if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=0;
        }
    }
}
void cout_ans(){
    int maxn = 0;
    for(int i=1; i<=str1.size(); i++){
        for(int j=1; j<=str2.size(); j++){
            maxn = max(maxn, dp[i][j]);
        }
    }
    cout<<maxn<<endl;
}
int main() {
    
    initialize();
    solve_dp();
    cout_ans();
    return 0;
}

```