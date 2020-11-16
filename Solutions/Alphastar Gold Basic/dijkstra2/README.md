# dijkstra2
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
int V, E, S;
vector<Pair> path[50010];
int dist[50010];
bool visited[50010];
// declare any functions
void initialize(){
    cin >> V >> E >> S;
    for(int i=1; i<=E; i++){
        int a,b,d; cin >> a >> b >> d;
        path[a].push_back(Pair(b,d));
        path[b].push_back(Pair(a,d));
    }
}
void spath(int start){
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    
    memset(visited, false, sizeof(bool)*(V+1));
    memset(dist, 0, sizeof(int)*(V+1));
    pq.push(make_pair(0, start));
    
    while(!pq.empty()){
        int i = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if(visited[i]) continue;
        visited[i] = true;
        
        for(int x=0; x<path[i].size(); x++){
            int go = path[i][x].neighbor;
            int ndist = dist[i] + path[i][x].weight;
            if((go!=S and dist[go]==0) || ndist < dist[go]){
                dist[go] = ndist;
                pq.push(make_pair(ndist, go));
            }
        }
        
    }
    for(int i=1; i<=V; i++){
        if(i==S) cout<<"0"<<endl;
        else if (!visited[i]) cout<<"-1"<<endl;
        else cout<<dist[i]<<endl;
    }
}

void print_ans(){
    
}
int main() {
    
    
    // input
    initialize();
    // main
    spath(S);
    // output
    print_ans();
    
    //close
    return 0;
}

```