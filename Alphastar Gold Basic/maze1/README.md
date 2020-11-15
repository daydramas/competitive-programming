# maze1
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
#include <string>
using namespace std;

// declare any structures

// declare any global variables
struct p{
    int x,y,d,t;
    p(int x, int y, int d,int t) : x(x),y(y),d(d),t(t) {}
};
// declare any functions

int main() {
    // declare any local variables
    int N, M;
    cin >> M >> N;
    string temp;
    getline(cin, temp);
    
    int maze[N*2+1][M*2+1];
    bool visited1[N*2+1][M*2+1];
    
    int ex1,ey1; int ex2,ey2;
    ex1=ey1=ex2=ey2=-1;
    
    for(int i=0; i<((N*2)+1); i++){
        string read;
        getline(cin,read);
        for(int j=0; j<((M*2)+1); j++){
            visited1[i][j]=false;
            if(read[j]=='+' or read[j]=='-' or read[j]=='|') maze[i][j]=1;
            else maze[i][j]=0;
            
            if(maze[i][j]==0){
                if(i==0){
                    if(ex1==-1){
                        ex1=1; ey1=j;
                    } else{
                        ex2=1; ey2=j;
                    }
                } else if(i==2*N){
                    if(ex1==-1){
                        ex1=(2*N)-1; ey1=j;
                    } else{
                        ex2=(2*N)-1; ey2=j;
                    }
                } else if(j==0){
                    if(ex1==-1){
                        ex1=i; ey1=1;
                    } else{
                        ex2=i; ey2=1;
                    }
                } else if(j==2*M){
                    if(ex1==-1){
                        ex1=i; ey1=(2*M)-1;
                    } else{
                        ex2=i; ey2=(2*M)-1;
                    }
                }
            }
        }
    }
    // main
    //    cout<<ex1<<" "<<ey1<<" "<<ex2<<" "<<ey2<<endl;
    queue<p> qu;
    
    qu.push(p(ex1,ey1,1,0));
    qu.push(p(ex2,ey2,1,1));
    
    
    int X[] = {1,0,-1,0};
    int Y[] = {0,1,0,-1};
    int ans = 0;
    
    visited1[ex1][ey1]=visited1[ex2][ey2]=true;
    while(!qu.empty()){
        int i=qu.front().x;
        int j=qu.front().y;
        int d=qu.front().d;
        int t=qu.front().t;
        //        int t=qu.front().t;
        qu.pop();
        
        ans = max(ans,d);
        
        //        if(t==1){
        for(int k=0; k<4; k++){
            int x=i+X[k];
            int y=j+Y[k];
            if(x>=0 && x<=(N*2)+1 && y>=0 && y<=M*2+1){
                //                    cout<<"pass ";
                if(maze[x][y]==0){
                    //                        cout<<"pass :";
                    x += X[k]; y += Y[k];
                    //                        cout<<x<<"/ "<<y<<" ";
                    if(x>=0 && x<=N*2 && y>=0 && y<=M*2 && !visited1[x][y] && maze[x][y]==0){
                        //                            cout<<"pass ";
                        qu.push(p(x,y,d+1,t));
                        visited1[x][y]=true;
                    }
                }
            }
        }
    }
    // output
    cout<<ans<<endl;
    return 0;
}

```