#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<str> vs;

#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define pb push_back

#define for0(a,n) for(int a = 0; a < (n); ++a)
#define for1(a,n) for(int a = 1; a <= (n); ++a)
#define rof0(a,n) for(int a = (n-1); a >= 0; --a)
#define rof1(a,n) for(int a = (n); a >= 1; --a)
#define trav(a,x) for (auto& a: x)

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
const ll INF = 1e18;
const double PI = acos(-1);
const int X[4] = {1,0,-1,0}, Y[4] = {0,1,0,-1};

/* Source: Benq (https://github.com/bqi343/USACO) [Modified] */

template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

namespace IO {
    void setIO(string PROB = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (sz(PROB)) {
            freopen((PROB+".in").c_str(),"r",stdin);
            freopen((PROB+".out").c_str(),"w",stdout);
        }
    }

    /* Input */
    template<class A, class B> void re(pair<A,B>& p);
    template<class A> void re(vector<A>& v);
    template<class T> void re(T& x) { cin >> x; }
    template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }
    template<class A, class B> void re(pair<A,B>& p) { re(p.f,p.s); }
    template<class A> void re(vector<A>& x) { trav(a,x) re(a); }

    /* Output */
    template<class A> void pr(A x) { cout << ts(x); }
    template<class H, class... T> void pr(const H& h, const T&... t) {
        pr(h); pr(t...); }
    void pl() { cout << "\n"; }
}
using namespace IO;

/* ============================ */

struct lazySegTree {

	int n;
	vector<ll> st, lz;

	lazySegTree(int n_, vl &a) {
		n = n_;
		st.assign(4*n, 0);
		lz.assign(4*n, 0);
		build(1, 1, n, a);
	}

	int left(int i) { return i*2; }
	int right(int i) { return i*2+1; }

	void build(int id, int L, int R, vl &a) {
		if (L == R) {
			st[id] = a[L-1];
			return;
		}
		build(left(id), L, (L+R)/2,a);
		build(right(id), (L+R)/2+1, R,a);
		st[id] = st[left(id)] + st[right(id)];
	}

	void propagate(int id, int L, int R) {
		st[id] += lz[id] * (R-L+1);
		if (L!=R) {
			lz[left(id)] += lz[id];
			lz[right(id)] += lz[id];
		}
		lz[id] = 0;
	}

	void update(int id, int L, int R, int l, int r, ll value) {
		if (lz[id]!=0) propagate(id, L, R);
		if (l > R || r < L) return;
		if (l <= L && R <= r) {
			lz[id] += value;
			propagate(id, L, R);
			return;
		}
		if (L == R) return;
		update(left(id), L, (R+L)/2, l, r, value);
		update(right(id), (R+L)/2+1, R, l, r, value);
		st[id] = st[left(id)] + st[right(id)];
	}

	void update(int L, int R, ll value) {
		update(1, 1, n, L, R, value);
	}

	ll get(int id, int L, int R, int l, int r) {
		if (lz[id]!=0) propagate(id, L, R);
		if (l > R || r < L) return 0;
		if (l <= L && R <= r) return st[id];
		return get(left(id), L, (R+L)/2, l, r) + get(right(id), (R+L)/2+1, R, l, r);
	}

	ll get(int L, int R) {
		return get(1, 1, n, L, R);
	}
};


int main() {
    setIO("");

    int n,q; re(n,q);
    vl x(n); re(x);
    lazySegTree t(n,x);
    for0(it,q) {
        int a; re(a);
        if(a==1) {
            int b,c,d; re(b,c,d);
            t.update(b,c,d);
        }
        else {
            int e; re(e);
            cout << t.get(e,e) <<"\n";
        }
    }

}