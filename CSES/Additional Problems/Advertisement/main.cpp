#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
#define f first
#define s second
#define pb push_back
#define all(x) begin(x), end(x)

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

template<int SZ> struct DSU {
    ll sz[SZ]; int pa[SZ];

    DSU() {
        for(int i=0; i<SZ; i++)
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

using vpi = vector<pair<int, int> >;
const int maxn = 2e5+5;

int main() {

    int n; ll v[maxn]; vpi a; DSU<maxn> dsu;
    cin >> n;
    FOR(i,1,n) {
        cin >> v[i];
        a.pb({v[i],i});
    }
    sort(all(a)); ll ans=0;
    R0F(i,n) {
        auto x = a[i];
        if (x.s+1 <= n && v[x.s+1]>=v[x.s]) dsu.comb(x.s, x.s+1);
        if (x.s-1 >= 1 && v[x.s-1]>=v[x.s]) dsu.comb(x.s, x.s-1);
        ans = max(ans, x.f*dsu.sz[dsu.get(x.s)]);
    }
    cout << ans;

}