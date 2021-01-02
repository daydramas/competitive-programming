/*
    ID: dongliu3
    PROG: milk
    LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, m;
// n is number of units needed
// m is number of farmers
vector<pair<ll,int>> f;

int main() {
    ifstream fin("milk.in");
    ofstream fout("milk.out");

    fin >> n >> m;
    for(int i=0; i<m; i++) {
        ll cost; int units;
        fin >> cost >> units;
        f.push_back({cost, units});
    }
    sort(f.begin(), f.end());
    ll result = 0;
    for(int i=0; i<m; i++) {
        if(n == 0) break;
        result += f[i].first * min(n, f[i].second);
        n -= min(n, f[i].second);
    }
    fout << result << '\n';
}