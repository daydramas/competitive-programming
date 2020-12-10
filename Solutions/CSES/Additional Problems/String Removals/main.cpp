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

    const int mod = 1e9+7;

    string s; cin >> s;
    vi cnt(26); ll ans=0;
    trav(x, s) {
        ll t = cnt[x-'a'];
        cnt[x-'a'] = (ans+1) % mod;
        ans=(2*ans+mod+1-t) % mod;
    }
    cout << ans;

}