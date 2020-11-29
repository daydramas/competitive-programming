#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

using ll = long long;
using ld = long double;
using str = string;

using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<str>;
using vii = vector<pii>;
template <class T> using v = vector<T>;

#define mp make_pair
#define f first
#define s second

#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define lb lower_bound
#define ub upper_bound

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

const int MOD = 1e9+7;
const ll INF = 1e18;
const int MX = 2e5+5;
const ld PI = acos(-1);
const int X[] = {1, 0, -1, 0},
          Y[] = {0, 1, 0, -1};

/* ============================ */

void setIO(str PROB = "") {
    cin.tie(0)->sync_with_stdio(0);
    if(sz(PROB)) {
        freopen((PROB+".in").c_str(), "r", stdin);
        freopen((PROB+".out").c_str(), "w", stdout);
    }
}

/* ============================ */

struct segTree {

    int n; vl va, lz, am;

	segTree(int n_) { n = n_, va.assign(4*n, 0); lz.assign(4*n, 0); am.assign(4*n, 0); }

	int left(int i) { return i*2; }
	int right(int i) { return i*2+1; }

    ll val(int id, int l, int r){
		int d = r - l + 1;
		return va[id] + lz[id] * d + am[id] * d * (d - 1) / 2;
	}

	void push(int id, int l, int r){
        lz[left(id)] += lz[id];
        am[left(id)] += am[id];
        lz[right(id)] += lz[id] + am[id] * ((r - l) / 2 + 1);
        am[right(id)] += am[id];
        lz[id]=am[id]=0;
	}

	void upd(int id, int a, int b, int l, int r, int v){
		if(b < l || r < a) return;
		if(a <= l && r <= b){
			lz[id] += v * (l - a + 1);
			am[id] += v;
			return;
		}

		push(id, l, r);
        upd(left(id), a, b, l, (l+r)/2, v);
        upd(right(id), a, b, (l+r)/2+1, r, v);
        va[id] = val(left(id), l, (l+r)/2) + val(right(id), (l+r)/2+1, r);
	}

	long qry(int id, int l, int r, int a, int b){
		if(r < a || b < l) return 0;
		if(a <= l && r <= b) return val(id, l, r);

		push(id, l, r);
		va[id] = val(left(id), l, (l+r)/2) + val(right(id), (l+r)/2+1, r);

		return qry(left(id), l, (l+r)/2, a, b) + qry(right(id), (l+r)/2+1, r, a, b);
	}
};


int n, q, t[MX];

int main() {
    // setIO("input");

    cin >> n >> q;
    FOR(i,1,n) cin >> t[i];

    segTree st(n+1);
    FOR(i,1,n) st.upd(1, i, i, 1, n, t[i]);
    F0R(i, q) {
        int _,a,b; cin >> _ >> a >> b;
        if (_==1) {
            st.upd(1, a, b, 1, n, 1);
        } else {
            cout << st.qry(1, 1, n, a, b) <<"\n";
        }
    }

}