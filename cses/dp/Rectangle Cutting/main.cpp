/* Template Source: Benq (https://github.com/bqi343/USACO) [Modified] */

#include <bits/stdc++.h>
using namespace std;

typedef int i;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<i,i> pi;
typedef pair<ll,ll> pl;
typedef pair<db,db> pd;

typedef vector<i> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;

#define mp make_pair
#define f first
#define s second
#define sz(x) (i)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound

#define for0(a,n) for(i a = 0; a < (n); ++a)
#define for1(a,n) for(i a = 1; a <= (n); ++a)
#define rof0(i,n) for(i a = (n-1); a >= 0; --a)
#define rof1(i,n) for(i a = (n); a >= 1; --a)
#define trav(a,x) for (auto& a: x)

const i MOD = 1e9+7; // 998244353;
const i MX = 2e5+5;
const ll INF = 1e18;
const ld PI = acos((ld)-1);
const i X[4] = {1,0,-1,0}, Y[4] = {0,1,0,-1};

template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

// INPUT
template<class A, class B> void re(pair<A,B>& p);
template<class A> void re(vector<A>& v);

template<class T> void re(T& x) { cin >> x; }
template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }
template<class A, class B> void re(pair<A,B>& p) { re(p.f,p.s); }
template<class A> void re(vector<A>& x) { trav(a,x) re(a); }

// TO_STRING
#define ts to_string
template<class A, class B> str ts(pair<A,B> p);
template<class A> str ts(complex<A> c) { return ts(mp(c.real(),c.imag())); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(char c) { str s = ""; s += c; return s; }
str ts(str s) { return s; }
str ts(const char* s) { return (str)s; }
template<size_t SZ> str ts(bitset<SZ> b) {
    str res = ""; for0(i,SZ) res += char('0'+b[i]);
    return res; }
template<class T> str ts(T v) {
    bool fst = 1; str res = "{";
    for (const auto& x: v) {
        if (!fst) res += ", ";
        fst = 0; res += ts(x);
    }
    res += "}"; return res;
}
template<class A, class B> str ts(pair<A,B> p) {
    return "("+ts(p.f)+", "+ts(p.s)+")"; }

// OUTPUT
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) {
    pr(h); pr(t...); }
void ps() { pr("\n"); } // print w/ spaces
template<class H, class... T> void ps(const H& h, const T&... t) {
    pr(h); if (sizeof...(t)) pr(" "); ps(t...); }

// IO
void setIO(string PROB = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(PROB)) {
        freopen((PROB+".in").c_str(),"r",stdin);
        freopen((PROB+".out").c_str(),"w",stdout);
    }
}

int main() {
    setIO("");

    i a,b; re(a,b);
    vvi dp(a+1, vi(b+1, 1e9));
    for0(x,a+1) for0(y,b+1) {
        if(x==y) ckmin(dp[x][y], 0);
        for1(_x,x-1) ckmin(dp[x][y], dp[_x][y]+dp[x-_x][y]+1);
        for1(_y,y-1) ckmin(dp[x][y], dp[x][_y]+dp[x][y-_y]+1);
    }
    cout << dp[a][b];
}