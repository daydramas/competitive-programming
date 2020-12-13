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

template<int SZ> struct DSU {
    int sz[SZ], pa[SZ];

    DSU() {
        for(int i=0; i<SZ; i++)
            sz[i]=1, pa[i]=i;
    }
    DSU(int n) {
        for(int i=1; i<=n; i++)
            sz[i]=1, pa[i]=i;
    }

    int get(int a) { // find parent
        if(pa[a] == a) return a;
        return pa[a]=get(pa[a]);
    }

    bool comb(int a, int b) { // merge
        a=get(a), b=get(b);
        if (a==b) return false;
        if (sz[a] < sz[b]) swap(a,b);
        sz[a]+=sz[b]; pa[b]=a;
        return true;
    }

};

const int maxn = 1e5+5;
int n, m, dp[maxn], s[maxn];
DSU<maxn> D;

int main() {

    cin >> n >> m;
    D = DSU<maxn> (n);
    while(m--) {
        int a,b; cin >> a >> b;
        D.comb(a, b);
    }
    bitset<maxn> ans; ans[0]=1;
    FOR(i,1,n) if(D.pa[i]==i) {
        bitset<maxn> temp = ans<<D.sz[i];
        ans = ans | temp;
    }
    FOR(i,1,n) cout << ans[i];
    // map<int,int> M;
    /*vi o;*FOR(i,1,n) if(D.pa[i]==i) M[D.sz[i]]++;o.pb(D.sz[i]);*/
    /*trav(x, M) o.pb(x.f);*/ /*sort(all(o));*/
    // FOR(i,1,n) dp[i]=s[i]=0; dp[0]=1;
    // trav(a, M) {
    //     int x=a.f, m=a.s+1;
    //     F0R(i,n+1) {
    //         s[i]=dp[i];
    //         if (i>=x) s[i]+=s[i-x];
    //         dp[i]=(s[i] > (i>=m*x? s[i-m*x]:0));
    //     }
    // }
    // trav(x, o) R0F(i,n) if(dp[i])
    //     if(x+i<=n) dp[x+i]=1;
    // FOR(i,1,n) cout<<dp[i];
}