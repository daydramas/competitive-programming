#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
#define f first
#define s second
#define pb push_back
#define all(x) begin(x), end(x)

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

void solve(vl &y, vl &x) {
    int n=x.size(); y = {0};
    F0R(i,n) F0R(j, 1<<i) y.pb(y[j]+x[i]);
    sort(all(y));
}

int main() {

    int n, x, m; ll ans; vl a, b, c, d;
    cin >> n >> x;
    m = n/2;
    F0R(i,m) { ll t; cin >> t; a.pb(t); }
    F0R(i,n-m) { ll t; cin >> t; b.pb(t); }
    solve(c, a); solve(d, b); ans=0;
    trav(t, c) {
        auto l = lower_bound(all(d), x-t);
        auto r = upper_bound(all(d), x-t);
        ans += (r-l);
    }
    cout << ans;
}