/*
    ID: dongliu3
    PROG: barn1
    LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int M, S, C;
vector<int> s;

int main() {
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");

    fin >> M >> S >> C;
    for(int i=0; i<C; i++) {
        int t; fin >> t;
        s.push_back(t);
    }
    sort(s.begin(), s.end());
    int ans=S;
    ans -= s[0]-1;
    ans -= S-s.back();
    for(int i=0; i<C-1; i++) {
        s[i]=s[i+1]-s[i]-1;
    }
    s.pop_back();
    sort(s.rbegin(), s.rend());

    for(int i=0; i<min(M-1,C-1); i++) ans -= s[i];
    fout << ans << '\n';
}