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

struct BIT {

	int n;
	vector<vector<int> > t;

	BIT(int n_) {
		n = n_;
		t.assign(n+1, vi(n+1, 0));
	}

	void update(int i, int j, int value) {
        int oj=j;
		for (; i<=n; i+=i&(-i))
        for (j=oj; j<=n; j+=j&(-j)) t[i][j] += value;
	}

	int get(int i, int j) {
		int sum = 0, oj=j;
		for (; i>0; i-=i&(-i))
        for (j=oj; j>0; j-=j&(-j)) sum += t[i][j];
		return sum;
	}

};


int main() {
    setIO("");

    int n, q; re(n,q);
    vs a(n); re(a);

    BIT t(n);
    for0(i,n) for0(j,n) {
        if (a[i][j]=='*') t.update(i+1, j+1, 1);
    }
    for0(i,q) {
        int _; re(_);
        if (_==1) {
            int x,y; re(x,y);
            a[x-1][y-1]=a[x-1][y-1]=='*'?'.':'*';
            if (a[x-1][y-1]=='.') t.update(x, y, -1);
            else t.update(x, y, 1);
        } else {
            int y1,x1,y2,x2; re(x1,y1,x2,y2);
            cout << t.get(x2,y2)-t.get(x1-1,y2)-t.get(x2,y1-1)+t.get(x1-1,y1-1)<<"\n";
        }
    }

}