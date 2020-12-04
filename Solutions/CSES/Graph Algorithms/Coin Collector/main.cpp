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
	vi todo, comp; vector<bool> vis;
	void init(int _N) { N = _N;
		adj.rsz(N), radj.rsz(N), comp = vi(N,-1), vis.rsz(N); }
	void ae(int x, int y) { adj[x].pb(y), radj[y].pb(x); }
	void dfs(int x) {
		vis[x] = 1; trav(y,adj[x]) if (!vis[y]) dfs(y);
		todo.pb(x); }
	void dfs2(int x, int v) {
		comp[x] = v;
		trav(y,radj[x]) if (comp[y] == -1) dfs2(y,v); }
	void gen(int _N) { // fills allComp
		FOR(i,1,_N) if (!vis[i]) dfs(i);
		reverse(all(todo));
		trav(x,todo) if (comp[x] == -1) dfs2(x,x);
	}
};

const int maxn = 1e5+5;
int n,en,m;
vi e1[maxn], e2[maxn];
SCC scc; // scc
int v[maxn];
ll gv[maxn]; // group value
ll dp[maxn];

int id(int i) {
    return scc.comp[i];
}
ll dfs(int i) {
    if (dp[i]==-1) {
        // cout <<"base case: dp["<<i<<"] = "<<gv[i]<<"\n";
        dp[i]=gv[i];
        trav(j, e2[i]) {
            ll bf=dfs(j);
            dp[i]=max(dp[i],bf+gv[i]);
            // cout <<"ckmax(dp["<<i<<"], "<<bf<<"+"<<gv[i]<<"\n";
        }
    }
    // cout <<"dp["<<i<<"] = "<<dp[i]<<"\n";

    return dp[i];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> en;
    scc.init(n+1);

    FOR(i,1,n) { cin >> v[i]; }
    F0R(i,en) {
        int a,b; cin >> a >> b;
        e1[a].pb(b);
        scc.ae(a,b);
    }
    scc.gen(n);
    // cout <<"hi\n"; return 0;
    m=0;
    FOR(i,1,n) dp[i]=-1;
    FOR(i,1,n) { gv[id(i)]+=v[i]; }
    FOR(i,1,n) trav(j,e1[i]) {
        if (id(i) == id(j)) continue;
        e2[id(j)].pb(id(i));
        // cout <<id(j)<<" -> "<<id(i)<<"\n";
    }
    FOR(i,1,n) dfs(i);
    ll ans=0;
    FOR(i,1,n) ans=max(ans, dp[i]);
    cout << ans;
    cout.flush(); //cout <<endl;
}