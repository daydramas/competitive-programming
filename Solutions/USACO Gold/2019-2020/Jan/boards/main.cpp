#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
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

/* source: benq */
template<class T> struct Seg { // comb(ID,b) = b
	const T ID = 1e18; T comb(T a, T b) { return min(a,b); }
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n,ID); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		p += n;
		seg[p] = min(val,seg[p]);
		// seg[p]=val;
		for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// sum on interval [l, r]
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
};

const int maxp = 1e5+5;
using pi = pair<int,int>;
using pn = pair<pi,pi>; // { {x,y} {type, index}}

int n, p;
vector<pn> P;
Seg<ll> st;
map<int,int> M;
ll ans[maxp];

int main() {

	ifstream fin("boards.in");
	// ofstream fout("boards.out");
	ofstream fout("boards.out");

	fin >> n >> p;
	F0R(i,p) {
		int x,y,x2,y2;
		fin >> x >> y >> x2 >> y2;
		P.pb({{x,y},{1,i}});
		P.pb({{x2,y2},{-1,i}});
		M[y]=M[y2]=1;
	}
	M[n]=1;
	int c=0; trav(x, M) M[x.f]=++c;
	// cout <<"here-1"<<endl;
	st.init(c+1); sort(all(P));
	// cout <<"here"<<endl;
	trav(x, P) {
		if(x.s.f==1) {
			ll t = min(0LL,st.query(0,M[x.f.s]));
			t += x.f.f + x.f.s;
			ans[x.s.s]=t;
		} else {
			st.upd(M[x.f.s], ans[x.s.s] - x.f.f - x.f.s);
		}
		// cout <<"m="<<M[x.s.s]<<endl;
		// ll t=st.query(0,M[x.s.s]);
		// cout <<"m="<<M[x.s.s]<<endl;
		// t = min(t, 0LL);
		// t = t - x.f.f - x.f.s + x.s.f + x.s.s;

		// cout <<"t="<<t<<"\n";
		// st.upd(M[x.f.s],t);
	}
	ll t2=min(0LL,st.query(0,M[n]));
	ll ans = n+n+t2;
	cout <<"qr="<<t2<<"\n";
	cout << ans <<"\n";
	fout << ans <<"\n";
}
