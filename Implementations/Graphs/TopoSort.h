struct TopoSort {
    int N, *w; vi *g, r;
    void init(int N) {
        this->N=N; g = new vi[N+1];
        w = new int[N+1]; }
    void ae(int a, int b) {
        g[a].pb(b); w[b]++; }
    bool sort() {
        queue<int> Q; r.clear();
        for(int i=1; i<=N; i++) if(!w[i]) {
            Q.push(i); }
        while(Q.size()) {
            int a=Q.front(); Q.pop(); r.pb(a);
            for(int b : g[a]) if(!--w[b]) {
                Q.push(b); }
        }
        return r.size()==N;
    }
};