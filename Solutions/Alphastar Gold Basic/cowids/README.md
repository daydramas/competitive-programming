# cowids
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
#include <math.h>
using namespace std;

// declare any structures

// declare any global variables
struct point{
    int zero, r;
    point (int zero, int r) : zero(zero), r(r) {}
};
// declare any functions
point intlog(int K, int N) {
    int timestimes = 0;
    int times = 1;
    while(true){
        if(N<=times){
            return point(timestimes, times-N+1);
            break;
        }
        times *= K;
        timestimes++;
    }
}
int main() {
    // declare any local variables
    int N, K;
    
    // input
    cin >> N >> K;
    // main
    if(K==1){
        cout<<"1";
        for(int i=2; i<=N; i++){
            cout<<"0";
        }
        cout<<endl;
        return 0;
    }
    point temp = intlog(K,N);
    
    int num_of_0 = temp.zero;
    //    cout<<num_of_0<<" "<<remainder<<" ";
    
    int sizeofans = num_of_0+K;
    int DP[5010][K+10];
    for(int i=0; i<=sizeofans+5; i++){
        for(int j=0; j<=K; j++){
            DP[i][j] = 0;
        }
    }
    DP[0][0] = 1;
    for(int i=1; i<=5000; i++){
        for(int j=0; j<=K; j++){
            if(j-1 < 0) DP[i][j] = DP[i-1][j];
            else DP[i][j] = DP[i-1][j-1] + DP[i-1][j];
        }
    }
    int current_K = K;
    int current_N = N;
    int N_i = 6000;
    int printed = 0;
    vector<char> ans;
    while(true){
        for(int i=1; i<=5000; i++){
            
            if(DP[i][current_K]>=current_N){
                if(N_i==6000){
                    sizeofans = i;
                } else {
                    for(int j=i+1; j<N_i; j++){
                        cout<<"0";
                        printed++;
                    }
                }
                N_i = i;
                cout<<"1";
                printed++;
                current_N -= DP[i-1][current_K];
                break;
            }
        }
        current_K--;
        if(current_K==0){
            for(int i=printed+1; i<=sizeofans; i++){
                cout<<"0";
            }
            break;
        }
    }
    // output
    return 0;
}


```