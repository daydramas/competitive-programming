#include <bits/stdc++.h>
using namespace std;

typedef int i;
typedef long long ll;
typedef string str;

typedef pair<i,i> pii;
typedef pair<ll,ll> pll;

typedef vector<i> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<str> vs;

#define mp make_pair
#define f first
#define s second
#define sz(x) (i)x.size()
#define all(x) begin(x), end(x)
#define pb push_back

#define for0(a,n) for(i a = 0; a < (n); ++a)
#define for1(a,n) for(i a = 1; a <= (n); ++a)
#define rof0(a,n) for(i a = (n-1); a >= 0; --a)
#define rof1(a,n) for(i a = (n); a >= 1; --a)
#define trav(a,x) for (auto& a: x)

const i MOD = 1e9+7; // 998244353;
const i MX = 2e5+5;
const ll INF = 1e18;
const double PI = acos(-1);
const i X[4] = {1,0,-1,0}, Y[4] = {0,1,0,-1};

/* Source: Benq (https://github.com/bqi343/USACO) [Modified] */

template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

namespace IO {
    void setIO(string PROB = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (sz(PROB)) {
            freopen((PROB+".in").c_str(),"r",stdin);
            freopen((PROB+".out").c_str(),"w",stdout);
        }
    }

    /* Input */
    template<class A, class B> void re(pair<A,B>& p);
    template<class A> void re(vector<A>& v);
    template<class T> void re(T& x) { cin >> x; }
    template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }
    template<class A, class B> void re(pair<A,B>& p) { re(p.f,p.s); }
    template<class A> void re(vector<A>& x) { trav(a,x) re(a); }

    /* Output */
    template<class A> void pr(A x) { cout << ts(x); }
    template<class H, class... T> void pr(const H& h, const T&... t) {
        pr(h); pr(t...); }
    void pl() { cout << "\n"; }
}
using namespace IO;

/* ============================ */

int main() {
    setIO("");

    i n; re(n);
    vl x(n); re(x);
    vvl dp(n, vl(n));
    ll sum=0; trav(a,x)sum+=a;
    rof0(a,n) for(i b=a; b<n; b++){
        if(a==b) dp[a][b]=x[a];
        else dp[a][b] = max(x[a]-dp[a+1][b], x[b]-dp[a][b-1]);
    }
    cout << (sum+dp[0][n-1])/2 << "\n";

}