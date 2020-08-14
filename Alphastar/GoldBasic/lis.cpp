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

// declare any functions
int max0(int a, int b){
    if(a>b) return a;
    return b;
}
int main() {
    // declare any local variables
    int N;
    int num[20001];
    int DP[20001];
    
    // input
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> num[i];
    }
    
    // main
    //    vector < vector<int> > LIS;
    int maxn = 0;
    for(int i=1; i<=N; i++){
        DP[i] = 1;
        for(int j=1; j<=i-1; j++){
            if(num[j]<num[i]){
                DP[i] = max(DP[i], DP[j]+1);
            }
        }
        maxn = max(maxn, DP[i]);
    }
    //    vector<int> sub;
    //    LIS.push_back(sub);
    //    for(int i=1; i<=N; i++){
    //
    ////        if(LIS.size()==0){
    //////            LIS.push_back(push_back(num[i]));
    ////            vector<int> sub; sub.push_back(num[i]);
    ////            LIS.push_back(sub);
    ////        }
    ////        else {
    ////        cout<<i<<" s: "<<LIS.size()<<endl;
    //        for(int j=0; j<LIS.size(); j++){
    //            if(LIS[j].size()==0 || num[i] > LIS[j][LIS[j].size()-1]){
    //                vector<int> sub1=LIS[j];
    //                sub1.push_back(num[i]);
    //                LIS.push_back(sub1);
    //            } else {
    //                LIS.erase(LIS.begin()+j);
    //            }
    //        }
    ////        }
    ////        maxn = max0(maxn, LIS.size());
    //        for(int j=0; j<LIS.size(); j++){
    //            maxn = max0(maxn, LIS[j].size());
    //            for(int k=0; k< LIS[j].size(); k++){
    ////                cout<<LIS[j][k]<<" ";
    //            }
    ////            cout<<endl;
    ////            cout<<LIS[j].size()<<" ";
    //        }
    ////        cout<<endl;
    //    }
    // output
    cout<<maxn<<endl;
    return 0;
}
