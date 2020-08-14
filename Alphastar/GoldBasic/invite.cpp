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
#include <set>
#include <algorithm>
using namespace std;

// declare any structures

// declare any global variables

// declare any functions

int main() {
    // declare any local variables
    int N,G;
    map<int, vector<int> > group;
    map<int, set<int> >party;
    //    vector<int> group[600],party[600];
    //    int group[310][310],party[310][310];
    bool visited[1000001];
    
    // input
    cin >> N >> G;
    
    for(int i=1; i<=G; i++){
        int size1;
        cin >> size1;
        for(int j=1; j<=size1; j++){
            int id;
            cin >> id;
            group[id].push_back(i);
            //            group[id][count]=i;
            party[i].insert(id);
            //            party[i][count]=id;
            visited[j] = false;
            
        }
    }
    // main
    queue <int> qu;
    int counter=0;
    visited[1]=true;
    qu.push(1);
    while(!qu.empty()){
        int i=qu.front();
        qu.pop();
        
        counter++;
        for(int j=0; j<group[i].size(); j++){
            int g=group[i][j];
            
            
            party[g].erase(i);
            
            if(party[g].size()==1){
                set<int>::iterator it=party[g].begin();
                int in=*it;
                if(!visited[in]){
                    visited[in]=true;
                    qu.push(in);
                }
            }
        }
    }
    
    // output
    cout<<counter<<endl;
    return 0;
}
