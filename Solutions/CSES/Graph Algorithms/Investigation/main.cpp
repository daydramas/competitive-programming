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

template<int SZ> struct Dijkstra {
    using Node = pair<long long, int>;

    vector<Node> adj[SZ];
    long long dist[SZ];
    ll num[SZ]; int minp[SZ], maxp[SZ]; bool vis[SZ];

    Dijkstra() {}
    void edge(int i, int j, long long weight) {
        adj[i].pb({weight, j});
        // adj[j].pb({weight, i});
    }
    void calc(int src) {
        for(int i=0; i<SZ; i++)
            dist[i]=1e18, num[i]=minp[i]=maxp[i]=0, vis[i]=false;

        priority_queue<Node, vector<Node>, greater<Node> > PQ;
        PQ.push({dist[src]=0,src}); num[src]=1;
        while(!PQ.empty()) {
            Node F = PQ.top(); PQ.pop();
            if (F.f > dist[F.s]) continue;
            if (vis[F.s]) continue;
            vis[F.s]=true;
            for(auto &e : adj[F.s]) {
                if (dist[F.s]+e.f < dist[e.s]) {
                    dist[e.s]=dist[F.s]+e.f;
                    num[e.s] = num[F.s];
                    minp[e.s] = minp[F.s]+1;
                    maxp[e.s] = maxp[F.s]+1;
                    PQ.push({dist[e.s], e.s});
                } else if (dist[F.s]+e.f == dist[e.s]) {
                    num[e.s] = (num[F.s]+num[e.s]) % MOD;
                    minp[e.s] = min(minp[e.s], minp[F.s]+1);
                    maxp[e.s] = max(maxp[e.s], maxp[F.s]+1);
                    PQ.push({dist[e.s], e.s});
                }
            }
        }

    }
};

const int MAXN = 1e5+5;

Dijkstra<MAXN> ds;

int main() {
    setIO("");

    int n, m; cin >> n >> m;
    F0R(i,m) {
        int a,b,c; cin >> a >> b >> c;
        ds.edge(a,b,c);
    }
    ds.calc(1);
    cout << ds.dist[n]<<" "<<ds.num[n]<<" "<<ds.minp[n]<<" "<<ds.maxp[n];

}