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

int main() {
    // declare any local variables
    int N,W;
    vector<pair<string,int> > dic;
    
    // input
    cin >> W >> N;
    string read;
    for(int i=1; i<=W; i++){
        cin >> read;
        dic.push_back(make_pair(read,i));
    }
    sort(dic.begin(),dic.end());
    // main
    int K;
    int times;
    string word;
    for(int i=1; i<=N; i++){
        cin >> K >> word;
        times=0;
        times=lower_bound(dic.begin(),dic.end(),make_pair(word,0))-dic.begin();
        
        times+=K-1;
        
        if(times<W) {
            if(dic[times].first.substr(0,word.length())==word){
                cout<<dic[times].second<<endl;
            } else{
                cout<<"-1"<<endl;
            }
        } else cout<<"-1"<<endl;
    }
    
    // output
    
    return 0;
}
