# sed
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
    for(int i=1; i<=str1.size(); i++){
        for(int j=1; j<=str2.size(); j++){
            dp[i][j]=1000000;
        }
    }
    for(int i=1; i<=str1.size(); i++) dp[i][0] = i;
    for(int i=1; i<=str2.size(); i++) dp[0][i] = i;
}
int compare(int a, int b){
    if(str1[a]==str2[b]) return 0;
    return 1;
}
void solve_dp(){
    for(int i=1; i<=str1.size(); i++){
        for(int j=1; j<=str2.size(); j++){
            dp[i][j]=min(min(dp[i-1][j-1]+compare(i-1,j-1),dp[i][j-1]+1),dp[i-1][j]+1);
        }
    }
}
int main() {
    
    initialize();
    solve_dp();
    
    cout<<dp[str1.size()][str2.size()];
    
    return 0;
}

```