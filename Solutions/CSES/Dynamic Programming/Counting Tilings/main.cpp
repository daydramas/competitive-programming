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

int n, m;

const long double mod = 1e9+7;
const long double PI = 3.14159265358979323846L;
#define SQ(x) (x)*(x)
using ld = long double;

ld COS(ld x, ld prec=0.000000000000000000000000000000000000000001L) {
    ld t, s ;
    int p;
    p = 0;
    s = 1.0;
    t = 1.0;
    while(fabs(t/s) > prec)
    {
        p++;
        t = (-t * x * x) / ((2 * p - 1) * (2 * p));
        s += t;
    }
    return s;
}


int main() {
    const long double tm = 4.000000000000000001L;
    ri(n, m);
    if(n%2 && m%2) {
        ws("0\n");
    } else {
        cout << fixed << setprecision(10);
        cout <<" PI = "<<PI<<"\n";
        long double res = 1, pre; long double t1, t2;
        for(int j=1; j<=m/2; j++)
        for(int k=1; k<=n/2; k++) {
            t1 = SQ( COS(PI * j / (m+1)) );
            t2 = SQ( COS(PI * k / (n+1)) );


            pre = res;
            res = fmod(res * ( tm * t1 + tm * t2), mod);
            // res = fmod(res, mod);
            // while(res >= mod) res -= mod;
            cout << ( tm * t1 + tm * t2) << '\n';
            // cout << pre <<" -> "<<res<<" | "<<(pre==res)<<"\n";
        }
        cout <<"DBG: "<< res << '\n';

        // while(res >= mod) res -= mod;
        res = fmod(res, mod);
        wi(ll(round(res))); wc('\n');
    }
}