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
    int h,s;
    p(int h, int s) : h(h),s(s) {}
};
// declare any global variables

// declare any functions

int main() {
    // declare any local variables
    int n;
    vector<p> heights;
    
    // main
    cin >> n;
    int sound[50010];
    for(int i=0; i<n; i++){
        int h,s;
        sound[i]=0;
        cin >> h >> s;
        heights.push_back(p(h,s));
    }
    
    
    for(int i=0; i<n; i++){
        for(int j=(i+1); j<n; j++){
            if(heights[j].h > heights[i].h){
                sound[j]+=heights[i].s;
                break;
            }
        }
        for(int j=(i-1); j>=0; j--){
            if(heights[j].h > heights[i].h){
                sound[j]+=heights[i].s;
                break;
            }
        }
    }
    
    // output
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans,sound[i]);
    }
    cout<<ans<<endl;
    return 0;
}
