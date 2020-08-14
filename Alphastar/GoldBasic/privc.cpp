/*
 ============================================================================
 Name        : cpp_template.cpp
 Author      : Dong Liu
 Website     : dongliu.template.com
 ============================================================================
 */
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;

// declare any structures
struct myclass {
    bool operator() (int i,int j) { return (i<j);}
} myobject;

// declare any global variables
int N;
vector<int> order, sorted;
int cow[4][4];
// declare any functions
void initialize(){
    cin >> N;
    int read;
    for(int i=1; i<=N; i++){
        cin >> read;
        order.push_back(read);
        sorted.push_back(read);
    }
    cow[1][1]=cow[1][2]=cow[1][3]=0;
    cow[2][1]=cow[2][2]=cow[2][3]=0;
    cow[3][1]=cow[3][2]=cow[3][3]=0;
    
    sort(sorted.begin(), sorted.end(), myobject);
}
void solve(){
    for(int i=0; i<N; i++){
        if(order[i] != sorted[i]){
            cow[order[i]][sorted[i]]++;
        }
    }
    int ans = 0;
    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            //            if(i==j) continue;
            int minn = min(cow[i][j], cow[j][i]);
            ans += minn;
            cow[i][j] -= minn;
            cow[j][i] -= minn;
        }
    }
    ans += (cow[1][2]+cow[1][3])*2;
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
