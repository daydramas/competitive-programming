# coaster
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
struct piece{
    int x, w, f, c;
    piece(int x, int w, int f, int c) : x(x), w(w), f(f), c(c) {}
};
struct waytosort {
    bool operator() (piece i, piece j) {
        if(i.x!=j.x)return (i.x<j.x);
        return i.w < j.w;
    }
} waytosort;

// declare any global variables
int L, N, B;
vector<piece> component;
int dp[1001][1001];
// declare any functions
void initialize(){
    cin >> L >> N >> B;
    for(int i=0; i<N; i++){
        int x, w, f, c; cin >> x >> w >> f >> c;
        component.push_back(piece(x,w,f,c));
    }
    sort(component.begin(), component.end(), waytosort);
    for(int i=0; i<=L; i++){
        for(int j=0; j<=B; j++){
            dp[i][j]=-100000000;
        }
    }
}
void solve(){
    dp[0][0]=0;
    for(int i=0; i<N; i++){
        int start = component[i].x;
        int width = component[i].w;
        int fun = component[i].f;
        int cost = component[i].c;
        //        cout<<start<<" "<<width<<" "<<fun<<" "<<cost<<endl;
        for(int x=0; x<=B; x++){
            if(cost > x) continue;
            //            cout<<"dp["<<start+width<<"]["<<x<<"] = max("<<dp[start+width][x]<<", "<<dp[start][x-cost]+fun<<") = "<< max(dp[start+width][x], dp[start][x-cost]+fun)<<endl;
            dp[start+width][x] = max(dp[start+width][x], dp[start][x-cost]+fun);
        }
    }
}
void print_ans(){
    int ans = 0;
    for(int j=0; j<=B; j++){
        ans = max(ans, dp[L][j]);
    }
    if(ans==0) cout<<"-1";
    else cout<<ans<<endl;
}
int main() {
    
    
    // input
    initialize();
    // main
    solve();
    // output
    print_ans();
    return 0;
}

```