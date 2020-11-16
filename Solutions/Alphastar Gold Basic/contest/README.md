# contest
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
struct p{
    int b; bool better;
    p(int b, bool better):b(b),better(better) {}
};
// declare any functions

int main() {
    // declare any local variables
    int N,M;
    map<int, int> times;
    //    int X[4501],Y[4501];
    vector<p> result[101];
    cin >> N >> M;
    for(int i=1; i<=M; i++){
        int x,y;
        cin >> x >> y;
        result[x].push_back(p(y,true));
        result[y].push_back(p(x,false));
    }
    
    // input
    int ans=0;
    bool visited[N+1];
    for(int i=1; i<=N; i++){
        
        queue<int> above;
        memset(visited, false,sizeof(bool)*(N+1));
        int mysmallcounter = -2;
        above.push(i);
        while(!above.empty()){
            int j=above.front();
            above.pop();
            visited[j]=true;
            mysmallcounter++;
            
            for(int k=0; k<result[j].size(); k++){
                if(!result[j][k].better && !visited[result[j][k].b]){
                    visited[result[j][k].b] = true;
                    above.push(result[j][k].b);
                }
            }
        }
        
        queue<int> below;
        memset(visited, false,sizeof(bool)*(N+1));
        below.push(i);
        while(!below.empty()){
            int j=below.front();
            below.pop();
            visited[j]=true;
            mysmallcounter++;
            
            for(int k=0; k<result[j].size(); k++){
                if(result[j][k].better && !visited[result[j][k].b]){
                    visited[result[j][k].b] = true;
                    below.push(result[j][k].b);
                }
            }
        }
        if(mysmallcounter==(N-1)){
            ans++;
        }
    }
    // main
    cout<<ans<<endl;
    // output
    
    return 0;
}


```