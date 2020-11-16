# jump
```cpp
/*
 ============================================================================
 Name        : cpp_template.cpp
 Author      : Dong Liu
 Website     : dongliu.template.com
 ============================================================================
 */
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

// declare any structures
struct myclass {
    bool operator() (int i, int j) { return (i<j);}
} waytosort;

// declare any global variables
int L, N, M;
vector<int> rocks;
bool mark[50001];
// declare any functions
void initialize(){
    cin >> L >> N >> M;
    memset(mark, false, sizeof(mark));
    for(int i=0; i<N; i++){
        int read_dist;
        cin >> read_dist;
        rocks.push_back(read_dist);
    }
    rocks.push_back(L);
    sort(rocks.begin(), rocks.end(), waytosort);
}
void solve(){
    int min = 0;
    int max = 1000000000;
    while(min<max && min!=max){
        int mid = (min+max)/2;
        int safe = 0;
        int left = M;
        int work = true;
        for(int i=0; i<=N; i++){
            if(rocks[i]-safe >= mid){
                safe = rocks[i];
            } else {
                left--;
                if(left < 0){
                    work = false;
                    break;
                }
            }
        }
        if(work){
            if(min+1 == max){
                min = mid;
                break;
            }
            min = mid;
            //            cout<<mid<<" worked "<<min<<" "<<max<<endl;
        } else {
            max = mid;
            //            cout<<mid<<" no worked "<<min<<" "<<max<<endl;
        }
    }
    cout<<min<<endl;
}
void print_ans(){
    
}
int main() {
    
    // input
    initialize();
    // main
    solve();
    // output
    print_ans();
    
    //close
    return 0;
}

```