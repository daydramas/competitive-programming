#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

using ll = long long;
using ld = long double;
using str = string;

using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<str>;
using vii = vector<pii>;
template <class T> using v = vector<T>;

#define mp make_pair
#define f first
#define s second

#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define lb lower_bound
#define ub upper_bound

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

const int MOD = 1e9+7;
const ll INF = 1e18;
const int MX = 2e5+5;
const ld PI = acos(-1);
const int X[] = {1, 0, -1, 0},
          Y[] = {0, 1, 0, -1};

/* ============================ */

void setIO(str PROB = "") {
    cin.tie(0)->sync_with_stdio(0);
    if(sz(PROB)) {
        freopen((PROB+".in").c_str(), "r", stdin);
        freopen((PROB+".out").c_str(), "w", stdout);
    }
}

/* ============================ */
template<int SZ> struct DSU {
    int sz[SZ], pa[SZ];

    DSU() {
        for(int i=0; i<SZ; i++)
            sz[i]=1, pa[i]=i;
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
template<int SZ> struct MST {
    using Edge = pair<int, pair<int, int> >;
    DSU<SZ> dsu;
    vector<Edge> edges;

    void ae(int a, int b, int c) {
        edges.pb({c, {a, b}});
    }
    ll calc(int n) {
        ll res=0, cnt=1;
        sort(all(edges));
        trav(E, edges) {
            if (dsu.comb(E.s.f, E.s.s)) cnt++, res += E.f;
        }
        if (cnt != n) return -1;
        return res;
    }
};

int main() {
    setIO("");

    int n, m; cin >> n >> m;

    const int MX2 = 1e5+5;
    MST<MX2> mst;
    F0R(i,m) {
        int a,b,c; cin >> a >> b >> c;
        mst.ae(a,b,c);
    }
    ll res = mst.calc(n);
    if (res == -1) cout <<"IMPOSSIBLE";
    else cout << res;

}