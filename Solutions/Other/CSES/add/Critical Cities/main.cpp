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

const int maxn = 1e5+5;
int n, m, k, d[maxn];
vi adj[maxn];
vi ord, ans;

bool pull(int x) {
    d[x]=1, ord.pb(x);
    if(x==n) return 1;
    trav(y, adj[x]) if(d[y]==-1 && pull(y))
        return 1;
    ord.pop_back(); return 0;
}
void push(int x) {
    d[x]=k;
    // cout<<"d["<<x<<"]="<<k<<"\n";
    trav(y, adj[x]) {
        k=(k>d[y]?k:d[y]);
        if (d[y]==-1) push(y);
    }
}
int main() {

    cin >> n >> m;
    F0R(i,m) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
    }
    FOR(i,1,n) d[i]=-1; pull(1);
    FOR(i,1,n) d[i]=-1;
    F0R(i,sz(ord)) d[ord[i]]=i; // update distances
    k=0; F0R(i,sz(ord)) {
        // cout <<"k="<< k <<" i="<< i<<" ord[i]="<<ord[i]<<"\n";
        if (k<=i) ans.pb(ord[i]);
        push(ord[i]);
    }
    sort(all(ans));
    cout << ans.size() <<"\n";
    trav(x, ans) cout << x <<" ";
}