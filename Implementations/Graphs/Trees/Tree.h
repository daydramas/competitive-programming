struct Tree {

    int n; vi *g;
    Tree() {}
    Tree(int n) {
        this->n = n;
        g = new vi[n+1]; }
    void ae(int a, int b) {
        g[a].pb(b), g[b].pb(a); }
};