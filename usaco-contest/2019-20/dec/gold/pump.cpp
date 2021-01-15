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

const int maxn = 1005;
using E = pair<int, pi>;

int n, m;
vector<E> g[maxn];
int dp[maxn][maxn]; 

int main() {
	setIO("pump");

	ri(n,m);
	F0R(i,m) {
		int a, b, c, f;
		ri(a,b,c,f);
		g[a].pb({c,{b,f}});
		g[b].pb({c,{a,f}});
	}
	
	FOR(i,1,n) FOR(j,1,1000) dp[i][j]=1e9;
	priority_queue<E> pq;
	dp[1][1001] = 0; pq.push({-0, {1, 1001}});
	while(pq.size()) {
		E t = pq.top(); pq.pop();
		if(-t.f > dp[t.s.f][t.s.s]) continue;
		trav(e, g[t.s.f]) {
			int rf = min(t.s.s, e.s.s);
			int rc = -t.f + e.f;
			if(dp[e.s.f][rf] > rc) {
				dp[e.s.f][rf] = rc;
				pq.push({-rc, {e.s.f, rf}});
			}
		}
	}
	double ans = 0;
	FOR(j,1,1000) {
		if(dp[n][j] == 1e9) continue;
		ans = max(ans, 1.0 * j / dp[n][j]);
	}
	int res = ans * 1000000;
	wi(res); wc('\n');
}