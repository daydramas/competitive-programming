# agrinet
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

// declare any functions

int main()
{
    int N;
    int dist[101];
    int path[101][101];
    
    cin >> N;
    for (int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int temp_d;
            cin >> temp_d;
            path[i][j]=temp_d;
        }
    }
    
    int k=1;
    int ans=0;
    
    fill(dist, dist+N+1, 1000000000);
    //mst
    for (int i=1; i<=(N-1); i++)
    {
        dist[k]=-1;
        
        for (int j=1; j<=N; j++) {
            if (path[k][j]<dist[j]){
                dist[j]=path[k][j];
            }
        }
        k=-1;
        for (int j=1; j<=N; j++){
            if (dist[j]!=-1 && dist[j]!=1000000000){
                if (k==-1 || dist[j]<dist[k]){
                    k=j;
                }
            }
        }
        ans+=dist[k];
    }
    cout << ans << endl;
}

```