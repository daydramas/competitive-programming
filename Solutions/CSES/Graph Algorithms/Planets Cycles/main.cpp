#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
#define f first
#define s second
#define pb push_back
#define all(x) begin(x), end(x)

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

const int MX = 2e5+5;

int n, q;
int out[MX]; int cycle[MX], csz[MX];
vi S; // stack
bool vis[MX]; // visited
int cycleID=-1;
int in[MX];

void findCycle(int i) {
    if (vis[i]) return;
    vis[i]=1; S.pb(i);
    findCycle(out[i]);
}

int d[MX];
int dfs(int i) {
    if (d[i]!=-1) return d[i];
    if (cycle[i] != -1) return csz[cycle[i]];
    return (d[i] = dfs(out[i])+1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    FOR(i,1,n) { int a; cin >> a; out[i]=a, in[a]++; }
    FOR(i,1,n) vis[i]=false, cycle[i]=-1;
    FOR(i,1,n) if (!vis[i]) {
        findCycle(i);
        int count=0; int firstItem = out[S.back()];
        trav(a, S) {
            if (a==firstItem) count=1, cycleID++;
            if (count) cycle[a]=cycleID, count++;
        } S.clear(); if (count) csz[cycleID]=count;
    }
    FOR(i,1,n) d[i]=-1;
    FOR(i,1,n) if (in[i]==0) dfs(i);
    FOR(i,1,n) {
        if (cycle[i]!=-1) cout << csz[cycle[i]]-1 <<" ";
        else cout << d[i]-1<<" ";
    }
    return 0;
}