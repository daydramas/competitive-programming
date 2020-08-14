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
#include <math.h>
#include <iomanip>
using namespace std;

// declare any structures

// declare any global variables
struct p{
    long long x, y;
};
// declare any functions
long long square(long x){
    return x*x;
}
int main()
{
    int N; int M;
    p field[1001];
    long double dist[1001];
    cin >> N >> M;
    bool connected[N+1][N+1];
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            connected[i][j] = false;
        }
    }
    for(int i=1; i<=N; i++){
        cin >> field[i].x >> field[i].y;
    }
    for (int i=1; i<=M; i++){
        long long x,y;
        cin >> x >> y;
        connected[x][y]=true;
        connected[y][x]=true;
    }
    int k=1;
    long double ans=0;
    bool visited[N+1];
    memset(visited,false,sizeof(bool)*(N+1));
    fill(dist, dist+N+1, 100000000000);
    //mst
    for (int i=1; i<=(N-1); i++)
    {
        //        cout<<"k: "<<k<<endl;
        //        dist[k]=-1;
        visited[k]=true;
        for (int j=1; j<=N; j++) {
            if(connected[k][j]){
                dist[j]=0;
            }
            long double current_dist = sqrt(square(field[k].x-field[j].x)+square(field[k].y-field[j].y));
            if (current_dist<dist[j]){
                dist[j]=current_dist;
            }
            //            cout<<"dist["<<j<<"] = "<<dist[j]<<endl;
        }
        k=-1;
        for (int j=1; j<=N; j++){
            if (!visited[j] && dist[j]!=100000000000){
                if (k==-1 || dist[j]<dist[k]){
                    k=j;
                }
            }
        }
        ans += dist[k];
        //        cout << ans << endl;
        
    }
    
    cout << fixed << setprecision(2) << ans << endl;
}
