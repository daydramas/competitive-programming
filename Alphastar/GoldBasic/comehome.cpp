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
struct p{
    char b;
    int d;
    p(char b, int d) : b(b),d(d) {}
};
// declare any global variables
//vector <p> path[10001];
//map<char, vector<p> > path;
//map<char, map<char, int> > path;
map<char,int> dist;
//int dist[60];
map<char,int> visited;
//bool visited[60];
// declare any functions
int ansd=1000000000; char ansc;
//void spath(){
//    priority_queue<pair<int, char>,vector<pair<int, char> >, greater<pair<int, char> > > pq;
//
////    memset(dist,1000000000,sizeof(int)*(60));
////    memset(visited,false,sizeof(bool)*(60));
//    visited['Z'] = true;
//    pq.push(make_pair(0,'Z'));
//    dist['Z']=0;
//    while(!pq.empty()){
//        char a = pq.top().second;
////        int d = pq.top().first;
//        pq.pop();
//
//        if(isupper(a) && a!='Z'){
//            ansd = dist[a];
//            ansc = a;
//            return;
//        }
//
//        for(map<char,int>::iterator it=path[a].begin(); it!=path[a].end(); ++it){
//            if(it->second==1000000000) continue;
//            char go = it->first;
//            int ndist = dist[a] + it->second;
//            if((dist[go]==0) || ndist < dist[go]){
//                dist[go] = ndist;
////                if(!visited[go]){
////                    cout<<a<<" -> "<<go<<" "<<dist[go]<<" "<<ndist<<endl;
//                    pq.push(make_pair(dist[go], go));
//                    visited[go]=true;
////                }
//            }
//        }
//    }
//}
int change2int(char c){
    if(islower(c)){
        return (c-'a'+1);
    }
    return (c-'A'+27);
}
char change2char(int a){
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    return abc[a-27];
}
int min0(int a, int b){
    if(a<b){
        return a;
    }
    return b;
}
int main() {
    // declare any local variables
    int P;
    
    // input
    //    int path[60][60];
    map<int, map<int, int> > path;
    cin >> P;
    for(int i=1; i<=52; i++){
        for(int j=1; j<=52; j++){
            path[i][j]=1000000000;
        }
    }
    for(int i=1; i<=P; i++){
        char a,b;
        int d;
        //        int a,b,d;
        cin >> a >> b >> d;
        int ai = change2int(a);
        int bi = change2int(b);
        //        path[a].push_back(p(b,d));
        path[ai][bi]=min0(path[ai][bi],d);
        //        path[a].push_back(p(b,d));
        //        path[b].push_back(p(a,d));
        path[bi][ai]=min0(path[bi][ai],d);
        //        path[b][path[b].size()+1]=p(a,d);
    }
    
    // main
    for(int k=1; k<=52; k++){
        for(int i=1; i<=52; i++){
            for(int j=1; j<=52; j++){
                path[i][j]=min0(path[i][j],path[i][k]+path[k][j]);
            }
        }
    }
    
    for (int k=27; k<=51; k++){
        if(path[52][k]<ansd){
            ansd=path[52][k];
            ansc=change2char(k);
        }
    }
    //    spath();
    // output
    //    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXY";
    //    for(int i=0; i<25; i++){
    ////        cout<<alpha[i]<<" d: "<<dist[alpha[i]]<<endl;
    //        if(dist[alpha[i]]!=0 and (dist[alpha[i]]<ansd || (dist[alpha[i]]==ansd and alpha[i]<ansc))){
    //            ansd=dist[alpha[i]];
    //            ansc=alpha[i];
    //        }
    //    }
    cout<<ansc<<" "<<ansd<<endl;
    return 0;
}
