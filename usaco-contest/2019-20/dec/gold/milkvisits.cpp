#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int,int>;
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

namespace IO {
	/* INPUT */
	char nc() { return getchar_unlocked(); }
	void rs(string& x) {
		char ch; x=""; while (isspace(ch = nc()));
		do { x += ch; } while (!isspace(ch = nc()) && ch != EOF); }
	template<class T> void ri(T &x) {
		int sgn=1; char ch; x=0;
		while (!isdigit(ch = nc())) if (ch == '-') sgn *= -1;
		x = ch-'0'; while (isdigit(ch = nc())) x = x*10+(ch-'0');
		x *= sgn; }
	template<class T, class... Ts> void ri(T& t, Ts&... ts) {
		ri(t); ri(ts...); }
	/* OUTPUT */
	void wc(char ch) { putchar_unlocked(ch); }
	void ws(string x) { for(char ch : x) wc(ch); }
	template<class T> inline void wi(T x) {
		if(x < 0) x*=-1, wc('-');
		if(0 <= x && x <= 9) wc('0'+x);
		else wi(x/10), wc('0'+x%10); }
};
using namespace IO;

void setIO(string s = "") {
	cin.tie(0)->sync_with_stdio(0); if (s.size()) {
		freopen((s+".in").c_str(), "r", stdin);
		freopen((s+".out").c_str(), "w", stdout); }
}

const int maxn = 1e5+5;
struct QRY { int a, b, c; };
int n, m, c[maxn], ans[maxn], l[maxn][20], d[maxn], boi=0;
QRY f[maxn];
vi g[maxn];
pi r[maxn]; vector<pi> t[maxn];
stack<int> p[maxn];	 

void dfs(int a, int c, int D=0) {
	r[a].f = ++boi; l[a][0]=c; d[a]=D;
	trav(b,g[a]) if(b!=c) dfs(b,a,D+1);
	r[a].s = boi;
}
bool ANS(int a, int b) {
	return r[a].f <= r[b].f && r[b].s <= r[a].s;
}
int jmp(int a, int d) {
	for(int i=19; i>=0; i--) if(d&(1<<i))
		a = l[a][i]; return a; }
int lca(int a, int b) {
	if(a==b) return a;
	if(d[a] < d[b]) swap(a,b);
	a = jmp(a, d[a]-d[b]);
	if(a==b) return a;
	for(int i=19; i>=0; i--) if(l[a][i] != l[b][i]) {
		a=l[a][i]; b=l[b][i]; }
	if(a!=b) a=l[a][0], b=l[b][0]; return a; }
void dfs2(int x, int z) {
	p[c[x]].push(x);
	for(pi tmp : t[x]) {
		int i=tmp.f, y=tmp.s;
		QRY q = f[i];
		if(p[q.c].empty()) continue;
		int a = p[q.c].top();
		if(ANS(lca(x,y), a)) {
			ans[i]=1;
		}
	}
	trav(b,g[x]) if(b!=z) dfs2(b,x);
	p[c[x]].pop();
}
int main() {
	setIO("milkvisits");

	ri(n,m);
	FOR(i,1,n) ri(c[i]);
	F0R(i,n-1) {
		int a,b; ri(a,b);
		g[a].pb(b);
		g[b].pb(a);
	}
	FOR(i,1,m) {
		ans[i] = 0;
		int a,b,c; ri(a,b,c);
		f[i] = {a,b,c};
		t[a].pb({i,b}); t[b].pb({i,a});
	}
	dfs(1,1);
	FOR(i,1,19) FOR(j,1,n) l[j][i] = l[l[j][i-1]][i-1];
	dfs2(1,-1);
	FOR(i,1,m) wi(ans[i]);
}