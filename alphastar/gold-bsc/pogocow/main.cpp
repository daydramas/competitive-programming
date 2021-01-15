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

using namespace std;

//structures
struct point{
    int x, p;
    point(int x, int p):x(x),p(p) {}
};
struct myclass {
    bool operator() (point i,point j) { return (i.x<j.x);}
} waytosort;

//global variables

// functions

int main() {
    
    // local variables
    int N;
    int DP[1010][1010];
    vector<point> target;
    
    // input
    cin >> N;
    
    for(int i = 0; i < N; i++){
        int x,p;
        cin >> x >> p;
        target.push_back(point(x,p));
    }
    sort(target.begin(), target.end(), waytosort);
    
    //main
    int maxn = 0;
    for(int temp = 0; temp < 2; temp++) {
        for(int i = N-1; i >= 0; i--) {
            int k = N;
            int val = 0;
            for(int j=0; j<=i; j++) {
                while(k - 1 > i && target[k - 1].x - target[i].x >= target[i].x - target[j].x) {
                    k--;
                    val = max(val, target[k].p + DP[k][i]);
                }
                DP[i][j] = val;
            }
            maxn = max(maxn, target[i].p + val);
        }
        for(int i = 0; i < N; i++) {
            target[i].x = -1*target[i].x;
        }
        reverse(target.begin(), target.end());
    }
    
    //output
    cout << maxn << endl;
    return 0;
}
