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
#define MAXN 50001
// declare any global variables
int N;
//int Elsie[MAXN];
vector<int> Elsie1, Elsie2, Bessie;
bool deck[(2*MAXN)-1];

struct myclass {
    bool operator() (int i,int j) { return (i<j);}
} myobject;

// declare any functions
void initialize(){
    cin >> N;
    memset(deck, false, sizeof(deck));
    for(int i=1; i<=N; i++){
        int card; cin >> card;
        if(i<=(N/2)) Elsie1.push_back(card);
        else Elsie2.push_back(card);
        deck[card] = true;
        //        cout<<"deck["<<Elsie[i]<<"] = true"<<endl;
    }
    for(int i=1; i<=2*N; i++){
        if(!deck[i]){
            Bessie.push_back(i);
        }
    }
    sort(Elsie1.begin(), Elsie1.end(), myobject);
    sort(Elsie2.begin(), Elsie2.end(), myobject);
    sort(Bessie.begin(), Bessie.end(), myobject);
}
void solve(){
    int ans = 0;
    for(int i=0; i<Elsie1.size(); i++){
        for(int j=(N/2); j<=(N-1); j++){
            if(Bessie[j]>Elsie1[i] && !deck[Bessie[j]]){
                ans++;
                //                cout<<"used "<<Bessie[j]<<" to defeat "<<Elsie[i]<<endl;
                deck[Bessie[j]] = true;
                break;
            }
        }
    }
    for(int i=0; i<Elsie2.size(); i++){
        for(int j=0; j<N/2; j++){
            if(!deck[Bessie[j]] && Bessie[j]<Elsie2[i]){
                ans++;
                //                cout<<"used "<<Bessie[j]<<" to defeat "<<Elsie[i]<<endl;
                deck[Bessie[j]] = true;
                break;
            }
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
