#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

using ll = long long;
using ld = long double;
using str = string;

using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<str>;
using vii = vector<pii>;
template <class T> using v = vector<T>;

using Matrix = v<vl>;

#define mp make_pair
#define f first
#define s second

#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define lb lower_bound
#define ub upper_bound

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

const int MOD = 1e9+7;
const ll INF = 1e18;
const int MX = 2e5+5;
const ld PI = acos(-1);
const int X[] = {1, 0, -1, 0},
          Y[] = {0, 1, 0, -1};

/* ============================ */

void setIO(str PROB = "") {
    cin.tie(0)->sync_with_stdio(0);
    if(sz(PROB)) {
        freopen((PROB+".in").c_str(), "r", stdin);
        freopen((PROB+".out").c_str(), "w", stdout);
    }
}

/* ============================ */
void multiply(Matrix &a, Matrix &b) {
    ll mul[6][6];
    F0R(i,6) F0R(j,6) {
        mul[i][j] = 0;
        F0R(k,6) mul[i][j] = (mul[i][j]+a[i][k]*b[k][j]) % MOD;
    }
    F0R(i,6) F0R(j,6) a[i][j] = mul[i][j];
}
void power(Matrix &H, ll n) {
    if (n==1) return;
    Matrix M = {{ 1, 1, 1, 1, 1, 1},
                { 1, 0, 0, 0, 0, 0},
                { 0, 1, 0, 0, 0, 0},
                { 0, 0, 1, 0, 0, 0},
                { 0, 0, 0, 1, 0, 0},
                { 0, 0, 0, 0, 1, 0} };
    power(H, n/2);
    multiply(H, H);
    if (n&1) multiply(H, M);
}

int main() {
    setIO("");

    ll n; cin >> n;

    ll ans;
    if (n==0) ans=1;
    else if (1 <= n && n <= 6) ans=1<<(n-1);
    else {
         Matrix H = {{ 1, 1, 1, 1, 1, 1},
                    { 1, 0, 0, 0, 0, 0},
                    { 0, 1, 0, 0, 0, 0},
                    { 0, 0, 1, 0, 0, 0},
                    { 0, 0, 0, 1, 0, 0},
                    { 0, 0, 0, 0, 1, 0} };
        power(H, n-6);
        vl tm = {32, 16, 8, 4, 2, 1};
        ans=0;
        F0R(i,6) {
            ans = (ans+H[0][i]*tm[i]) % MOD;
        }
    }

    cout << ans;
}