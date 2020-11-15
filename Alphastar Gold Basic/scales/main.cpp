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


struct myclass {
    bool operator() (int i,int j) { return (i>j);}
} myobject;


vector<int> weight;
int N; int max1;
int ans = 0;
void recurse (int i, int C){
    
    if(C < 0) return;
    ans = max(ans, max1-C);
    
    
    if(C == 0) return;
    if(i >= N) return;
    
    if(i+1<N and weight[i]+weight[i+1]<=C){
        recurse(i+1, C-weight[i]);
    }
    else if(weight[i] > C){
        recurse(i+1, C);
    }
    else {
        recurse(i+1, C-weight[i]);
        recurse(i+1, C);
    }
    
}

int main() {
    
    cin >> N >> max1;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        weight.push_back(a);
    }
    
    sort(weight.begin(), weight.end(), myobject);
    recurse(0,max1);
    
    cout<<ans<<endl;
    return 0;
}
