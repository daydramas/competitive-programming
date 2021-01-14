#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

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

    /* To String */
    str ts(int i) { return to_string(i); }
    str ts(ll i) { return to_string(i); }
    str ts(bool b) { return b ? "true" : "false"; }
    str ts(char c) { str s=""; s+=c; return s; }
    str ts(str s) { return s; }
    str ts(const char* s) { return (str)s; }
    template<class T> str ts(vector<T> v) {
        bool fst=1; str res="{";
        trav(a, v) {
            if (!fst) res += ", ";
            fst = 0; res += ts(a);
        }
        res+="}"; return res;
    }

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
	vector<ll> st;
    vector<pll> lz;

	lazySegTree(int n_) {
		n = n_;
		st.assign(4*n, 0);
		lz.assign(4*n, {1,0});
	}

	int left(int i) { return i*2; }
	int right(int i) { return i*2+1; }


	void propagate(int id, int L, int R) {
		st[id] = lz[id].f*st[id]+(R-L+1)*lz[id].s;
		if (L!=R) {
            if (!lz[id].f) lz[left(id)] = {0,0};
            lz[left(id)].s += lz[id].s;
            if (!lz[id].f) lz[right(id)] = {0,0};
            lz[right(id)].s += lz[id].s;
		}
		lz[id] = {1,0};
	}

	void update(int id, int L, int R, int l, int r, pll value) {
		propagate(id, L, R);
		if (l > R || r < L) return;
		if (l <= L && R <= r) {
			lz[id] = value;
			propagate(id, L, R);
			return;
		}
		if (L == R) return;
		update(left(id), L, (R+L)/2, l, r, value);
		update(right(id), (R+L)/2+1, R, l, r, value);
		st[id] = st[left(id)] + st[right(id)];
	}

	void update(int L, int R, pll value) {
		update(1, 1, n, L, R, value);
	}

	ll get(int id, int L, int R, int l, int r) {
		propagate(id, L, R);
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

    int n, q; re(n, q);
    lazySegTree t(n+1);


    for1(i,n) {
        int a; re(a);
        t.update(i, i, {0, a});
    }
    for0(i,q) {
        int a; re(a);
        if (a==1) {
            int x,y,z; re(x,y,z);
            t.update(x,y,{1,z});
        } else if (a==2) {
            int x,y,z; re(x,y,z);
            t.update(x,y,{0,z});
        } else {
            int x,y; re(x,y);
            pr(t.get(x,y)); pl();
        }
    }


}