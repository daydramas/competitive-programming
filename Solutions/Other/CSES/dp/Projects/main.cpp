#include <bits/stdc++.h>
using namespace std;

typedef int i;
typedef long long ll;
typedef string str;

typedef pair<i,i> pii;
typedef pair<ll,ll> pll;

typedef vector<i> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<str> vs;

#define mp make_pair
#define f first
#define s second
#define sz(x) (i)x.size()
#define all(x) begin(x), end(x)
#define pb push_back

#define for0(a,n) for(i a = 0; a < (n); ++a)
#define for1(a,n) for(i a = 1; a <= (n); ++a)
#define rof0(a,n) for(i a = (n-1); a >= 0; --a)
#define rof1(a,n) for(i a = (n); a >= 1; --a)
#define trav(a,x) for (auto& a: x)

const i MOD = 1e9+7; // 998244353;
const i MX = 2e5+5;
const ll INF = 1e18;
const double PI = acos(-1);
const i X[4] = {1,0,-1,0}, Y[4] = {0,1,0,-1};

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

struct segTree {

	int n;
	vector<ll> st;

	segTree(int n_) {
		n = n_;
		st.assign(4*n, 0);
	}

	int left(int i) { return i*2; }
	int right(int i) { return i*2+1; }

	void update(int id, int L, int R, int P, ll value) {
		if (P > R || P < L) return;
		if (P >= L && P <= R) ckmax(st[id], value);
		if (L == R) return;
		update(left(id), L, (R+L)/2, P, value);
		update(right(id), (R+L)/2+1, R, P, value);
	}

	void update(int P, ll value) {
		update(1, 1, n, P, value);
	}

	ll get(int id, int L, int R, int l, int r) {
		if (l > R || r < L) return 0;
		if (l <= L && R <= r) return st[id];
		return max(get(left(id), L, (R+L)/2, l, r),get(right(id), (R+L)/2+1, R, l, r));
	}

	ll get(int L, int R) {
		return get(1, 1, n, L, R);
	}
};


vi b(200005);
bool comp(i x, i y) {
    return b[x]<b[y];
}
int main() {
    setIO("");
    // freopen("input.txt", "r", stdin);

    i n; re(n);
    vi a(n),p(n),s1(n);
    // set<i> S;
    map<int, int> M;
    for0(i,n) {
        re(a[i],b[i],p[i]);
        s1[i]=i;
        M[a[i]]=1, M[b[i]]=1;
    }
    i cnt=1;
    trav(m,M) {
        m.second=cnt++;
    }
    sort(all(s1), comp);
    segTree t(2*n+1);
    ll ans=0;
    for0(_,n) {
        i in=s1[_];
        i a_ = M[a[in]];
        i b_ = M[b[in]];
        ll res=t.get(1, a_-1)+p[in];
        t.update(b_,res);
        ckmax(ans, res);
    }
    cout << ans;

}