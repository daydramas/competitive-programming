# milkprod
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
struct point {
    int start, end, efficiency;
    point(int start, int end, int efficiency) : start(start), end(end), efficiency(efficiency) {}
};
struct s2b {
    bool operator() (point i, point j) { return (i.start<j.start);}
} s2b;

// declare any global variables
int N, M, R;
vector<point> interval;
int dp[1000001];
// declare any functions
void initialize(){
    cin >> N >> M >> R;
    
    int a, b, e;
    for(int i=1; i<=M; i++){
        cin >> a >> b >> e;
        interval.push_back(point(a,b,e));
    }
    sort(interval.begin(), interval.end(), s2b);
    //    for(int i=0; i<M; i++){
    //        cout<<interval[i].start<<" "<<interval[i].end<<" "<<interval[i].efficiency<<endl;
    //    }
}
void solve_dp(){
    for(int i=1; i<=M; i++){
        for(int j=0; j<=N; j++){
            if(j>interval[i-1].start) break;
            if((dp[j]==0 and j<=interval[i-1].start)||(j+R <= interval[i-1].start )){
                //                cout<<"dp["<<interval[i-1].end<<"] = max("<<dp[interval[i-1].end]<<", "<<dp[j]<<"+"<<interval[i-1].efficiency<<") = "<<max(dp[interval[i-1].end], dp[j]+interval[i-1].efficiency)<<endl;
                dp[interval[i-1].end] = max(dp[interval[i-1].end], dp[j]+interval[i-1].efficiency);
            }
        }
    }
}
void print_ans(){
    
    int ans = 0;
    for(int j=0; j<=N; j++){
        ans = max(ans, dp[j]);
    }
    cout<<ans<<endl;
}
int main() {
    
    // input
    initialize();
    // main
    solve_dp();
    // output
    print_ans();
    
    //close
    return 0;
}

```