#include "Tree.h"

struct LCA {
    const int L = 30;
    int n, *d, **p; Tree t;
    LCA() {}
    LCA(int n) {
        this->n = n; t = Tree(n);
        d = new int[n+1]; p = new int*[n+1];
        for(int i=1; i<=n; i++) p[i] = new int[L]; }
    void ae(int a, int b) {
        t.ae(a,b); }
    void dfs(int a=1, int c=0) {
        if(a-1) d[a]=d[c]+1; p[a][0]=c;
        for(int b : t.g[a]) if(b!=c)
            dfs(b,a); }
    void gen() { dfs();
        for(int d=1; d<L; d++) for(int a=1; a<=n; a++)
            p[a][d]=p[p[a][d-1]][d-1]; }
    int jmp(int a, int D) { if(D<=0) return a;
        for(int i=0; i<L; i++) if((1<<i)&D) {
            a=p[a][i]; } return a;
    }
    int lca(int a, int b) { a = jmp(a,d[a]-d[b]);
        b = jmp(b,d[b]-d[a]); if(a==b) return a;
        for(int i=L-1; i>=0; i--) if(p[a][i]!=p[b][i]) {
            a=p[a][i]; b=p[b][i]; }
        if(a!=b) { a=p[a][0], b=p[b][0]; }
        return a;
    }
    int dist(int a, int b) {
        return d[a]+d[b]-2*d[lca(a,b)]; }
};