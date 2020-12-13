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


int main() {

    int n; cin >> n;
    vector<ll> a(n), b(n), v={0};
    trav(x,a) cin >> x;
    trav(x,b) cin >> x;
    FOR(i,1,n-1) v.pb(a[i]-b[i]+v.back());
    sort(all(v));
    ll ans=0; trav(x,v) ans+=abs(x-v[n/2]);
    cout << ans;
}