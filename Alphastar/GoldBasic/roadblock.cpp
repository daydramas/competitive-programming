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
int N,M;
//vector<p> edge[10000];
//map<int, map<int, int> > edge;
int edge[101][101];
map<int, int> pre;
int spath_before(){
    int dist[2501];
    bool visited[2501];
    memset(dist,-1,sizeof(int)*(N+1));
    memset(visited,false, sizeof(bool)*(N+1));
    dist[1] = 0;
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
        for(int i=1; i<=N; i++){
            if(edge[in][i]==0) continue;
            int go = i;
            int ndist = dist[in]+edge[in][i];
            if(dist[go]==-1 || ndist<dist[go]){
                pre[go] = in;
                dist[go]=ndist;
            }
        }
    }
    return dist[N];
}
int spath_after(){
    int dist[2501];
    bool visited[2501];
    memset(dist,-1,sizeof(int)*(N+1));
    memset(visited,false, sizeof(bool)*(N+1));
    dist[1] = 0;
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
        for(int i=1; i<=N; i++){
            if(edge[in][i]==0) continue;
            int go = i;
            int ndist = dist[in]+edge[in][i];
            if(dist[go]==-1 || ndist<dist[go]){
                pre[go] = in;
                dist[go]=ndist;
            }
        }
    }
    return dist[N];
}
// declare any functions

int main() {
    // declare any local variables
    
    
    // input
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            edge[i][j]=0;
        }
    }
    for(int i=1; i<=M; i++){
        int a,b,d;
        cin >> a >> b >> d;
        edge[a][b]=d;
        edge[b][a]=d;
    }
    // main
    int ori_dist = spath_before();
    int before = N;
    int current;
    int ans = 0;
    while(true){
        current = pre[before];
        if(current==0) break;
        
        edge[before][current] *=2;
        edge[current][before] *=2;
        ans = max(ans,spath_after()-ori_dist);
        edge[before][current] /=2;
        edge[current][before] /=2;
        
        before = current;
        
    }
    // output
    cout<<ans<<endl;
    return 0;
}
