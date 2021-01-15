#include <bits/stdc++.h>
using namespace std;

/* source: benq */
template<class T> using V = vector<T>;
using vpi = vector<pair<int,int>>;
using vi = vector<int>;
#define rsz resize
// #define back() back()
#define eb emplace_back
#define pb push_back
#define sz(x) (int)(x).size()
template<class T> void ckmin(T &a, T b) { a = min(a, b); }
#define trav(a, x) for(auto &a : x)
#define f first
#define s second

struct BCC {
	V<vpi> adj; vpi ed;
	V<vi> comps, vertSets; // edges for each bcc
	int N, ti = 0; vi disc, st;
	void init(int _N) { N = _N; disc.rsz(N), adj.rsz(N); }
	void ae(int x, int y) {
		adj[x].eb(y,sz(ed)), adj[y].eb(x,sz(ed)), ed.eb(x,y); }
	int dfs(int x, int p = -1) { // return lowest disc
		int low = disc[x] = ++ti;
		trav(e,adj[x]) if (e.s != p) {
			if (!disc[e.f]) {
				st.pb(e.s); // disc[x] < LOW -> bridge
				int LOW = dfs(e.f,e.s); ckmin(low,LOW);
				if (disc[x] <= LOW) { // get edges in bcc
					comps.eb(); vi& tmp = comps.back(); // new bcc
					for (int y = -1; y != e.s; )
						tmp.pb(y = st.back()), st.pop_back();
				}
			} else if (disc[e.f] < disc[x]) // back-edge
				ckmin(low,disc[e.f]), st.pb(e.s);
		}
		return low;
	}
	void gen() {
		for(int i=0; i<N; i++) if (!disc[i]) dfs(i);
		vector<bool> in(N);
		trav(c,comps) { // vertices contained within each BCC
			vertSets.eb(); // so you can easily create block cut tree
			auto ad = [&](int x) { if (!in[x]) in[x] = 1, vertSets.back().pb(x); };
			trav(e,c) ad(ed[e].f), ad(ed[e].s);
			trav(e,c) in[ed[e].f] = in[ed[e].s] = 0;
		}
	}
};

const int maxn = 1e5;
int n, m, q;
BCC G;

vi adj[maxn*2];
int lca[maxn*2][25], d[maxn*2];
void dfs(int cur, int par=-1) {
    for(auto nex : adj[cur]) if(nex!=par) {
        lca[nex][0] = cur;
        d[nex] = d[cur]+1;
        dfs(nex, cur);
    }
}
int LCA(int u, int v) {
    if(d[u] > d[v]) swap(v, u);
    int D = d[v] - d[u];
    for(int i = 0; i < 25; i++) {
        if(D & (1 << i)) {
            v = lca[v][i];
        }
    }
    if(u == v) return u;
    for(int i=24; i>=0; i--) {
        if(lca[u][i] != lca[v][i]) {
            u = lca[u][i];
            v = lca[v][i];
        }
    }
    return lca[u][0];
}
int qry(int a, int b) {
    int c = LCA(a,b);
    return d[a]+d[b]-2*d[c];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> q;
    G.init(n);
    while(m--) {
        int a,b; cin >> a >> b;
        G.ae(--a,--b);
    }
    G.gen();
    int I=0; trav(x, G.vertSets) {
        map<int,bool> M;
        trav(y, x) M[y]=1;
        trav(y, M) {
            adj[y.f].pb(n+I);
            adj[n+I].pb(y.f);
        }
        I++;
    }
    // cout <<"gonna dfs..."<<endl;
    d[0]=0; dfs(0);
    for(int i=1; i<25; i++) for(int j=0; j<n+I; j++)
        lca[j][i] = lca[lca[j][i-1]][i-1];
    // cout <<"quering...\n";
    while(q--) {
        int a,b,c; cin >> a >> b >> c;
        --a, --b, --c;
        if(qry(a,c)+qry(c,b) != qry(a,b)) cout <<"YES\n";
        else cout <<"NO\n";
    }
}