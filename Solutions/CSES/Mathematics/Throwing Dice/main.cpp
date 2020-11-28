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

// ll ans[MX] = {1,1,2,4,8,16,32};
map<ll, int> M;
ll pw(ll a, ll b, ll m=1e9+7) { // calculating a^b (mod m)
    if (b == 0) return 1LL;
    return pw((a*a)%m, b/2, m) * (b&1?a:1LL) % m;
}

ll F(ll x) {
    if (x==0) return 1;
    if (x==1) return 1;
    if (x==2) return 2;
    if (x==3) return 4;
    if (x==4) return 8;
    if (x==5) return 16;
    if (x==6) return 32;
    if (x==7) return 63;
    if (x==8) return 125;
    if (x==9) return 248;
    if (x==10) return 492;
    if (x==11) return 976;
    if (x==12) return 1936;
    if (x==13) return 3840;
    if (M[x]) return M[x];
    ll m=x/2;
    ll fst=F(m), snd=x-m;
    ll res=0;
    ROF(i,1,6) {
        res =  (res + fst * F(snd)) % MOD;
        fst-=F(m-i); if (fst<0) fst += (-fst/MOD+1)*MOD;
        snd--;
    }
    return(M[x]=res);
}

int main() {
    setIO("");

    ll x; cin >> x;
    ll ans=F(x);
    // if (ans<0) ans += (-ans/MOD+1)*MOD;
    cout << ans;
    // cout << F(x);
}