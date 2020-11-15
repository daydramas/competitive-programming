# checklist
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
int H, G, hx[1001], hy[1001], gx[1001], gy[1001];
long long dp[1001][1001][2];
// declare any functions
void initialize(){
    cin >> H >> G;
    for(int i=0; i<H; i++) cin >> hx[i] >> hy[i];
    for(int i=0; i<G; i++) cin >> gx[i] >> gy[i];
    for(int i=0; i<=H; i++){
        for(int j=0; j<=G; j++){
            for(int k=0; k<=1; k++){
                dp[i][j][k] = 100000000000;
            }
        }
    }
}
int square (int x){
    return (x*x);
}
int dist(int x1, int y1, int x2, int y2){
    return square(abs(x2-x1))+square(abs(y2-y1));
}
void solve(){
    
    dp[1][0][0]=0;
    for(int i=0; i<=H; i++){
        for(int j=0; j<=G; j++){
            for(int k=0; k<=1; k++){
                if(k == 0 && i == 0) continue;
                if(k == 1 && j == 0) continue;
                
                int fx, fy;
                if(k==0){
                    fx=hx[i-1]; fy=hy[i-1];
                } else if (k==1){
                    fx=gx[j-1]; fy=gy[j-1];
                }
                if(i<H){
                    dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][k] + dist(hx[i],hy[i],fx,fy));
                }
                if(j<G){
                    dp[i][j+1][1] = min(dp[i][j+1][1], dp[i][j][k] + dist(gx[j],gy[j],fx,fy));
                }
            }
        }
    }
    
}
void print_ans(){
    cout<<dp[H][G][0]<<endl;
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