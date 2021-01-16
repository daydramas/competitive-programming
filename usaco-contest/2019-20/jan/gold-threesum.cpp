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

const int N = 5005;

int n, q, v[N];
ll dp[N][N], m[2000005];

int main() {
	setIO("threesum");

	ri(n,q);
	FOR(i,1,n) { ri(v[i]); }
	FOR(i,1,n) FOR(j,i,n) dp[i][j] = 0;

	ROF(i,1,n)  {
		FOR(j,i+1,n) {
			int Q = 1e6 - (v[i] + v[j]);
			if(Q >= 0 && Q <= 2e6) dp[i][j] = m[Q];
			m[int(1e6 + v[j])]++;
		}
		FOR(j,i+1,n) m[int(1e6 + v[j])]--;
	}
	ROF(i,1,n) FOR(j,i+1,n) {
		dp[i][j] += dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]; 
	}
	F0R(i,q) {
		int a, b; ri(a,b);
		wi(dp[a][b]); wc('\n');
	}
}