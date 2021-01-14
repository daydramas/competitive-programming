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
int out[MX], cycle[MX];
vi S; // stack
bool vis[MX]; // visited
int cycleID=-1, pathID=-1;
int in[MX], lca[MX][20];

using cyclePath = set<pair<int, int> >;
vector<cyclePath> paths;

void findCycle(int i) {
    if (vis[i]) return;
    vis[i]=1; S.pb(i);
    findCycle(out[i]);
}

pair<int, pair<int, int> > d[MX]; // {depth, {pathID, cycleID}}
pair<int, pair<int, int> > dfs(int i) {
    if (d[i].f!=-1) return d[i];
    if (cycle[i] != -1) return { 0, { pathID, i } };
    pair<int, pair<int, int> > prev = dfs(out[i]);
    d[i] = { prev.f+1, prev.s };
    return d[i];
}
int getDist(int c, int a, int b) {
    if (a<=b) return b-a;
    return (paths[c].size()-a+b);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // freopen("input.in", "r", stdin);
    // freopen("input.out", "w", stdout);

    cin >> n >> q;
    // cerr << "read n and q\n";
    FOR(i,1,n) in[i]=0;
    FOR(i,1,n) { int a; cin >> a; out[i]=a, in[a]++; lca[i][0]=a; }
    FOR(i,1,n) vis[i]=false, cycle[i]=-1;
    FOR(i,1,19) FOR(j,1,n) lca[j][i] = lca[lca[j][i-1]][i-1];
    FOR(i,1,n) if (!vis[i]) {
        findCycle(i);
        int count=0; int firstItem = out[S.back()];
        trav(a, S) {
            if (a==firstItem) count=1, cycleID++, paths.pb({});
            if (count) cycle[a]=cycleID, paths[cycleID].insert({a, count-1}), count++;
        } S.clear();
    }
    FOR(i,1,n) d[i]={-1,{-1,-1}};
    FOR(i,1,n) if (in[i]==0) {
        // cout << i<<" is a root\n";
        pathID++; dfs(i);
    }
    FOR(i,1,q) {
        int a,b; cin >> a >> b;
        if (a==b) cout <<"0\n"; // same node
        else if (cycle[a]==-1 && cycle[b]==-1) { // both are NOT in a cycle
            if (d[a].s.f == d[b].s.f && d[a].f>=d[b].f) {
                int diff = d[a].f-d[b].f;
                R0F(i,20) if (diff & (1<<i)) a=lca[a][i];
                if (a==b) cout <<diff<<"\n";
                else cout <<"-1\n";
            }
            else cout <<"-1\n";
        } else if (cycle[a]==-1 && cycle[b]!=-1) { // a is NOT in cycle, b is in cycle
            int AcycleID = cycle[d[a].s.s];
            auto it2 = paths[AcycleID].lower_bound({b,-1});
            if (it2!=paths[AcycleID].end() && (*it2).f==b) {
                auto it = paths[AcycleID].lower_bound({d[a].s.s, -1});
                cout <<d[a].f+getDist(AcycleID,(*it).s,(*it2).s) <<"\n";
            } else cout <<"-1\n";
        } else if (cycle[a]!=-1 && cycle[b]!=-1) { // both are in cycle
            if (cycle[a] == cycle[b]) {
                auto it = paths[cycle[a]].lower_bound({a,-1});
                auto it2 = paths[cycle[a]].lower_bound({b,-1});
                cout <<getDist(cycle[a], (*it).s, (*it2).s)<<"\n";
            } else cout <<"-1\n";
        } else cout <<"-1\n";
    }
    return 0;
}