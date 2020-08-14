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
#define MAXN 50010
struct point{
    int b, e;
    point(int b, int e) : b(b), e(e) {}
};
// declare any global variables
void readfile(){
    
}
int V,E,K;
int DP[MAXN][11];
vector<point> edges[MAXN];
// declare any functions
int min(int a, int b){
    if(a<b) return a;
    return b;
}
int max(int a, int b){
    if(a>b) return a;
    return b;
}
int dfs(int a, int k){
    if(a == V) return 0;
    if(DP[a][k] != 0) return DP[a][k];
    int maxn = 0;
    int minn = 100000000;
    for(int i=0; i<edges[a].size(); i++){
        int b = edges[a][i].b;
        int e1 = edges[a][i].e;
        maxn = max(maxn, dfs(b,k)+e1);
        //        cout<<a<<" "<<k<<" maxn: "<<maxn<<endl;
        if(k-1 >= 0){
            minn = min(minn, dfs(b,k-1)+e1);
            //            cout<<a<<" "<<k<<" minn: "<<minn<<endl;
        }
    }
    DP[a][k] = min(minn, maxn);
    //    cout<<"dp["<<a<<"]["<<k<<"] = min("<<minn<<", "<<maxn<<") + "<<e<<" = "<<DP[a][k]<<endl;
    return DP[a][k];
}
//long solve(){
//    long minn = 100000000000;
//    for(int k=0; k<=K; k++){
//        for(int i=1; i<=V; i++){
//            for(int j=0; j<=K; j++){
//                DP[i][j]=0;
//            }
//        }
//        minn = min0(minn, dfs(V,k,0));
//    }
//    return minn;
//}
int main() {
    // declare any local variables
    
    // input
    cin >> V >> E >> K;
    for(int i=1; i<=E; i++){
        int a,b,e;
        cin >> a >> b >> e;
        edges[a].push_back(point(b,e));
    }
    // main
    cout<<dfs(1,K)<<endl;
    // output
    
    return 0;
}
