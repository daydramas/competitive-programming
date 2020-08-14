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
struct point{
    int a; int b;
    point(int a, int b) : a(a), b(b) {}
};
// declare any global variables
struct sorting {
    bool operator() (point i,point j) {
        if(i.b!=j.b) return (i.b<j.b);
        else  return i.a<j.a;
    }
} sorting1;

// declare any functions

int main() {
    // declare any local variables
    int N;
    vector<point> interval;
    // input
    cin >> N;
    for(int i=1;i<=N; i++){
        int a,b;
        cin >> a >> b;
        interval.push_back(point(a,b));
    }
    // main
    sort(interval.begin(), interval.end(), sorting1);
    int maxn = 0;
    int ans = 0;
    for(int i=0; i<N; i++){
        if(interval[i].a >= maxn){
            ans++;
            maxn = max(maxn, interval[i].b);
        }
    }
    // output
    cout<<ans<<endl;
    return 0;
}
