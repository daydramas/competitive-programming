#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
const int maxn = 1e5+5;
using ll = long long;
const ll mod = 1e9+7;
// struct iso {
    int n; vi g[maxn];
    ll dfs(int a=1, int c=-1) {
        ll r=1;
        for(int b : g[a]) if(b!=c) r=(r*dfs(b,a)) % mod;
        return (r+42069LL) % mod;
    }
    ll iso() {
        for(int i=1; i<=n; i++) g[i].clear();
        for(int i=1; i<n; i++) {
            int a,b; cin >> a >> b;
            g[a].pb(b); g[b].pb(a);
        }
        return dfs();
    }
    // ~iso() {
    //     for(int i=0; i<n; i++) g[i].clear();
    // }

// };
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while(t--) {
        cin >> n;
        if(iso() == iso()) { cout <<"YES\n"; }
        else cout <<"NO\n";
    }
}