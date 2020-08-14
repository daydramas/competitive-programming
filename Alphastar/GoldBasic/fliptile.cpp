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
int N, M;
int grid[16][16];
bool flipped[16][16];
int X[] = {0,1,0,-1,0};
int Y[] = {0,0,1,0,-1};

// declare any functions

//void non_recurse(int i){
//
//
//}
int least_flip = 300;
bool flipped_ans[16][16];
bool compair(bool a[16][16],bool b[16][16]){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(!b[i][j] && a[i][j]){
                return false;
            }
            if(!a[i][j] && b[i][j]){
                return true;
            }
        }
    }
    return false;
}
void flip(int i, int j){
    flipped[i][j]=true;
    for(int k=0; k<5; k++){
        int x = i+X[k];
        int y = j+Y[k];
        if(x>=1 && x<=N && y>=1 && y<=M){
            grid[x][y]=1-grid[x][y];
        }
    }
}
void dfs(int z){
    //    cout<<"j: "<<z<<" grid: "<<grid[1][1]<<" "<<grid[1][2]<<" "<<grid[1][3]<<" "<<grid[1][4]<<" "<<grid[1][5]<<endl;
    //    cout<<endl;
    if(z>M){
        int oldgrid[16][16];
        bool oldflip[16][16];
        //        for(int i=1; i<=N; i++) {
        //            for(int j=1; j<=M; j++) {
        //                cout<<grid[i][j]<<" ";
        //            }
        //            cout<<endl;
        //        }
        //        cout<<"causing"<<endl;
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                oldgrid[i][j]=grid[i][j];
                oldflip[i][j]=flipped[i][j];
            }
        }
        for(int i=2; i<=N; i++){
            for(int j=1; j<=M; j++){
                if(grid[i-1][j]==1){
                    flip(i,j);
                }
            }
        }
        bool impossible1 = false;
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                if(grid[i][j]==1){
                    impossible1=true;
                    //                    cout<<"failed on "<<i<<" "<<j<<endl;
                    //                    break;
                }
            }
            //            if(impossible1) break;
        }
        if(!impossible1){
            int k=0;
            for(int i=1; i<=N; i++) {
                for(int j=1; j<=M; j++) {
                    //                    cout<<flipped[i][j]<<" ";
                    if(flipped[i][j]) k++;
                }
                //                cout<<endl;
            }
            //            cout<<endl;
            if(k<least_flip || (k==least_flip && compair(flipped,flipped_ans))){
                least_flip=k;
                for(int i=1; i<=N; i++) {
                    for(int j=1; j<=M; j++) {
                        flipped_ans[i][j]=flipped[i][j];
                    }
                }
            }
        }
        
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                grid[i][j]=oldgrid[i][j];
                flipped[i][j]=oldflip[i][j];
            }
        }
        return;
    }
    // w/out flip
    dfs(z+1);
    flip(1,z);
    // w/ flip
    dfs(z+1);
    flipped[1][z] = false;
    for(int k=0; k<5; k++){
        int x = 1+X[k];
        int y = z+Y[k];
        if(x>=1 && x<=N && y>=1 && y<=M){
            grid[x][y]=1-grid[x][y];
        }
    }
}
int main() {
    // declare any local variables
    // fstream
    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            int tile_color;
            cin >> tile_color;
            
            grid[i][j]=tile_color;
            flipped[i][j]=false;
            flipped_ans[i][j]=false;
        }
    }
    // input
    dfs(1);
    
    // main
    if(least_flip==300) cout<<"IMPOSSIBLE"<<endl;
    else {
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                cout<<flipped_ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    // output
    
    return 0;
}
