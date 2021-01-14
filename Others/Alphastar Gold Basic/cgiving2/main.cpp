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
    p(int b, int d) :b(b),d(d) {}
};
// declare any global variables

// declare any functions

int main() {
    // declare any local variables
    int N, start, E;
    map<int, vector<p> > edge;
    // fstream
    
    // input
    cin >> N >> E >> start;
    for(int i=1; i<=E; i++){
        int a,b,d;
        cin >> a >> b >> d;
        edge[a].push_back(p(b,d));
        edge[b].push_back(p(a,d));
    }
    
    // main
    int dist[2501];
    bool visited[2501];
    memset(dist,-1,sizeof(int)*(N+1));
    memset(visited,false, sizeof(bool)*(N+1));
    dist[start] = 0;
    while(true){
        int in = -1;
        for(int i=1; i<=N; i++){
            if(dist[i] != -1){
                if(!visited[i]&&(in == -1 or dist[i]<dist[in])){
                    in=i;
                }
            }
        }
        if(in==-1) break;
        visited[in] = true;
        for(int i=0; i<edge[in].size(); i++){
            int go = edge[in][i].b;
            int ndist = dist[in]+edge[in][i].d;
            if(dist[go]==-1 || ndist<dist[go]){
                dist[go]=ndist;
            }
        }
    }
    // output
    for(int i=1; i<=N; i++){
        cout<<dist[i]<<endl;
    }
    return 0;
}
