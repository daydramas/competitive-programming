# sandcas
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
    bool operator() (int i,int j) { return (i<j);}
} waytosort;
// declare any global variables
int N, X, Y;
vector<int> M, B;
// declare any functions
void initialize(){
    cin >> N >> X >> Y;
    for(int i=0; i<N; i++){
        int m, b; cin >> m >> b;
        M.push_back(m);
        B.push_back(b);
    }
    sort(M.begin(), M.end(), waytosort);
    sort(B.begin(), B.end(), waytosort);
}
void solve(){
    int ans = 0;
    for(int i=0; i<N; i++){
        if(M[i] > B[i]){
            ans += abs(M[i] - B[i])*Y;
        } else{
            ans += abs(M[i] - B[i])*X;
        }
    }
    cout<<ans<<endl;
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