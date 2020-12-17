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

#define rsz resize
struct DSU {
    vi sz, pa; int comps;
    DSU() {}
    DSU(int n) { comps=n; sz.rsz(n+1), pa.rsz(n+1);
                FOR(i,1,n) sz[i]=1, pa[i]=i; }

    int get(int a) { // find parent
        if(pa[a] == a) return a;
        return pa[a]=get(pa[a]);
    }

    bool comb(int a, int b) { // merge
        a=get(a), b=get(b);
        if (a==b) return false;
        if (sz[a] < sz[b]) swap(a,b);
        sz[a]+=sz[b]; pa[b]=a; comps--;
        return true;
    }

};

const int maxn = 1e5+5;

using pii = pair<int,int>;

int main() {

    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m, k;
    map<pii,int> M;
    vector<pii> todo;

    cin >> n >> m >> k;
    DSU D(n);
    F0R(i,m) {
        int a,b; cin >> a >> b;
        if(a>b) swap(a,b);
        M[{a,b}] = 1;
    }
    F0R(i,k) {
        int a,b; cin >> a >> b;
        if(a>b) swap(a,b);
        M[{a,b}] = 0;
        todo.pb({a,b});
    }
    trav(x, M) if(x.s) D.comb(x.f.f,x.f.s);
    vi ans;
    R0F(i,k) {
        ans.pb(D.comps);
        D.comb(todo[i].f, todo[i].s);
    }
    R0F(i,k) cout << ans[i] << " ";
}