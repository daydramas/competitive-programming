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
#define bk back()
/* scc from benq */
struct SCC {
	int N, ti = 0; vector<vi> adj;
	vi disc, comp, st, comps;
	void init(int _N) { N = _N; adj.rsz(N), disc.rsz(N), comp = vi(N,-1); }
	void ae(int x, int y) { adj[x].pb(y); }
	int dfs(int x) {
		int low = disc[x] = ++ti; st.pb(x); // disc[y] != 0 -> in stack
		trav(y,adj[x]) if (comp[y] == -1) low=min(low,disc[y]?:dfs(y));
		if (low == disc[x]) { // make new SCC, pop off stack until you find x
			comps.pb(x); for (int y = -1; y != x;)
				comp[y = st.bk] = x, st.pop_back();
		}
		return low;
	}
	void gen() {
		FOR(i,1,N-1) if (!disc[i]) dfs(i);
		reverse(all(comps));
	}
};

SCC G;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m; cin >> n >> m;
    G.init(n+1);
    while(m--) {
        int a, b; cin >> a >> b;
        G.ae(a, b);
    }
    G.gen();
    vi *t = new vi[n+1];
    FOR(i,1,n) t[G.comp[i]].pb(i);
    int a=0; trav(x, G.comps) if(t[x].size()-1) a++;
    cout << a << '\n';
}