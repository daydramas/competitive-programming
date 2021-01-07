#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;
#define f first
#define s second
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

namespace IO {
    /* INPUT */
    char nc() { return getchar_unlocked(); }
    void rs(string& x) {
        char ch; x=""; while (isspace(ch = nc()));
        do { x += ch; } while (!isspace(ch = nc()) && ch != EOF); }
    template<class T> void ri(T &x) {
        int sgn=1; char ch; x=0;
        while (!isdigit(ch = nc())) if (ch == '-') sgn *= -1;
        x = ch-'0'; while (isdigit(ch = nc())) x = x*10+(ch-'0');
        x *= sgn; }
    template<class T, class... Ts> void ri(T& t, Ts&... ts) {
        ri(t); ri(ts...); }
    /* OUTPUT */
    void wc(char ch) { putchar_unlocked(ch); }
    void ws(string x) { for(char ch : x) wc(ch); }
    template<class T> inline void wi(T x) {
        if(x < 0) x*=-1, wc('-');
        if(0 <= x && x <= 9) wc('0'+x);
        else wi(x/10), wc('0'+x%10); }
};
using namespace IO;

template<int SZ> struct BinCoef {
    ll fact[SZ+5];
    ll MOD = 1e9+7;

    ll pw(ll a, ll b) {
        if (b == 0) return 1LL;
        return pw((a*a)%MOD, b/2) * (b&1?a:1LL) % MOD;
    }

    ll ifact(int i) { return pw(fact[i], MOD-2); }

    BinCoef(ll _MOD = 1e9+7) {
        MOD = _MOD;
        fact[0]=1;
        FOR(i,1,SZ) fact[i] = (fact[i-1]*i) % MOD;
    }

    ll get(int a, int b) {
        if (a < b) return 0;
        return (fact[a]*ifact(a-b) % MOD * ifact(b) % MOD);
    }

};

int n;
BinCoef<1000005> c;

int main() {

    ri(n);
    if(n&1) {
        ws("0\n");
    } else {
        n /= 2;
        ll r = c.get(2*n, n) * c.pw(n+1,c.MOD-2) % c.MOD;
        wi(r); wc('\n');
    }
}