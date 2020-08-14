/*
 ============================================================================
 Name        : cpp_template.cpp
 Author      : Dong Liu
 Website     : dongliu.template.com
 ============================================================================
 */
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

//declare any structures
#define MAXN 1000001
#define Pair pair<int, int>
struct node {
    int x, y;
    node(int x, int y) : x(x), y(y) {}
} ;

//declare any global variables
int N;
int x[100], y[100];
int converter[100];
set<pair<int, int> > points;
vector<node> nodes;
vector<int> directPath[500];

//declare any functions
int distance(int a, int b) { return abs(nodes[a].x-nodes[b].x)+abs(nodes[a].y-nodes[b].y); }
bool isNotBlockedByFarm(int i, int j){ for(int k=0; k<N; k++){ if(x[k]==i and y[k]==j){ return false; } } return true; }
bool blocked_by_node(int x1, int y1, int x2, int y2, int x3, int y3){ return (x2==x3 && (x1 == x2 && y1 > min(y2, y3) && y1 < max(y2, y3))) || (y1==y2&&(y1 == y2 && x1 > min(x2, x3) && x1 < max(x2, x3))); }
bool isValid(int i, int j) { return (i >= 1 and i <= MAXN-1 and j >= 1 and j <= MAXN-1); }
bool isDestination(int i, int j, Pair dest){ return (i==dest.first && j==dest.second); }

bool route_possible(int a, int b){
    bool return1, return2;
    if(nodes[a].x == nodes[b].x or nodes[a].y == nodes[b].y or isNotBlockedByFarm(nodes[a].x, nodes[b].y)) return1 = true;
    else return1 = false;
    for(int i = 0; i < N; i++){
        if(blocked_by_node(x[i], y[i], nodes[a].x, nodes[a].y, nodes[a].x, nodes[b].y) || blocked_by_node(x[i], y[i], nodes[a].x, nodes[b].y, nodes[b].x, nodes[b].y)){
            return1 = false;
            break;
        }
    }
    if(nodes[a].x == nodes[b].x or nodes[a].y == nodes[b].y or isNotBlockedByFarm(nodes[b].x, nodes[a].y)){
        return2 = true;
    } else return2 = false;
    
    for(int i = 0; i < N; i++){
        if(blocked_by_node(x[i], y[i], nodes[a].x, nodes[a].y, nodes[b].x, nodes[a].y) || blocked_by_node(x[i], y[i], nodes[b].x, nodes[a].y, nodes[b].x, nodes[b].y)){
            return2 = false;
            break;
        }
    }
    
    return (return1 || return2);
}

bool visited[500];
int dist[500];
int solve(int a, int b) {
    fill(dist, dist+nodes.size(), 1000000000);
    memset(visited, false, sizeof(visited));
    
    for(int i = 0; i < N; i++) if(converter[i] != a && converter[i] != b) visited[converter[i]] = true;
    
    dist[a] = 0;
    for(int i = 0; i < nodes.size(); i++){
        int next = 0;
        for(int j = 0; j < nodes.size(); j++){
            if(!visited[j] && (dist[j] < dist[next] || visited[next])) next = j;
        }
        if(visited[next] || dist[next] == 1000000000) return -1;
        
        if(next == b) return dist[b];
        
        visited[next] = true;
        for(int j = 0; j < directPath[next].size(); j++){
            if(!visited[directPath[next][j]]) dist[directPath[next][j]] = min(dist[directPath[next][j]], dist[next] + distance(next, directPath[next][j]));
        }
    }
    return -1;
}
void initialize(){
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
        points.insert(make_pair(x[i], y[i]));
    }
    int X[] = {0,1,0,-1,0};
    int Y[] = {0,0,1,0,-1};
    
    for(int i = 0; i < N; i++){
        for(int j=0; j<=4; j++){
            if(X[j] == 0 && Y[j] == 0) {
                nodes.push_back(node(x[i], y[i]));
                converter[i] = nodes.size()-1;
            }
            else if((X[j]==0 or Y[j]==0) && isNotBlockedByFarm(x[i]+X[j],y[i]+Y[j])) nodes.push_back(node(x[i]+X[j],y[i]+Y[j]));
        }
    }
}
void solve(){
    for(int i = 0; i < nodes.size(); i++){
        for(int j = i+1; j<nodes.size(); j++){
            if(route_possible(i, j)){
                directPath[i].push_back(j);
                directPath[j].push_back(i);
            }
        }
    }
}
int solve4ans(int i){
    if(i==N-1) return 0;
    else return i+1;
}
int print_ans(){
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int current_minutes = solve(converter[i], converter[solve4ans(i)]);
        //        cout<<i<<" m: "<<current_minutes<<endl;
        if(current_minutes == -1) {
            return -1;
            break;
        } else ans += current_minutes;
    }
    return ans;
}
int main(){
    //input
    initialize();
    //main
    solve();
    //fout
    cout<< print_ans() <<endl;
    
    //close
    return 0;
}
