/*
    ID: dongliu3
    PROG: milk2
    LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int n;
using point = pair<int,int>; // {time, start/end}
vector<point> P;

int main() {

    ifstream fin("milk2.in");
    ofstream fout("milk2.out");

    fin >> n;
    for(int i=0; i<n; i++) {
        int s, e; fin >> s >> e;
        P.push_back({s, -1}); // -1 is start
        P.push_back({e, 1}); // 1 is end
    }
    sort(P.begin(), P.end());
    int farmers=0, cur_m=0, cur_i=0, ans_m=0, ans_i=0;
    for(int i=0; i<P.size(); i++) {
        if(i!=0) {
            if(farmers) {
                cur_m += P[i].first-P[i-1].first;
                ans_m = max(ans_m, cur_m);
                cur_i = 0;
            } else {
                cur_m = 0;
                cur_i += P[i].first-P[i-1].first;
                ans_i = max(ans_i, cur_i);
            }
        }
        if(P[i].second == -1) farmers++;
        else farmers--;
    }
    fout << ans_m <<" "<<ans_i <<"\n";
}