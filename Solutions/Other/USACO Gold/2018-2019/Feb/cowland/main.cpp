#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
#define f first
#define s second
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

const int maxn = 1e5+5;
int n, q, v[maxn], v2[maxn], d[maxn], lca[maxn][20];
vi adj[maxn];
pair<int,int> itv[maxn]; int t;


struct lazySegTree {

	int n; vi st, lz;

	void rsz(int n_) {
		n = n_;
		st.assign(4*n, 0);
		lz.assign(4*n, 0);
	}

	int left(int i) { return i*2; }
	int right(int i) { return i*2+1; }

	void propagate(int id, int L, int R) {
		st[id] ^= lz[id];
		if (L!=R) {
			lz[left(id)] ^= lz[id];
			lz[right(id)] ^= lz[id];
		}
		lz[id] = 0;
	}

	void upd(int id, int L, int R, int l, int r, int value) {
		if (lz[id]!=0) propagate(id, L, R);
		if (l > R || r < L) return;
		if (l <= L && R <= r) {
			lz[id] ^= value;
			propagate(id, L, R);
			return;
		}
		if (L == R) return;
		upd(left(id), L, (R+L)/2, l, r, value);
		upd(right(id), (R+L)/2+1, R, l, r, value);
		st[id] = st[left(id)] ^ st[right(id)];
	}

	void upd(int L, int R, int value) {
		upd(1, 1, n, L, R, value);
	}

	int qry(int id, int L, int R, int l, int r) {
		if (lz[id]!=0) propagate(id, L, R);
		if (l > R || r < L) return 0;
		if (l <= L && R <= r) return st[id];
		return qry(left(id), L, (R+L)/2, l, r) ^ qry(right(id), (R+L)/2+1, R, l, r);
	}

	int qry(int L, int R) {
		return qry(1, 1, n, L, R);
	}
};

lazySegTree st;

void dfs(int par, int cur, int dep) {
	v2[cur] = v2[par] ^ v[cur];
	d[cur]=dep;
	st.upd(t, t, v2[cur]);
	itv[cur].f = t++;
	lca[cur][0]=par;
	trav(nex, adj[cur]) if(nex!=par) dfs(cur, nex, dep+1);
	itv[cur].s = t-1;
}
int jmp(int x, int d) {
		F0R(i,20) if ((1<<i)&d) x = lca[x][i];
		return x; }
int LCA(int x, int y) {
	if (d[x] < d[y]) swap(x,y);
	x = jmp(x,d[x]-d[y]); if (x == y) return x;
	R0F(i,20) {
		int X = lca[x][i], Y = lca[y][i];
		if (X != Y) x = X, y = Y;
	}
	return lca[x][0];
}
int main() {

	ifstream fin("cowland.in");
	ofstream fout("cowland.out");

	fin >> n >> q;
	FOR(i,1,n) fin >> v[i];
	F0R(i,n-1) {
		int a,b; fin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	st.rsz(n+1); t=1, v2[0]=0; dfs(0, 1, 0);
	FOR(j,1,19) FOR(i,1,n) lca[i][j] = lca[lca[i][j-1]][j-1];
	F0R(i,q) {
		int t, a, b; fin >> t >> a >> b;
		if(t==1) { // upd
			st.upd(itv[a].f, itv[a].s, v[a]); v[a]=b;
			st.upd(itv[a].f, itv[a].s, v[a]);
		} else { // qry
			if (a==b) { fout << v[a] <<"\n"; continue; }
			int c = LCA(a,b);
			// cout <<"lca("<<a<<","<<b<<") = "<<c<<"\n";
			// cout << st.qry(a,a) <<" ^ "<<st.qry(b,b) <<" ^ "<<st.qry(c,c)<<"\n";
			fout << (st.qry(itv[a].f,itv[a].f) ^ st.qry(itv[b].f,itv[b].f) ^ v[c]) <<"\n";
		}
	}
}
