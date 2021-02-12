/*
============================================================================
 Name:		problem
 Link:		link
 Author:	Dong Liu
 Date:		2021-02-11
============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
template<class T> using V = vector<T>;
template<class T, class U> using PR = pair<T, U>;

#define F           first
#define S           second
#define PB          push_back
#define ALL(x)      begin(x), end(x)
#define SZ(x)       int((x).size())
#define FOR(i,a,b)  for(int i=(a); i<=(b); ++i)
#define F0R(i,x)    FOR(i,0,(x)-1)
#define ROF(i,a,b)  for(int i=(b); i>=(a); --i)
#define R0F(i,x)    ROF(i,0,(x)-1)
#define REP(x)      F0R(_,x)
#define EACH(a,x)   for(auto& a: x)

template<class T> bool ckmin(T& a, const T& b) {
	return (b < a ? a = b, 1 : 0); }
template<class T> bool ckmax(T& a, const T& b) {
	return (b > a ? a = b, 1 : 0); }

inline namespace IO {
	template<class T> void read(V<T>& x);
	template<class T, class U> void read(PR<T, U>& x);
	template<class T> void read(T& x) { cin >> x; }
	template<class T, class... U> void read(T& x, U&... y) { read(x); read(y...); }
	template<class T> void read(V<T>& x) { EACH(a, x) read(a); }
	template<class T, class U> void read(PR<T, U>& x) { read(x.F, x.S); }
	template<class T> void write(const V<T>& x);
	template<class T, class U> void write(const PR<T, U>& x);
	template<class T> void write(const T& x) { cout << x; }
	template<class T, class... U> void write(const T& x, const U&... y) { write(x); write(y...); }
	template<class T> void write(const V<T>& x) { bool f=1; EACH(a, x) { if(!f) write(" "); write(a); f=0; } };
	template<class T, class U> void write(const PR<T, U>& x) { write(x.F, " ", x.S); }
	template<class T> void print(const T& x) { write(x, "\n"); }
	template<class T, class... U> void print(const T& x, const U&... y) { write(x, " "); print(y...); }
	template<class T> void pdebug(const T& x) { write(x, "]\n"); cout.flush(); }
	template<class T, class... U> void pdebug(const T& x, const U&... y) { write(x, ", "); pdebug(y...); }
	#define debug(...) cout << "LINE(" << __LINE__ << ") => [" << #__VA_ARGS__ << "]: [", pdebug(__VA_ARGS__)
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, q, k; read(n, q, k);
	int a[n+2]{}; FOR(i,1,n) read(a[i]);
	ll ps[n+1]{}; ps[0] = 0;
	FOR(i,1,n) {
		ll low = max(1, a[i-1] + 1);
		ll hi = min(k, a[i+1] - 1);
		if(low <= a[i] && a[i] <= hi) hi--;
		ps[i] = ps[i-1] + max(0LL, hi - low + 1);
	}
	REP(q) {
		int l, r; read(l, r);
		if(l == r) {
			ll ans = k;
			if(1 <= a[l] && a[r] <= k) ans--;
			print(ans);
		} else {
			ll ans = ps[r-1]-ps[l];
			// debug("ans", ans);
			ll lo = 1, hi = a[l+1]-1;
			ans += max(0LL, hi - lo);
			lo = a[r-1] + 1, hi = k;
			ans += max(0LL, hi - lo);
			print(ans);
		}
	}

}