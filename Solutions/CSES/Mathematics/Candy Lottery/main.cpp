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

using ld = long double;

ld pw(ld a, int b) {
    if (b == 0) return 1.0;
    return pw(a*a, b/2) * (b&1?a:1.0);
}

int main() {

    ld n, k; cin >> n >> k;
    ld ans = 0.0, ps = 0.0;
    FOR(i,1,k) {
        ld a = pw(i/k, n);
        // cout << (a)<<"-"<<(ps) <<"\n";
        ans += i*(a-ps);
        ps = a;
    }
    cout << fixed << setprecision(6) << ans ;

}