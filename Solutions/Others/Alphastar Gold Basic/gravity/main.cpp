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
    int x,y,flips,d;
    p(int x, int y, int flips, int d) : x(x), y(y), flips(flips),d(d) {}
};
// declare any global variables

// declare any functions

int main() {
    // declare any local variables
    int N, M;
    int matrix[501][501];
    int visited[501][501],visited1[501][501];


    // input
    int cx=0,cy=0,dx=0,dy=0;
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        string read;
        cin >> read;
        for(int j=1; j<=M; j++){
            visited[i][j] = visited1[i][j] = 0;
            if(read[j-1]=='#') matrix[i][j] = 1;
            else if (read[j-1]=='.') matrix[i][j] = 0;
            else if (read[j-1]=='D'){
                dx = i; dy = j;
                matrix[i][j] = 0;
            } else if (read[j-1]=='C'){
                cx = i; cy = j;
                matrix[i][j] = 0;
            }

        }
    }


    // bfs
    deque <p> myde;
    int ans = -1;
    myde.push_front(p(cx,cy,0,0));

    while(!myde.empty())
    {
        int i=myde.front().x;
        int j=myde.front().y;
        int f=myde.front().flips;
        int d=myde.front().d;
        myde.pop_front();
        //        cout<<i<<" "<<j<<" "<<f<<" "<<d<<endl;

        //        visited[i][j]=1;
        if(i==dx and j==dy){
            ans = f;
            break;
        }

        if(d==1){
            visited1[i][j]=1;
            if(i-1 < 1) continue;
            else if(i-1 >= 1 and matrix[i-1][j]==0 and visited1[i-1][j]==0){
                myde.push_front(p(i-1,j,f,d));
            } else if (true){
                if ((i-1)>=1){
                    if(((j+1)<=M and matrix[i-1][j]==1 and matrix[i][j+1]==0 and visited1[i][j+1]==0)){
                        //                    if(((j+1)<=M and matrix[i][j+1]==0 and visited1[i][j+1]==0)){
                        myde.push_front(p(i,j+1,f,d));
                    }
                    if((j-1)>=1 and matrix[i-1][j]==1 and matrix[i][j-1]==0 and visited1[i][j-1]==0){
                        //                    if((j-1)>=1 and matrix[i][j-1]==0 and visited1[i][j-1]==0){
                        myde.push_front(p(i,j-1,f,d));
                    }
                }
                if((i+1)<=N and matrix[i+1][j]==0 and visited[i+1][j]==0){
                    myde.push_back(p(i+1,j,f+1,0));
                }
            }
        } else if (d==0){
            visited[i][j]=1;
            if(i+1 > N) continue;
            else if(i+1 <= N and matrix[i+1][j]==0 and visited[i+1][j]==0){
                myde.push_front(p(i+1,j,f,d));
            } else if (true){
                if ((i+1)<=N){
                    if(((j+1)<=M and matrix[i+1][j]==1 and matrix[i][j+1]==0 and visited[i][j+1]==0)){
                        //                    if(((j+1)<=M and matrix[i][j+1]==0 and visited[i][j+1]==0)){
                        myde.push_front(p(i,j+1,f,d));
                    }
                    if((j-1)>=1 and matrix[i+1][j]==1 and matrix[i][j-1]==0 and visited[i][j-1]==0){
                        //                    if((j-1)>=1 and matrix[i][j-1]==0 and visited[i][j-1]==0){
                        myde.push_front(p(i,j-1,f,d));
                    }
                }
                if((i-1)>=1 and matrix[i-1][j]==0 and visited1[i-1][j]==0){
                    myde.push_back(p(i-1,j,f+1,1));
                }

            }
        }
    }
    cout<<ans<<endl;
    // output
    return 0;
}
