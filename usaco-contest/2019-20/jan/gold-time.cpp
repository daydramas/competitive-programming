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

const int N = 1005;
int n, m, c, v[N], dp[N][N*3];
vi g[N];

int main() {
	setIO("time");

	ri(n, m, c);
	FOR(i,1,n) ri(v[i]);
	F0R(i,m) {
		int a,b; ri(a,b);
		g[a].pb(b);	
	}
	dp[1][0] = 0;
	queue<pi> q; q.push({1,0});
	while(q.size()) {
		pi x = q.front(); q.pop();
		trav(y, g[x.f]) {
			int nc = dp[x.f][x.s] + v[y] + c * ( (x.s * x.s) - ((x.s+1) * (x.s+1)) );
			if(nc > dp[y][x.s+1]) {
				dp[y][x.s+1] = nc;
				q.push({y,x.s+1});
			}	
		}
	}
	int ans = 0;
	FOR(i,0,n*3) ans = max(ans, dp[1][i]);
	wi(ans); wc('\n');
}