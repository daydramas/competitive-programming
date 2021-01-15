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

int n, m, *c, x, *r, rr, k, kk; 

int main() {

	ri(n,m);
	c = new int[m+1];
	r = new int[n+1]; rr=0;
	FOR(i,1,m) ri(c[i]);

	while(n--) {
		x=-1;
		FOR(i,2,m) if(c[i] && (x==-1 || c[x]<c[i])) x=i;
		if(x==-1 || c[1]-1) x=1;
		if(x==-1) break;
		r[++rr]=x; c[x]--;
	}
	if(n > 0) {
		ws("NO\n");
	} else {
		ws("YES\n"); k=1, kk=1;
		for(int i=2; i<=rr; i++) 
			if(r[i]==r[i-1]) k=max(k,++kk);
			else kk=1;
		wi(k); wc('\n');
		for(int i=1; i<=rr; i++) { wi(r[i]); wc('\n'); }
	}
}