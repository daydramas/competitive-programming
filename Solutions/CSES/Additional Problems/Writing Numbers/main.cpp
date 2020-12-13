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

ll get(ll n) {
    ll res = 0;
    ll cur = 0, aft = 0, bf = 0;
    for(ll i=1; (n/i); i*=10) {
        cur = (n / i) % 10;
        bf = n / (i * 10);
        aft = n - (n / i) * i;
        if (cur > 1) res = res + (bf + 1) * i;
        else if (cur == 0) res = res + bf * i;
        else if(cur == 1) res = res + bf * i + aft + 1;
    }
    return res;
}

int main() {

    ll n; cin >> n;
    ll l=1, r=(1e18),ans;
    while(l<r) {
        ll m = (r+l)/2;
        if (get(m) <= n) l=m+1,ans=m;
        else r=m-1;
    }
    if (get(l) > n) l--;
    cout << l;

}