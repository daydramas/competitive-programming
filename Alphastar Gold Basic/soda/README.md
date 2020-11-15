# soda
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
struct node{
    int location; bool start;
    node(int location, bool start) : location(location), start(start) {}
};
struct myclass {
    bool operator() (node i,node j) {
        if(i.location!=j.location) return (i.location<j.location);
        return i.start==true;
    }
} waytosort;

// declare any global variables
int N;
vector<node> interval; int read_s, read_e;
// declare any functions
void initialize(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> read_s >> read_e;
        interval.push_back(node(read_s, true));
        interval.push_back(node(read_e, false));
    }
    sort(interval.begin(), interval.end(), waytosort);
}
void solve(){
    int ans = 0;
    int counter = 0;
    for(int i=0; i<(2*N); i++){
        if(interval[i].start){
            counter++;
            ans = max(ans, counter);
        } else if (!interval[i].start){
            counter--;
        }
    }
    cout<< ans <<endl;
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