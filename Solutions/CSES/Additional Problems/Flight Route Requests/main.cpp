#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
#define f first
#define s second
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

const int maxn = 1e5+5;
queue<int> Q;

struct TopoSort {
    vi adj[maxn], res; int w[maxn];
    TopoSort() {}
    TopoSort(int n) { FOR(i,1,n) w[i]=0; }

    void ae(int a, int b) { adj[a].pb(b); w[b]++; }
    bool sort(int N) {
        res.clear();
        while(!Q.empty()) {
            int a=Q.front(); Q.pop(); res.pb(a);
            trav(b, adj[a]) if (!(--w[b])) Q.push(b);
        }
        return sz(res)==N;
    }
};
struct DSU {
    int sz[maxn], pa[maxn];

    DSU() {}
    DSU(int n) {
        FOR(i,1,n) sz[i]=1, pa[i]=i;
    }

    int get(int a) { // find parent
        if(pa[a] == a) return a;
        return pa[a]=get(pa[a]);
    }

    bool comb(int a, int b) { // merge
        a=get(a), b=get(b);
        if (a==b) return false;
        if (sz[a] < sz[b]) swap(a,b);
        sz[a]+=sz[b]; pa[b]=a;
        return true;
    }

};

int n, m;
DSU D;
TopoSort T;
map<int,vi> M;
int main() {

    cin >> n >> m;
    D = DSU(n);
    T = TopoSort(n);
    while(m--) {
        int a,b; cin >> a >> b;
        D.comb(a,b);
        T.ae(a,b);
    }
    FOR(i,1,n) M[D.get(i)].pb(i);
    int ans = 0;
    trav(x, M) {
        trav(j,x.s) if (T.w[j] == 0) Q.push(j);
        if (T.sort(sz(x.s))) ans += sz(x.s)-1; // not a cycle
        else ans += sz(x.s); // cycle
    }
    cout << ans;

}