#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
#define f first
#define s second
#define pb push_back
#define all(x) begin(x), end(x)
#define rsz resize

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

/* SCC from BenQ */
struct SCC {
	int N; vector<vi> adj, radj;
	vi todo, comp, comps; vector<bool> vis;
	void init(int _N) { N = _N;
		adj.rsz(N), radj.rsz(N), comp = vi(N,-1), vis.rsz(N); }
	void ae(int x, int y) { adj[x].pb(y), radj[y].pb(x); }
	void dfs(int x) {
		vis[x] = 1; trav(y,adj[x]) if (!vis[y]) dfs(y);
		todo.pb(x); }
	void dfs2(int x, int v) {
		comp[x] = v;
		trav(y,radj[x]) if (comp[y] == -1) dfs2(y,v); }
	void gen() { // fills allComp
		F0R(i,N) if (!vis[i]) dfs(i);
		reverse(all(todo));
		trav(x,todo) if (comp[x] == -1) dfs2(x,x), comps.pb(x);
	}
};

int ID[200005];

int main() {

    int n, m; cin >> n >> m;

    int c=0;
    SCC scc; scc.init(n);
    F0R(i,m) {
        int a,b; cin >> a >> b;
        scc.ae(--a,--b);
    }
    scc.gen();
    F0R(i,n) if (!ID[scc.comp[i]]) ID[scc.comp[i]]=++c;
    cout << c <<"\n";
    F0R(i,n) cout << ID[scc.comp[i]]<<" ";
}