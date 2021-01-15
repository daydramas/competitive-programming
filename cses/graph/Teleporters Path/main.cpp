#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
#define f first
#define s second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

/* source: bqi343 */

using pi = pair<int, int>;
using vb = vector<bool>;
using vpi = vector<pi>;
template<class T> using V = vector<T>;

#define begin(x) (x).begin()
#define end(x) (x).end()
#define eb emplace_back
#define bk back()
#define rsz resize

template<bool directed> struct Euler {
    int N; V<vpi> adj; V<vpi::iterator> its; vb used;
    void init(int _N) { N = _N; adj.rsz(N); }
    void ae(int a, int b) {
        int M = sz(used); used.pb(0);
        adj[a].eb(b,M); if (!directed) adj[b].eb(a,M); }
    vpi solve(int src = 0) {
        its.rsz(N); F0R(i,N) its[i] = begin(adj[i]);
        vpi ans, s{{src,-1}}; // {{vert, prev vert}, edge label}
        int lst = -1; // ans is generated in reverse order
        while (sz(s)) {
            int x = s.bk.f; auto& it = its[x], en = end(adj[x]);
            while (it != en && used[it->s]) it ++;
            if (it == en) { // no more edges out of vertex
                if (lst != -1 && lst != x) return {}; // not a path, no tour exists
                ans.pb(s.bk); s.pop_back(); if (sz(s)) lst = s.bk.f;
            } else s.pb(*it), used[it->s] = 1;
        }
        if (sz(ans) != sz(used)+1) return {}; // not all edges used
        reverse(all(ans)); return ans;
    }
};

void ri (int &x) {
    int c; x = 0;
    c=getchar_unlocked();
    for(; c>='0' && c <='9'; c=getchar_unlocked())
        x = 10*x + c-'0';
}
inline void wi(int x) {
	if (x <= 9)
		putchar_unlocked('0' + x);
	else {
		wi(x / 10);
		putchar_unlocked('0' + x % 10);
	}
}

int main() {

    int n,m; ri(n); ri(m); //cin >> n >> m;
    Euler<true> e; e.init(n);
    F0R(i,m) {
        int a,b; ri(a); ri(b);
        e.ae(--a,--b);
    }
    auto ans=e.solve();
    if (ans.empty() || (ans.back().f!=n-1)) {
        cout <<"IMPOSSIBLE";
    } else {
        trav(a, ans) wi(a.f+1), putchar_unlocked(' ');
    }

}