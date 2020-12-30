#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
#define pb push_back

struct query { char t; int v; };
int q, c, p[maxn][25], d[maxn], v[maxn];
vector<query*> Q;
vector<int> E[maxn];

void dfs(int a, int c=-1) {
    v[a]=1;
    for(int b : E[a]) if(b!=c)
        p[b][0]=a, d[b]=d[a]+1, dfs(b, a);
}
int lca(int u, int v) {
    if(d[u] > d[v]) swap(v, u);
    int D = d[v] - d[u];
    for(int i = 0; i < 25; i++) {
        if(D & (1 << i)) {
            v = p[v][i];
        }
    }
    if(u == v) return u;
    for(int i=24; i>=0; i--) {
        if(p[u][i] != p[v][i]) {
            u = p[u][i];
            v = p[v][i];
        }
    }
    return p[u][0];
}
int D[maxn], d1[maxn], d2[maxn];
void init() { for(int i=0; i<maxn; i++) D[i]=-1; }
int par(int x) { return D[x]<0 ? x : D[x]=par(D[x]); }
bool comb(int x, int y) {
    x=par(x), y=par(y); if(x==y) return 0;
    D[x]+=D[y], D[y]=x; return 1;
}
int gd(int a, int b) {
    // if(par(a) != par(b)) return 0;
    int c = lca(a, b);
    return d[a]+d[b]-2*d[c];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> q; c=0; init();
    for(int i=0; i<q; i++) {
        query* x = new query();
        cin >> x->t >> x->v; Q.pb(x);
        if(x->t == 'B') c++;
        if(x->t == 'B' && x->v != -1) {
            E[x->v].pb(c), E[c].pb(x->v);
            comb(x->v, c);
        }
    }
    for(int i=1; i<=c; i++) v[i]=0;
    for(int i=1; i<=c; i++) if(!v[i]) {/* cout <<"dfsing from "<<i<<endl; */d[i]=0, dfs(i);  }
    for(int i=1; i<25; i++)
    for(int j=1; j<=c; j++) p[j][i]=p[p[j][i-1]][i-1];
    for(int i=1; i<=c; i++) if(D[i]<0) d1[i]=d2[i]=i;
    c=0;
    for(query* x : Q) {
        if(x->t == 'B') {
            ++c;
            // if(x->v != -1) {
                int D1 = gd(c, d1[par(c)]);
                int D2 = gd(c, d2[par(c)]);
                if(D1 > gd(d1[par(c)],d2[par(c)]) && D1 > D2) d2[par(c)]=c;
                else if(D2 > gd(d1[par(c)],d2[par(c)])) d1[par(c)]=c;
            // }
        } else {
            cout << max(gd(x->v, d1[par(x->v)]), gd(x->v, d2[par(x->v)])) << '\n';
        }
    }
}