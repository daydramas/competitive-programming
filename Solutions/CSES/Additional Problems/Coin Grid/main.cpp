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

/* source: benq */
#define rsz resize
vi ans;
struct Dinic {
	using F = ll; // flow type
	struct Edge { int to, rev; F flo, cap; };
	int N; vector<vector<Edge>> adj;
	void init(int _N) { N = _N; adj.rsz(N); }
	/// void reset() { F0R(i,N) trav(e,adj[i]) e.flo = 0; }
	void ae(int a, int b, F cap, F rcap = 0) { assert(min(cap,rcap) >= 0);
		adj[a].pb({b,sz(adj[b]),0,cap});
		adj[b].pb({a,sz(adj[a])-1,0,0});
	}
	vi lev, ptr;
	bool bfs(int s, int t) { // level = shortest distance from source
		// lev = ptr = vi(N);
         ptr = vi(N); lev = vi(N,-1);
		lev[s] = 1; queue<int> q({s});
		while (sz(q)) { int u = q.front(); q.pop();
			trav(e,adj[u]) if (e.flo < e.cap && lev[e.to]==-1)
				q.push(e.to), lev[e.to] = lev[u]+1;
		}
		return lev[t]>0;
	}
    bool bfs2(int s, int t) {
        // lev = ptr = vi(N);
        ptr = vi(N); lev = vi(N,-1);
        lev[s] = 1; queue<int> q({s});
		while (sz(q)) { int u = q.front(); q.pop();
			trav(e,adj[u]) if (lev[e.to] == -1 && e.flo > 0)
				q.push(e.to), lev[e.to] = lev[u]+1;
		}
        return lev[t];
    }
	F dfs(int v, int t, F flo) {
		if (v == t) return flo;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i]; F dif = e.cap-e.flo;
			if (lev[e.to]!=lev[v]+1||!dif) continue;
			if (F df = dfs(e.to,t,min(flo,dif))) {
				e.flo += df; adj[e.to][e.rev].flo -= df;
				return df; } // saturated >=1 one edge
		}
		return 0;
	}
     bool dfs2(int v, int t) {
        if (v == t) { ans.pb(v); return 1; }
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lev[e.to]!=lev[v]+1||e.flo<=0) continue;
			if (dfs2(e.to,t)) {
                ans.pb(v); e.flo=0;
				return 1; }
		}
        return 0;
    }
	F maxFlow(int s, int t) {
		F tot = 0; while (bfs(s,t)) while (F df =
			dfs(s,t,numeric_limits<F>::max())) tot += df;
		return tot;
	}
};

int n, m;
Dinic D;

int main() {

    cin >> n;
    D.init(2*n+2);
    FOR(i,1,n) FOR(j,1,n) {
        char c; cin >> c;
        if(c=='o') D.ae(i,j+n,1);
    }
    FOR(i,1,n) D.ae(0,i,1);
    FOR(i,n+1,n+n) D.ae(i,n+n+1,1);
    cout << D.maxFlow(0, n+n+1) <<"\n";
    D.bfs(0, n+n+1); // generate levels
    trav(t,D.adj[0]) if (D.lev[t.to] < 0 && t.flo > 0) cout << "1 " << t.to <<"\n";
    FOR(i,n+1,2*n+1) trav(t,D.adj[i]) if (t.to == 2*n+1 && D.lev[i] >= 0 && t.flo > 0) cout << "2 "<<i-n<<"\n";
    // FOR(i,1,n) trav(e, D.adj[i]) if (e.flo > 0)cout<<i<<" "<<e.to<<"\n";// cout<<"1 "<<i<<"\n";
    // cout << D.maxFlow(0, n+n+1);

}