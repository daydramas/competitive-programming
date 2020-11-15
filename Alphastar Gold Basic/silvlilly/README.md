# silvlilly
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
struct for_ans{
    int min_lilly, min_jumps, paths;
    for_ans(int min_lilly, int min_jumps, int paths): min_lilly(min_lilly),min_jumps(min_jumps),paths(paths) {}
};
struct for_qu{
    int x, y, lilly, jumps;
    for_qu(int x, int y, int lilly, int jumps) : x(x),y(y),lilly(lilly),jumps(jumps) {}
};
// declare any global variables

// declare any functions

int main() {
    // declare any local variables
    int N; int M;
    int matrix[40][40]; int read;
    int sx=0, sy=0;
    bool visited[40][40];
    int min_lilly[40][40],min_jumps[40][40]; long paths[40][40];
    int ax=0,ay=0;

    // input
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> read;
            if(read == 4){
                ax = i; ay = j;
            }
            if(read == 3){
                sx = i; sy = j; matrix[i][j] = 0;
            } else matrix[i][j] = read;
            //            ans[i][j] = for_ans(1001, 1001, 0);
            min_lilly[i][j]=1001;
            min_jumps[i][j]=1001;
            visited[i][j] = false;
            paths[i][j]=0;
        }
    }

    // main
    queue<for_qu> qu;
    qu.push(for_qu(sx,sy,0,0));

    int X[] = {-2,-2,-1,-1,1,1,2,2};
    int Y[] = {-1,1,-2,2,-2,2,-1,1};
    min_lilly[sx][sy]=0;
    min_jumps[sx][sy]=0;
    paths[sx][sy]=1;
    while(!qu.empty()){
        int i=qu.front().x;
        int j=qu.front().y;
        //        int lilly = min(min_lilly[i][j],qu.front().lilly);
        int lilly = min_lilly[i][j];
        //        int jumps = min(min_jumps[i][j],qu.front().jumps);
        int jumps = min_jumps[i][j];
        qu.pop();


        //        cout<<"@ "<<i<<" "<<j<<" w/ lilly "<<lilly<<" and jumps "<<jumps<<" visited_ans "<<visited[ax][ay]<<" "<<min_lilly[i][j]<<" "<<min_jumps[i][j]<<" "<<paths[i][j]<<endl;


        if(visited[i][j]) continue;
        visited[i][j] = true;


        for(int k=0; k<8; k++){
            int x = i+X[k];
            int y = j+Y[k];
            if(x>=1 && x<=N && y>=1 and y<=M){
                //                cout<<x<<" "<<y<<" m: "<<matrix[x][y]<<" "<<lilly<<endl;
                if(matrix[x][y]==0){
                    //                    if(!visited[x][y])
                    qu.push(for_qu(x,y,lilly+1,jumps+1));
                    if (lilly+1 == min_lilly[x][y] && jumps+1 == min_jumps[x][y]){
                        paths[x][y]+=paths[i][j];
                        //                        cout<<"1paths["<<x<<"]["<<y<<"] = "<<paths[x][y]<<" pre: "<<i<<" "<<j<<" lilly "<<min_lilly[x][y]<<endl;
                    }
                    else if (lilly+1 < min_lilly[x][y] || (lilly+1==min_lilly[x][y] && jumps+1<min_jumps[x][y])){
                        min_lilly[x][y] = lilly+1;
                        min_jumps[x][y] = jumps+1;
                        paths[x][y] = paths[i][j];
                        visited[x][y]=false;
                        //          illy[x][y]<<endl;
                    }
                    //                    else if(lilly+1 > min_lilly[x][y] || jumps+1 > min_jumps[x][y]) continue;

                } else if ((matrix[x][y]==1 or matrix[x][y]==4)){
                    if(matrix[x][y]!=4) qu.push(for_qu(x,y,lilly,jumps+1));
                    if (lilly == min_lilly[x][y] && jumps+1 == min_jumps[x][y]){
                        paths[x][y]+=paths[i][j];
                    }
                    else if (lilly < min_lilly[x][y] || (lilly==min_lilly[x][y] && jumps+1<min_jumps[x][y])){
                        min_lilly[x][y] = lilly;
                        min_jumps[x][y] = jumps+1;
                        paths[x][y] = paths[i][j];
                        visited[x][y]=false;
                    }
                }
            }
        }

    }
    // output
    if (min_lilly[ax][ay]==1001)cout<<"-1";
    else cout<<min_lilly[ax][ay]<<endl<<min_jumps[ax][ay]<<endl<<paths[ax][ay]<<endl;
    return 0;
}

```