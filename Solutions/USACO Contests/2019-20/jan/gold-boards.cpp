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

using T = int; T U = 0;
T F(T a, T b) { return min(a,b); }

struct SegNode {
	T v; struct SegNode* C[2];
	SegNode() { v=U; C[0] = C[1] = nullptr; }
	SegNode* c(int i) {
		if(!C[i]) C[i] = new SegNode();
		return C[i]; }
	void upd(int qi, T qv, int l, int r) {
		if(l==r) { v = F(v, qv); return; }
		int m = (l+r)/2;
		if(qi <= m) c(0)->upd(qi,qv,l,m);
		else c(1)->upd(qi,qv,m+1,r);
		v = F((C[0] ? C[0]->v : U), 
			(C[1] ? C[1]->v : U)); } 
	T qry(int ql, int qr, int l, int r) {
		if(ql <= l && r <= qr) return v;
		else if(qr < l || ql > r) return U;
		int m = (l+r)/2;
		return F((C[0] ? C[0]->qry(ql,qr,l,m) : U), 
				(C[1] ? C[1]->qry(ql,qr,m+1,r) : U)); }
};

using pp = pair<pi,pi>;

int n, p; int ans[100005];
vector<pp> G;
SegNode *root;

int main() {
	setIO("boards");

	ri(n,p);
	root = new SegNode();
	root->upd(0, 0, 0, n);
	FOR(i,1,p) {
		int a,b,c,d; ri(a,b,c,d);
		G.pb({{a,b},{1,i}});
		G.pb({{c,d},{0,i}});
		ans[i] = (a+b)-(c+d);
	}
	sort(all(G));
	trav(x, G) {
		int i = x.s.s;
		if(x.s.f) {
			ans[i] += root->qry(0, x.f.s, 0, n);
		} else {
			root->upd(x.f.s, ans[i], 0, n);
		}
	}
	ll res = root->qry(0, n, 0, n) + (n+n);
	wi(res); wc('\n');
}