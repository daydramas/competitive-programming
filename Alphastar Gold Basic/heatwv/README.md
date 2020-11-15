# heatwv
```cpp

#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

// declare any structures
typedef pair<int, int> pi;
// declare any global variables
map<int, map<int, int> > edge;
//int edge[2501][2501];
//vector<int> path[2500];
map<int, vector<int> >path;
int N, C; int startt, endt;

// declare any functions

int spath(){
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    bool visited[N+1];
    memset(visited, false, sizeof(bool)*(N+1));
    int dist[N+1];
    memset(dist, -1, sizeof(int)*(N+1));
    
    pq.push(make_pair(0,startt));
    dist[startt]=0;
    while(!pq.empty()){
        int i = pq.top().second;
        //        cout<<"popping "<<i<<endl;
        pq.pop();
        //        int i = -1;
        //        for(int j=1; j<=N; j++){
        //            if(dist[j] != -1 && !visited[j]){
        //                if((i == -1 or dist[j]<dist[i])){
        //                    i=j;
        //                }
        //            }
        //            cout<<"dist["<<j<<"] = "<<dist[j]<<endl;
        //        }
        //        cout<<endl;
        //        if(i==-1) break;
        visited[i] = true;
        
        //        if(dist[endt]!=0 and dist[i] > dist[endt]){
        //            pq.pop();
        //            continue;
        //        }
        for(int x=0; x<path[i].size(); x++){
            int go = path[i][x];
            int ndist = dist[i] + edge[i][go];
            //            cout<<ndist<<" = "<<dist[i]<<" + "<<edge[i][go]<<endl;
            if(dist[go]==-1 || ndist < dist[go]){
                dist[go] = ndist;
                //                cout<<"dist["<<go<<"] = "<<dist[go]<<endl;
                if(!visited[go])pq.push(make_pair(dist[go],go));
            }
        }
    }
    return dist[endt];
}
int main() {
    ifstream fin ("read.in");
    // declare any local variables
    
    // fstream
    cin >> N >> C >> startt >> endt;
    for(int i=1; i<=C; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[a][b] = c;
        edge[b][a] = c;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    // input
    
    // main
    
    // output
    cout<<spath()<<endl;
    return 0;
}

```