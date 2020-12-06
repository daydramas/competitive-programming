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

int main() {

    int n; cin >> n;
    vector<ld> r(n); trav(a,r) cin >> a;

    ld ans=0.0;
    for(int i=0; i<n; i++)
    for(int j=i+1; j<n; j++)
    for(ld k=1; k<=r[i]; k++) {
        ld l=min(k-1, r[j]);
        ans += (1.0/r[i]) * (l/r[j]);
    }
    cout << fixed << setprecision(6) << ans;
}