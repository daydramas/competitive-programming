#include <bits/stdc++.h>
using namespace std;

/* SegTree implementation from BenQ */
template<class T> struct Seg { // comb(ID,b) = b
	const T ID = 1e18; T comb(T a, T b) { return min(a,b); }
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n,ID); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// sum on interval [l, r]
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
};

#define ll long long
Seg<ll> st;

int main() {
	int n, q; cin >> n >> q;
	st.init(n);
	for(int i=1; i<=n; i++) {
		int a; cin >> a;
		st.upd(i, a);
	}
	for(int i=1; i<=q; i++) {
		int t, a, b; cin >> t >> a >> b;
		if (t==1) st.upd(a,b);
		else cout << st.query(a,b) <<"\n";
	}
}