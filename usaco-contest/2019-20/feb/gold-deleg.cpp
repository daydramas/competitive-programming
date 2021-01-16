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

const int N = 1e5+5;

int n, s[N];
vi g[N], S[N];

int dfs(int a, int c) {
	s[a] = 1;
	trav(b, g[a]) if(b!=c) {
		s[a] += dfs(b, a);
		S[a].pb(s[b]);
	}
	if(a!=1) S[a].pb(n-s[a]);
	return s[a];
}
int um[N];
int c(int x) {
	F0R(i,x+1) um[i] = 0; 
	FOR(i,1,n) {
		int f = 0;
		trav(y, S[i]) {
			int z = y%x; if (z == 0) continue;
			if(um[x-z]) um[x-z]--, f++;
			else um[z]++, f--;  
		}
		if(f!=0) return 0;
	}
	return 1;
}
int main() {
	setIO("deleg");

	ri(n);
	F0R(i,n-1) {
		int a,b; ri(a,b);
		g[a].pb(b); g[b].pb(a);
	}
	dfs(1,1);
	FOR(i,1,n-1) {
		if((n-1) % i) cout << 0;
		else cout << c(i);
	}
	cout << '\n';

}