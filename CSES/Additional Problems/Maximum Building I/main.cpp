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

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

template<int SZ> struct DSU {
    int sz[SZ], pa[SZ];

    DSU() {
        for(int i=0; i<SZ; i++)
            sz[i]=1, pa[i]=-1;
    }

    void clear() {
        for(int i=0; i<SZ; i++)
            sz[i]=1, pa[i]=-1;
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

const int maxn = 1000;

int n, m;
char f[maxn][maxn];
int ls[maxn]; // last seen
vector<pair<int,int> > v;
DSU<1000> D;

int main() {

    cin >> n >> m;
    F0R(i,n) F0R(j,m) cin >> f[i][j];
    F0R(i,n) ls[i]=m; // pretend that there's a wall at j=M
    int ans=0;
    R0F(j,m) {
        F0R(i,n) if(f[i][j]=='*') ls[i]=j;
        D.clear(); v.clear();
        F0R(i,n) v.pb({ls[i]-j, i});
        sort(v.rbegin(), v.rend());
        trav(x, v) {
            D.pa[x.s] = x.s; // mark it as used
            if((x.s-1)>=0 && D.pa[x.s-1]!=-1) D.comb(x.s, x.s-1); // only combine with previously used ones
            if((x.s+1)<n && D.pa[x.s+1]!=-1) D.comb(x.s, x.s+1); // only combine with previously used ones
            ans = max(ans, x.f*D.sz[D.get(x.s)]); // update answer
        }
    }
    cout << ans;

}