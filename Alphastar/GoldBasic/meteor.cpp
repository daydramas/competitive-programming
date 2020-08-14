
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

struct p1{
    int x, y, t;
    p1(int x, int y, int t) : x(x), y(y), t(t) {}
};

int main() {
    
    //initialize
    int M;
    int matrix[310][310];
    bool visited[310][310];
    int maxn = 1001;
    
    for(int i=0; i<=301; i++){
        for(int j=0; j<=301; j++){
            matrix[i][j] = maxn;
            visited[i][j] = false;
        }
    }
    
    //input
    cin >> M;
    for(int i=1; i<=M; i++){
        int x, y, t;
        cin >> x >> y >> t;
        
        if (x > 300 || y>300 ) continue;
        matrix[x][y] = min(t, matrix[x][y]);
        if(x > 0) matrix[x-1][y] = min(t, matrix[x-1][y]);
        if(y > 0) matrix[x][y-1] = min(t, matrix[x][y-1]);
        if(x < 301) matrix[x+1][y] = min(t, matrix[x+1][y]);
        if(y < 301) matrix[x][y+1] = min(t, matrix[x][y+1]);
        
    }
    
    // bfs
    queue<p1> qu;
    
    qu.push(p1(0,0,0));
    
    int X[] = {1, 0, -1, 0};
    int Y[] = {0, 1, 0, -1};
    
    int ans = -1;
    visited[0][0] = true;
    
    while(!qu.empty()){
        int i = qu.front().x;
        int j = qu.front().y;
        int t = qu.front().t;
        qu.pop();
        
        
        if(t >= matrix[i][j]) continue;
        else if(matrix[i][j]==maxn){
            ans = t;
            break;
        }
        
        for(int k=0; k<4; k++){
            int x = i+X[k];
            int y = j+Y[k];
            
            if(x<0 || x>301 || y<0 || y>301) continue;
            if(!visited[x][y]){
                visited[x][y]=true;
                qu.push(p1(x,y,t+1));
            }
        }
    }
    
    // output
    cout<<ans<<endl;
    return 0;
}
