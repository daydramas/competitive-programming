# catchcow
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

struct p{
    int x, t;
    p(int x, int t) : x(x), t(t) {}
};

int main() {
    
    int N, K;
    cin >> N >> K;
    
    queue<p> qu;
    qu.push(p(N,0));
    map<int, int> visited;
    
    int far_right = 2*K;
    
    while(!qu.empty()){
        
        int i = qu.front().x;
        int t = qu.front().t;
        visited[i] = 1;
        
        //        cout<<i<<" time "<<t<<endl;
        if(i==K){
            cout<<t<<endl;
            break;
        }
        
        far_right = max(far_right, i);
        
        if(i-1>=0 && visited[i-1]==0) qu.push(p(i-1,t+1));
        if(i+1<=100000 and (i+1)<(far_right) && visited[i+1]==0) qu.push(p(i+1,t+1));
        if(i*2<=100000 and (i*2)<(far_right) && visited[i*2]==0) qu.push(p(i*2,t+1));
        qu.pop();
    }
    return 0;
}

```