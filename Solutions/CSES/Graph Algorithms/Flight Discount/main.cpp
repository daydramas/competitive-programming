#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef string str;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<str> vs;

#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define pb push_back

#define for0(a,n) for(int a = 0; a < (n); ++a)
#define for1(a,n) for(int a = 1; a <= (n); ++a)
#define rof0(a,n) for(int a = (n-1); a >= 0; --a)
#define rof1(a,n) for(int a = (n); a >= 1; --a)
#define trav(a,x) for (auto& a: x)

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
const ll INF = 1e18;
const double PI = acos(-1);
const int X[4] = {1,0,-1,0}, Y[4] = {0,1,0,-1};

/* Source: Benq (https://github.com/bqi343/USACO) [Modified] */

template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

namespace IO {
    void setIO(string PROB = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (sz(PROB)) {
            freopen((PROB+".in").c_str(),"r",stdin);
            freopen((PROB+".out").c_str(),"w",stdout);
        }
    }

    /* Input */
    template<class A, class B> void re(pair<A,B>& p);
    template<class A> void re(vector<A>& v);
    template<class T> void re(T& x) { cin >> x; }
    template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }
    template<class A, class B> void re(pair<A,B>& p) { re(p.f,p.s); }
    template<class A> void re(vector<A>& x) { trav(a,x) re(a); }

    /* To String */
    str ts(ll i) { return to_string(i); }
    str ts(bool b) { return b ? "true" : "false"; }
    str ts(char c) { str s=""; s+=c; return s; }
    str ts(str s) { return s; }
    str ts(const char* s) { return (str)s; }
    template<class T> str ts(vector<T> v) {
        bool fst=1; str res="{";
        trav(a, v) {
            if (!fst) res += ", ";
            fst = 0; res += ts(a);
        }
        res+="}"; return res;
    }

    /* Output */
    template<class A> void pr(A x) { cout << ts(x); }
    template<class H, class... T> void pr(const H& h, const T&... t) {
        pr(h); pr(t...); }
    void pl() { cout << "\n"; }
}
using namespace IO;

/* ============================ */

template<int SZ> struct Dijkstra {
    using Node = pair<long long, int>;

    vector<Node> adj[SZ];
    long long dist[SZ];

    Dijkstra() {}
    void edge(int i, int j, long long weight) {
        adj[i].pb({weight, j});
        // adj[j].pb({weight, i});
    }
    void calc(int src) {
        for(int i=0; i<SZ; i++) dist[i]=1e18;

        priority_queue<Node, vector<Node>, greater<Node> > PQ;
        PQ.push({dist[src]=0,src});
        while(!PQ.empty()) {
            Node F = PQ.top(); PQ.pop();
            if (F.f > dist[F.s]) continue;
            for(auto &e : adj[F.s]) {
                if (dist[F.s]+e.f < dist[e.s])
                    PQ.push({dist[e.s]=dist[F.s]+e.f, e.s});
            }
        }

    }
};

int main() {
    setIO("");

    int n, m; re(n, m);
    Dijkstra<100005> dj1, dj2;
    for0(i,m) {
        int a,b,c; re(a,b,c);
        dj1.edge(a,b,c);
        dj2.edge(b,a,c);
    }
    dj1.calc(1); dj2.calc(n);
    ll ans=INF;
    for1(i,n) if(dj1.dist[i]!=INF)
        trav(_,dj1.adj[i]) {
            int j=_.s;
            if (dj2.dist[j]==INF) continue;
            ckmin(ans, dj1.dist[i]+dj2.dist[j]+_.f/2);
        }
    pr(ans);

}