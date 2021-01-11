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

int n, k; string s;
vi ps, dp;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using T = int; T U = 1e9;
T F(T a, T b) { return min(a,b); }

struct SegNode {
	multiset<T> os; struct SegNode* C[2];
	T get() { if(os.empty()) return U;
			else return *os.begin(); }
	SegNode() { C[0] = C[1] = nullptr; }
	SegNode* c(int i) {
		if(!C[i]) C[i] = new SegNode();
		return C[i]; }
	void upd(int qi, T qv, int inc, int l, int r) {
		if(inc) os.insert(qv);
		else os.erase(os.find(qv));
		if(l==r) { return; }
		int m = (l+r)/2;
		if(qi <= m) c(0)->upd(qi,qv,inc,l,m);
		else c(1)->upd(qi,qv,inc,m+1,r);}
	T qry(int ql, int qr, int l, int r) {
		if(ql <= l && r <= qr) return this->get();
		else if(qr < l || ql > r) return U;
		int m = (l+r)/2;
		T L = U; if(C[0]) L=C[0]->qry(ql,qr,l,m);
		T R = U; if(C[1]) R=C[1]->qry(ql,qr,m+1,r);
		return min(L,R); }
};

map<int,int> M;
SegNode* root = new SegNode();

int main() {

	ri(n, k); rs(s); ps = {n+1}; dp = {0}; M[n+1]=1;
	trav(c,s) {
		ps.pb(ps.back()+(c=='H'?-1:1));
		M[ps.back()]=1;
	}
	int c=0; trav(x,M) M[x.f]=++c;
	trav(x,ps) x=M[x];

	root->upd(ps[0],0,1,1,c);
	FOR(i,1,n) {
		int l = root->qry(1,ps[i],1,c)+1;
		int r = root->qry(ps[i]+1,c,1,c);
		dp.pb(min(l,r));
		root->upd(ps[i],dp[i],1,1,c);
		if(i>=k) root->upd(ps[i-k],dp[i-k],0,1,c);
	}
	wi(dp[n]); wc('\n');
}