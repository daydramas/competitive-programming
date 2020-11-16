# daisy
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
    int N, M;
    vector <int> path[251];
    bool visited[251];
    
    // input
    cin >> N >> M;
    memset(visited, false, sizeof(bool)*(N+1));
    for(int i=1; i<=M; i++){
        int a,b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    // main
    queue<int> bfs;
    bfs.push(1);
    visited[1] = true;
    
    while(!bfs.empty()){
        int i=bfs.front();
        bfs.pop();
        
        for(int j=0; j<path[i].size(); j++){
            if(!visited[path[i][j]]){
                bfs.push(path[i][j]);
                //                cout<<i<<" -> "<<path[i][j]<<endl;
                visited[path[i][j]]=true;
            }
        }
    }
    // output
    bool zero = true;
    for(int i=1; i<=N; i++){
        if(!visited[i]){
            zero = false;
            cout<<i<<endl;
        }
    }
    if(zero) cout<<"0"<<endl;
    return 0;
}

```