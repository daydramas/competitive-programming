template<int SZ> struct TopoSort {
    vi adj[SZ], res; int w[SZ];
    TopoSort() {
        F0R(i,SZ) w[i]=0;
    }
    void ae(int a, int b) {
        adj[a].pb(b); w[b]++;
    }
    bool sort(int N) {
        queue<int> Q;
        FOR(i,1,N) if(!w[i]) Q.push(i);
        while(!Q.empty()) {
            int a=Q.front(); Q.pop(); res.pb(a);
            trav(b, a) if (!(--w[b])) Q.push(b);
        }
        return sz(res)==N;
    }
};