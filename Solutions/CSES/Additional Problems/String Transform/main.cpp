#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

using ll = long long;
#define f first
#define s second

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string s; cin >> s;
    pair<int,int> v[s.length()];
    F0R(i,s.length()) v[i] = {(s[i]-'a'), i};
    sort(v, v+s.length());
    int c=v[0].s;
    while(c!=0) {
        putchar('a'+v[c].f);
        c=v[c].s;
    }
}