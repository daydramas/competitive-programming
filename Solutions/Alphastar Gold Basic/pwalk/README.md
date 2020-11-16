# pwalk
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
    long long b,d;
    p(int b, long long d) :b(b),d(d) {}
};
// declare any global variables
int N,Q;
//int edge[1001][1001];
vector<p> edge[1001];

// declare any functions
long long spath(int s,int e){
    long long dist[1001];
    bool visited[1001];
    memset(dist,0,sizeof(long long)*(N+1));
    memset(visited,false,sizeof(bool)*(N+1));
    
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0,s));
    dist[s] = 0;
    
    while(!pq.empty()){
//        int d=pq.top().first;
        int i=pq.top().second;
        pq.pop();
        for(int j=0; j<edge[i].size(); j++){
            long long go = edge[i][j].b;
            long long ndist = dist[i] + edge[i][j].d;
            if(dist[go]==0 || ndist < dist[go]){
                dist[go] = ndist;
                if(!visited[go]) pq.push(make_pair(dist[go], go));
            }
        }
    }
    return dist[e];
}
int main() {
    // declare any local variables
    
    // input
    cin >> N >> Q;
    for(int i=1; i<N; i++){
        int a,b,d;
        cin >> a >> b >> d;
        edge[a].push_back(p(b,d));
        edge[b].push_back(p(a,d));
    }
    int s[Q+1],e[Q+1];
    for(int i=1; i<=Q; i++){
        cin >> s[i] >> e[i];
        cout<<spath(s[i],e[i])<<endl;
    }
    // main
    // output
    
    return 0;
}

```