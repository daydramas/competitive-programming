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
#define ll long long
struct node{
    ll start, speed, end_position;
    node(ll start, ll speed, ll end_position) : start(start), speed(speed), end_position(end_position) {}
};

// declare any global variables
ll N, T;
vector <node> cow;
int position[100001];
// declare any functions
void initialize(){
    cin >> N >> T;
    ll start, speed, end_position;
    for(int i=0; i<N; i++){
        cin >> start >> speed;
        end_position = start + (speed*T);
        cow.push_back(node(start, speed, end_position));
    }
    for(int i=0; i<N; i++){
        //        cout<<cow[i].start<<" "<<cow[i].speed<<" "<<cow[i].end_position<<endl;
    }
}
void solve(){
    //    position[1] = cow[0].end_position;
    //    cout<<"solving ... "<<endl;
    long long groups = N;
    for(long long i=N-1; i>0; i--){
        //        cout<<cow[i].end_position<<" "<<cow[i-1].end_position<<" "<<groups<<endl;
        if(cow[i].end_position <= cow[i-1].end_position){
            //            cout<<"cow["<<i-1<<"].end_position = "<<"cow["<<i<<"].end_position"<<endl;
            //            cout<<cow[i-1].end_position<<" = "<<cow[i].end_position<<endl;
            cow[i-1].end_position = cow[i].end_position;
            //            groups--;
        }
        //        cout<<"groups: "<<groups<<endl;;
    }
    for(int i=1; i<N; i++){
        if(cow[i].end_position == cow[i-1].end_position) groups--;
    }
    cout<<groups<<endl;
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
