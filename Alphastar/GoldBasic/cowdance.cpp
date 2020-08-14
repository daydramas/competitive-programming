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
    int t,i;
    p(int t, int i) : t(t),i(i) {}
};
// declare any global variables
struct b2s {
    bool operator() (int i,int j) { return (i>j);}
} b2s;

// declare any functions

int main() {
    // declare any local variables
    int N,T_max;
    vector<int> time;
    
    // input
    cin >> N >> T_max;
    for(int i=0; i<N; i++){
        int read;
        cin >> read;
        time.push_back(read);
    }
    
    int min = 0, max=N;
    while(min<max){
        int K = (min+max)/2;
        priority_queue<int, vector<int>, greater<int> > qu;
        int in = -1;
        for(int i=0; i<K; i++){
            in++;
            qu.push(time[in]);
        }
        bool work = false;
        while(!qu.empty()){
            int i=qu.top();
            qu.pop();
            
            if(in==N){
                work=true;
                break;
            }
            in++;
            if(i+time[in]>T_max){
                work=false;
                break;
            }
            qu.push(i+time[in]);
            
        }
        if(work){
            max=K;
        } else{
            min=K+1;
        }
    }
    // main
    cout<<min<<endl;
    // output
    
    return 0;
}
