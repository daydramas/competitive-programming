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
int V, E;
vector<Pair> path[50001]; int read_e, read_s, read_w;
bool visited[50001];
// declare any functions
void initialize(){
    cin >> V >> E;
    for(int i=1; i<=E; i++){
        cin >> read_s >> read_e >> read_w;
        path[read_s].push_back(Pair(read_e, read_w));
        path[read_e].push_back(Pair(read_s, read_w));
    }
    for(int i=1; i<=V; i++) visited[i] = false;
}
void solve(){
    int ans = 0;
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    pq.push(make_pair(0, 1));
    while(!pq.empty()){
        int i = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if(visited[i]) continue;
        visited[i] = true;
        ans += d;
        
        for(int j=0; j<path[i].size(); j++){
            int x = path[i][j].neighbor;
            int ndist = path[i][j].weight;
            pq.push(make_pair(ndist, x));
        }
    }
    cout<<ans<<endl;
}
void print_ans(){
    
}
int main() {
    
    
    // input
    initialize();
    // main
    solve();
    // output
    
    //close
    return 0;
}
