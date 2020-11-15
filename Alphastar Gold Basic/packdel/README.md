# packdel
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
int N, M;
vector<Pair> path[50001];
int dist[50001]; bool visited[50001];
// declare any functions
void initialize(){
    cin >> N >> M;
    for(int i=1; i<=M; i++){
        int a, b, d; cin >> a >> b >> d;
        path[a].push_back(Pair(b,d));
        path[b].push_back(Pair(a,d));
    }
}
void spath (int from){
    
    memset(dist,-1,sizeof(int)*(N+1));
    memset(visited,false, sizeof(bool)*(N+1));
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    pq.push(make_pair(0, from));
    dist[from] = 0;
    while(!pq.empty()){
        int in = pq.top().second;
        pq.pop();
        
        if(visited[in]) continue;
        visited[in] = true;
        for(int i=0; i<path[in].size(); i++){
            int go = path[in][i].neighbor;
            int ndist = dist[in]+path[in][i].weight;
            if(dist[go]==-1 || ndist<dist[go]){
                dist[go]=ndist;
                pq.push(make_pair(ndist, go));
            }
        }
    }
}
void print_ans(){
    cout<<dist[N]<<endl;
}
int main() {
    
    // input
    initialize();
    // main
    spath(1);
    // output
    print_ans();
    
    //close
    return 0;
}

```