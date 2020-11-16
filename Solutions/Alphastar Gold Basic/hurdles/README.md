# hurdles
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
struct p{
    int b,d;
    p(int b, int d) : b(b),d(d) {}
};
// declare any global variables

// declare any functions


int main() {
    // declare any local variables
    int N,M,T;
    int path[301][301];
    // input
    
    cin >> N >> M >> T;
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            path[k][i]=1000000001;
        }
    }
    for(int i=1; i<=M; i++){
        int a,b,d;
        cin >> a >> b >> d;
        path[a][b]=d;
    }
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                path[i][j]=min(path[i][j],max(path[i][k],path[k][j]));
            }
        }
    }
    for(int i=1; i<=T; i++){
        int f,g;
        cin >> f >> g;
        if(path[f][g]==1000000001){
            cout<<"-1"<<endl;
        }
        else cout<<path[f][g]<<endl;
    }
    // main
    
    // output
    
    return 0;
}

```