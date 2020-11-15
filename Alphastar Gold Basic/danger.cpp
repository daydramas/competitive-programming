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
    int N,M;
    int fm[101][101];
    vector<int> path;
    // fstream
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            fm[i][j]=1000000000;
        }
    }
    for(int i=1; i<=M; i++){
        int a;
        cin >> a;
        path.push_back(a);
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int d;
            cin >> d;
            fm[i][j]=d;
        }
    }
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                fm[i][j]=min(fm[i][j],fm[i][k]+fm[k][j]);
            }
        }
    }
    int ans = 0;
    for(int i=0; i<(M-1); i++){
        ans += fm[path[i]][path[i+1]];
    }
    // main
    cout<<ans<<endl;
    // output
    
    return 0;
}
