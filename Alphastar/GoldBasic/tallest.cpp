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
    int s,e;
};
// declare any global variables

// declare any functions

int main() {
    // declare any local variables
    int N,I,H,R;
    int temp[10001];
    map<int, map<int, int> > visited;
    
    cin >> N >> I >> H >> R;
    
    for(int i=1; i<=10000; i++){
        temp[i]=H;
    }
    
    for(int i=1; i<=R; i++){
        int x,y;
        cin >> x >> y;
        if(x>y) swap(x,y);
        if(visited[x][y]) continue;
        visited[x][y]=1;
        if(x+1 > N or y-1<1) continue;
        for(int j=x+1; j<=y-1; j++){
            temp[j] = temp[j]-1;
        }
    }
    // main
    for(int i=1; i<=N; i++){
        cout<<temp[i]<<endl;
    }
    // output
    
    return 0;
}
