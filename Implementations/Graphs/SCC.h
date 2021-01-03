struct SCC {
	int N; vi *g, *rg;
	vi td, cmps; int *cmp; bool *v;
	void init(int N) { this->N = N;
        g = new vi[N+1], cmp = new int[N+1];
        rg = new vi[N+1], v = new bool[N+1]; }
	void ae(int x, int y) {
        g[x].pb(y), rg[y].pb(x); }
	void t1(int x) { v[x]=1;
        trav(y,g[x]) if(!v[y]) t1(y);
		td.pb(x); }
	void t2(int x, int z) { cmp[x]=z;
		trav(y,rg[x]) if(!cmp[y]) t2(y,z); }
	void scc() {
		FOR(i,1,N) if(!v[i]) t1(i); reverse(all(td));
		trav(x,td) if(!cmp[x]) t2(x,x), cmps.pb(x);
	}
};