/*
============================================================================
 Name:		problem
 Link:		link
 Author:	Dong Liu
 Date:		2021-02-08
============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

#define F           first
#define S           second
#define PB          push_back
#define ALL(x)      begin(x), end(x)
#define SZ(x)       int((x).size())
#define FOR(i,a,b)  for(int i=(a); i<=(b); i++)
#define F0R(i,x)    FOR(i,0,(x)-1)
#define ROF(i,a,b)  for(int i=(b); i>=(a); i--)
#define R0F(i,x)    ROF(i,0,(x)-1)
#define REP(x)      F0R(_,x)
#define EACH(a,x)   for(auto& a: x)

struct SCC {
    int N, ti = 0; vector<vector<int>> adj;
    vector<int> disc, comp, st, comps;
    void init(int _N) { 
        N = _N; 
        adj.resize(N), disc.resize(N), comp = vector<int>(N,-1); 
    }
    void ae(int x, int y) { 
        adj[x].push_back(y); 
    }
    int dfs(int x) {
        int low = disc[x] = ++ti; st.push_back(x); // disc[y] != 0 -> in stack
        for(int y : adj[x]) if (comp[y] == -1) low = min(low, disc[y]?:dfs(y)); 
        if (low == disc[x]) { // make new SCC, pop off stack until you find x
            comps.push_back(x); for (int y = -1; y != x;) 
                comp[y = st.back()] = x, st.pop_back();
        }
        return low;
    }
    void gen() {
        for(int i=0; i<N; i++) if (!disc[i]) dfs(i);
        reverse(begin(comps), end(comps));
    }
};

SCC scc;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m, l, f;
	cin >> n >> m >> l >> f;
	vector<int> a(f);
	vector<int> b(l+1);
	EACH(x, a) cin >> x;
	EACH(x, a) b[x]++;
	scc.init(l+1);
	FOR(i,0,l) {
		if(i+n <= l) scc.ae(i,i+n);
		if(i-m >= 0) scc.ae(i,i-m);
	}
	scc.gen();
	vector<int> dp(l+1, -1e9);
	dp[scc.comp[0]] = 0;
	vector<int> g[l+1];
	FOR(i,0,l) EACH(j,scc.adj[i]) {
		if(scc.comp[i] == scc.comp[j]) continue;
		g[i].PB(j);
	}
	int ans = 0;
	EACH(x, scc.comps) {
		ans = max(ans, DP[x])
	}


}