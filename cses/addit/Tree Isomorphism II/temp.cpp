#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
#define pb push_back
using ll = long long;
const int maxn = 1e5+5;
const int mod = 1e9+7;

int n; vi g[maxn];

vi f() {
	int d = 0; vi deg(n+1), c, ans;
	for(int i=1; i<=n; ++i) {
		deg[i] = g[i].size();
		if (deg[i] == 1) c.pb(i), d++;
	}
	while(d<n) {
		vi nx;
		for(int x: c) for(int y : g[x]) {
            --deg[y]; if (deg[y] == 1) nx.pb(y), ++d;
        }
		c = nx;
	}
	return c;
}
ll dfs(int a=1, int c=-1) {
    ll r=1;
    for(int b : g[a]) if(b!=c) r=(r*dfs(b,a)) % mod;
    return (r+42069LL) % mod;
}
void read() {
    for(int i=1; i<=n; i++) g[i].clear();
    for(int i=1; i<n; i++) {
        int a,b; cin >> a >> b;
        g[a].pb(b); g[b].pb(a);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while(t--) {
        cin >> n;
        read(); vi c=f(); ll a=dfs(c[0]);
        read(); c=f();
        bool y=0; for(auto &x : c) if(dfs(x) == a) {
            cout <<"YES\n";
            y=1; break;
        }
        if(!y) cout <<"NO\n";
    }
}