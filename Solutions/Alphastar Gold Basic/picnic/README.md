# picnic
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
#define pi pair<int, int>
struct Pair{
    int neighbor, weight;
    Pair(int neighbor, int weight) : neighbor(neighbor), weight(weight) {}
};
// declare any global variables
//int V, E;
int K, N, M;
vector<int> path[50001]; int read_e, read_s, read_w;
bool visited[50001];
vector<int> loc;
// declare any functions
void initialize(){
    cin >> K >> N >> M;
    for(int i=1; i<=K; i++){
        int r; cin >> r;
        loc.push_back(r);
    }
    for(int i=1; i<=M; i++){
        cin >> read_s >> read_e;
        path[read_e].push_back(read_s);
    }
}
bool solve(int start){
    //    priority_queue<int, vector<int>, greater<int> > pq;
    queue<int> qu;
    qu.push(start);
    memset(visited, false, sizeof(bool)*(N+1));
    visited[start] = true;
    while(!qu.empty()){
        int i = qu.front();
        qu.pop();
        
        for(int j=0; j<path[i].size(); j++){
            int x = path[i][j];
            if(!visited[x]){
                qu.push(x);
                visited[x] = true;
            }
        }
    }
    
    bool returnb = true;
    for(int i=0; i<K; i++){
        if(!visited[loc[i]]){
            returnb = false;
            break;
        }
    }
    return returnb;
}
void print_ans(){
    
}
int main() {
    
    
    // input
    initialize();
    // main
    int ans = 0;
    for(int i=1; i<=N; i++){
        
        if(solve(i)){
            //            cout<<i<<endl;
            ans++;
        }
    }
    // output
    cout<<ans<<endl;
    //close
    return 0;
}

```