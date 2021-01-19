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

void upd(int &gang, int &cow, int ncow) {
	if(cow == 0) gang = ncow;
	if (gang == ncow) cow++;
	else cow--;
}

int qry(int gang, int cow, vi c) {
	sort(c.begin() + 1, c.end());
	while(c.back() > 0) {
		for(int i=sz(c)-1; i>0; i--) {
			upd(gang, cow, i); c[i]--;
			if(c[i-1] <= c[i]) break;
		}
	}
	F0R(i, c[0]) upd(gang, cow, 0);
	if(gang == 0) return cow;
	else return 0;
}

int main() {

	int n, m; ri(n,m);
	vi c(m); trav(x,c) ri(x);
	int gang = 0, cow = 0;
	int res = qry(gang, cow, c);
	if(res) {
		ws("YES\n");
		wi(res); wc('\n');
		F0R(it, n) {
			int ogang = gang, ocow = cow;
			for(int i=0; ; i++) if(c[i]) {
				c[i]--;
				upd(gang, cow, i);
				if(res == qry(gang, cow, c)) {
					wi(i+1); wc('\n'); break;
				}
				c[i]++;
				gang = ogang, cow = ocow;
			}
		}
	} else {
		ws("NO\n");
	}
}