# hideseek
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

// declare any global variables
int N; int M;
vector<int> path[20001]; int read_f, read_g;
bool visited[20001];
int dist[20001];
// declare any functions
void initialize(){
    cin >> N >> M;
    for(int i=1; i<=M; i++){
        cin >> read_f >> read_g;
        path[read_f].push_back(read_g);
        path[read_g].push_back(read_f);
    }
    for(int i=1; i<=N; i++){
        visited[i] = false;
        dist[i] = N+1;
    }
}
void solve(){
    queue<int> barn; barn.push(1);
    dist[1] = 0; visited[1] = true;
    
    while(!barn.empty()){
        int i = barn.front();
        barn.pop();
        
        for(int j=0; j<path[i].size(); j++){
            int x = path[i][j]; int ndist = dist[i]+1;
            if(ndist < dist[x]){
                dist[x] = ndist;
                if(!visited[x]){
                    visited[x] = true;
                    barn.push(x);
                }
            }
        }
    }
}
void print_ans(){
    int max_path = 0; int min_barn; int max_barns;
    max_barns = -1; min_barn = -1;
    for(int i=1; i<=N; i++){
        if(dist[i] != (N+1)){
            if(dist[i] > max_path){
                max_path = dist[i];
                min_barn = i;
                max_barns = 1;
            } else if (dist[i] == max_path){
                max_barns++;
            }
        }
    }
    cout<<min_barn<<" "<<max_path<<" "<<max_barns<<endl;
}
int main() {
    
    
    // input
    initialize();
    // main
    solve();
    // output
    print_ans();
    
    //close
    return 0;
}

```