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
		if (P >= L && P <= R) st[id] += value;
		if (L == R) return;
		update(left(id), L, (R+L)/2, P, value);
		update(right(id), (R+L)/2+1, R, P, value);
	}

	void update(int P, int value) {
		update(1, 1, n, P, value);
	}

	ll get(int id, int L, int R, int l, int r) {
		if (l > R || r < L) return 0;
		if (l <= L && R <= r) return st[id];
		return get(left(id), L, (R+L)/2, l, r) + get(right(id), (R+L)/2+1, R, l, r);
	}

	ll get(int L, int R) {
		return get(1, 1, n, L, R);
	}
};

int n, q;
int v[MX], lca[20][MX];
vi adj[MX];
int itc=1; pii itv[MX];

void dfs(int src, int par=-1) {
    itv[src].f = itc++;
    trav(dest, adj[src]) if (dest!=par) {
        lca[0][dest]=src;
        dfs(dest, src);
    }
    itv[src].s = itc-1;
}

int main() {
    setIO("");

    cin >> n >> q;
    FOR(i,1,n) cin >> v[i];
    F0R(i,n-1) {
        int a,b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1);
    segTree st(n+1);
    FOR(i,1,n) st.update(itv[i].f, v[i]);
    F0R(i,q) {
        int _; cin >>_;
        if (_==1) {
            int a, b; cin >> a >> b;
            st.update(itv[a].f, -v[a]);
            v[a]=b; st.update(itv[a].f, v[a]);
        } else if (_==2) {
            int a; cin >> a;
            cout << st.get(itv[a].f, itv[a].s) <<"\n";
        }
    }
}