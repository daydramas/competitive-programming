# egroup
```cpp
//============================================================================
// Name        : cpp_template.cpp
// Author      : Dong Liu
// Website     : dongliu.template.com
//============================================================================

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

// declare any structures

// declare any global variables
int N;
int cards[30001], ncards[30001];
int dp[30001][4], dp1[30001][4];
// declare any functions
void initialize(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> cards[i];
    }
    
}
void solve(){
    for(int j=1; j<=3; j++){
        for(int i=1; i<=N; i++){
            if(j==1) dp[i][1] = dp[i-1][1] + (cards[i]!=1);
            else if (j==2) dp[i][2]=min(dp[i-1][1], dp[i-1][2])+(cards[i]!=2);
            else if (j==3) dp[i][3]=min(dp[i-1][3], min(dp[i-1][1], dp[i-1][2]))+(cards[i]!=3);
            //            cout<<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<endl;
        }
    }
    
    for(int j=3; j>=1; j--){
        for(int i=1; i<=N; i++){
            if(j==1) dp1[i][1] = min(dp1[i-1][3], min(dp1[i-1][1], dp1[i-1][2])) + (cards[i]!=1);
            else if (j==2) dp1[i][2]=min(dp1[i-1][3], dp1[i-1][2])+(cards[i]!=2);
            else if (j==3) dp1[i][3]=dp1[i-1][3]+(cards[i]!=3);
            //            cout<<"dp["<<i<<"]["<<j<<"] = "<<dp1[i][j]<<endl;
        }
    }
}
void print_ans(){
    cout<<min(min(dp[N][1], min(dp[N][3], dp[N][2])),min(dp1[N][1], min(dp1[N][3], dp1[N][2])));
}
int main() {
    
    // fstream
    
    // input
    initialize();
    // main
    solve();
    // output
    print_ans();
    
    //close
    return 0;
}

```