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
    int x, y;
};
// declare any functions
int square(int x){
    return x*x;
}
int main()
{
    int N; int least_C;
    p field[2001];
    int dist[2001];
    
    cin >> N >> least_C;
    for (int i=1; i<=N; i++){
        cin >> field[i].x >> field[i].y;
    }
    
    int k=1;
    int ans=0;
    
    fill(dist, dist+N+1, 1000000000);
    //mst
    for (int i=1; i<=(N-1); i++)
    {
        dist[k]=-1;
        
        for (int j=1; j<=N; j++) {
            int current_dist = square(field[k].x-field[j].x)+square(field[k].y-field[j].y);
            if (current_dist >= least_C && current_dist<dist[j]){
                dist[j]=current_dist;
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
        if(k==-1){
            ans=-1;
            break;
        }
        ans+=dist[k];
    }
    cout << ans << endl;
}
