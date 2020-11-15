# tractor
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
#include <deque>
#include <algorithm>
using namespace std;

struct p{
    int x,y,b;
    p(int x, int y, int b) : x(x), y(y), b(b) {}
};
// declare any structures

// declare any global variables

// declare any functions


int main() {
    // declare any local variables
    int N; int tx, ty;
    //    map<int, map<int, int> > field;
    int field[1010][1010];
    //    map<int, map<int, int> > visited;
    bool visited[1010][1010];
    int bx,by;
    bx=by=1001;
    
    for(int i=1; i<=1000; i++){
        for(int j=1; j<=1000; j++){
            field[i][j] = 0;
            visited[i][j] = false;
        }
    }
    
    // input
    cin >> N >> tx >> ty;
    for(int i=1; i<=N; i++){
        int x,y;
        cin >> x >> y;
        field[x][y] = 1;
        if(bx!=1000)bx = max(bx,x+1);
        if(by!=1000)by = max(by,y+1);
    }
    
    deque<p> myde;
    
    myde.push_front(p(tx,ty,0));
    
    
    int X[] = {-1,0,1,0};
    int Y[] = {0,-1,0,1};
    while(!myde.empty()){
        
        int i=myde.front().x;
        int j=myde.front().y;
        int b=myde.front().b;
        //        cout<<i<<" "<<j<<" "<<b<<endl;
        myde.pop_front();
        
        if(visited[i][j]==1) continue;
        
        visited[i][j] = 1;
        
        if(i==0 || j==0){
            cout<<b<<endl;
            break;
        }
        for(int k=0; k<4; k++){
            int x = i+X[k];
            int y = j+Y[k];
            if(visited[x][y]==0 && x>=0 && x<=bx && y>=0 && y<=by){
                if(field[x][y]==1) myde.push_back(p(x,y,b+1));
                else myde.push_front(p(x,y,b));
            }
        }
        
    }
    
    
    // main
    // output
    
    return 0;
}

```