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

template<int SZ> struct BinCoef {
    ll fact[SZ+5];
    ll MOD = 1e9+7;

    ll pw(ll a, ll b) {
        if (b == 0) return 1LL;
        return pw((a*a)%MOD, b/2) * (b&1?a:1LL) % MOD;
    }

    ll ifact(int i) { return pw(fact[i], MOD-2); }

    BinCoef(ll _MOD = 1e9+7) {
        MOD = _MOD;
        fact[0]=1;
        FOR(i,1,SZ) fact[i] = (fact[i-1]*i) % MOD;
    }

    ll get(int a, int b) {
        if (a < b) return 0;
        return (fact[a]*ifact(a-b) % MOD * ifact(b) % MOD);
    }

};

const int mod = 1e9+7;
const int maxn = 1e6+5;
int n, m;
vector<pair<int,int>> T;
BinCoef<maxn*2> B;
int dp[maxn];

int main() {

    cin >> n >> m;
    F0R(i,m) {
        int x,y; cin >> x >> y;
        T.pb({x,y});
    }
    sort(all(T));
    F0R(i,m) {
        dp[i] = B.get(T[i].f+T[i].s-2, T[i].f-1);
        F0R(j,i) dp[i] = (dp[i] - dp[j]*B.get(T[i].f+T[i].s-T[j].f-T[j].s, T[i].f-T[j].f) + mod) % mod;
        while(dp[i]<0) dp[i]+=mod;
        // cout << "dp["<<i<<"] = "<<dp[i]<<"\n";
    }
    int ans = B.get(n+n-2, n-1);
    F0R(i,m) ans = (ans - dp[i]*B.get(n+n-T[i].f-T[i].s, n-T[i].f) + mod) % mod;
    while(ans<0) ans += mod;
    cout << ans;
}