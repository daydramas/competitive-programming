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
// ofstream fout("ouput.out");
template<int SZ> struct TopoSort {
    int N; vi adj[SZ], res; int in[SZ];
    void ae(int a, int b) {
        adj[a].pb(b); in[b] ++;
    }
    bool sort(int _N) {
        N=_N; queue<int> Q;


        FOR(i,1,N) if(in[i] == 0) Q.push(i);
        while(!Q.empty()) {
            int a=Q.front(); Q.pop(); res.pb(a);
            // if (sz(res) > 99900) fout << sz(res)<<" "<<Q.size()<<" -> "<<a <<" :( "<<"\n";
            trav(b, adj[a]) if (!(--in[b])) Q.push(b);
        }
        // fout <<"i'm done\n"<<" "<<(sz(res)==N);
        return (sz(res)==N);
    }
};

const int MX2 = 1e5+5;

TopoSort<MX2> tps;
int dp[MX2];

int main() {
    // setIO("input");
    // freopen("input.in", "r", stdin);
    int n, m; cin >> n >> m;
    FOR(i,1,n) tps.in[i]=0;
    F0R(i,m) {
        int a,b; cin >> a >> b;
        tps.ae(a,b);
    }
    bool temp = tps.sort(n);
    // cout <<temp<<" beginning dp\n";
    if (temp) {
        reverse(all(tps.res));
        FOR(i,1,n) dp[i]=-MOD;
        dp[n]=1; trav(a, tps.res) if (a!=n) {
            trav(b, tps.adj[a]) {
                dp[a]=max(dp[a], dp[b]+1);
            }
        }
        if (dp[1] < 0) cout <<"IMPOSSIBLE";
        else {
            cout << dp[1] <<"\n";
            vi cur = {1};
            while (cur.back() != n) {
                // fout << cur.back() <<" ";
                trav(x,tps.adj[cur.back()]) if (dp[cur.back()] == dp[x]+1) {
                    cur.pb(x);
                    break;
                }
            }
            trav(t,cur) cout << t <<" ";
        }
    } else {
        cout <<"IMPOSSIBLE";
    }

}