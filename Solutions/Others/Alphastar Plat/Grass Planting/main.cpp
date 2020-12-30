#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int n, q, idc=1, id[maxn+5], d[maxn+5], l[maxn+5][30];
pair<int,int> iv[maxn+5];
vector<int> g[maxn+5];

/* lseg */
using T = long long;
T st[(maxn+5)*4], lz[(maxn+5)*4];
T ID=0; T comb(T i, T j) { return i+j; }
void init() {
	for(int i=0; i<maxn*4; i++) st[i]=lz[i]=ID; }
void pull(int i) {
	st[i] = comb(st[i*2],st[i*2+1]); }
void push(int i, int l, int r) {
	st[i]+=(r-l+1)*lz[i];
	if(l!=r) lz[i*2]+=lz[i], lz[i*2+1]+=lz[i];
	lz[i]=0;
}
void upd(int L, int R, T v, int i=1, int l=0, int r=maxn) {
	push(i,l,r); if(R<l || L>r) return;
	if(L<=l && R>=r) { lz[i]=v; push(i,l,r); return; }
	int m=(l+r)/2; upd(L,R,v,i*2,l,m);
	upd(L,R,v,i*2+1,m+1,r); pull(i);
}
T qry(int L, int R, int i=1, int l=0, int r=maxn) {
	push(i,l,r); if(R<l || L>r) return ID;
	if(L<=l && R>=r) return st[i]; int m=(l+r)/2;
	return comb(qry(L,R,i*2,l,m), qry(L,R,i*2+1,m+1,r));
}

/* preorder */
void dfs(int a, int c) {
    l[a][0]=c, d[a]=d[c]+1; id[a]=iv[a].first=idc++;
    for(int b : g[a]) if(b!=c) dfs(b,a);
    iv[a].second=idc-1;
}
/* lca */
int lca(int u, int v) {
    if(d[u] > d[v]) swap(v, u);
    int D = d[v] - d[u];
    for(int i = 0; i < 30; i++) {
        if(D & (1 << i)) {
            v = l[v][i];
        }
    }
    if(u == v) return u;
    for(int i=29; i>=0; i--) {
        if(l[u][i] != l[v][i]) {
            u = l[u][i];
            v = l[v][i];
        }
    }
    return l[u][0];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for(int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    d[1]=-1; init(); dfs(1,1);
    for(int i=1; i<30; i++) for(int j=1; j<=n; j++)
        l[j][i]=l[l[j][i-1]][i-1];
    while(q--) {
        char t; int a, b;
        cin >> t >> a >> b;
        int c = lca(a, b);
        if(t == 'P') {
            upd(id[a], id[a], 1);
            upd(id[b], id[b], 1);
            upd(id[c], id[c], -2);
        } else {
            if(d[a]<d[b]) swap(a,b);
            cout << qry(iv[a].first,iv[a].second) << '\n';
        }
    }
}