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

template<int SZ> struct TreeDiameter {
	int N, par[SZ], dist[SZ], diaLen;
	vi adj[SZ], dia, center;
	void ae(int a, int b) { adj[a].pb(b), adj[b].pb(a); }
	void dfs(int x) {
		trav(y,adj[x]) if (y != par[x]) {
			par[y] = x; dist[y] = dist[x]+1;
			dfs(y); }
	}
	void genDist(int x) { par[x] = -1; dist[x] = 0; dfs(x); }
	void init(int _N) {
		N = _N; dia = {0,0};
		genDist(0); F0R(i,N) if (dist[i]>dist[dia[0]]) dia[0] = i;
		genDist(dia[0]); F0R(i,N) if (dist[i]>dist[dia[1]]) dia[1] = i;
		diaLen = dist[dia[1]];
	}
};

TreeDiameter<MX> td;

int main() {
    setIO("");

    int n; cin >> n;
    F0R(i,n-1) {
        int a,b; cin >> a >> b;
        a--,b--;
        td.ae(a,b);
    }
    td.init(n);
    cout << td.diaLen;

}