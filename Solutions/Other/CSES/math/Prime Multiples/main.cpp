#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

using ll = long double;
using pi = pair<int,int>;
using vi = vector<ll>;
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
using real_ll = long long;
real_ll n, r; int k, c;
vi a;

// ofstream fout("f.txt");

void f(int i, ll s=1, int c=0) {
    if(s<=0 || s>n) {
        // fout << "s = "<<s<<'\n';
        // fout << t << " => " << s<< '\n';
        return;
    }
    if(i==k) {
        if(c==0) return;
        // fout <<r <<" "<<n/s<<"\n";
        real_ll ns = s;
        if(c%2) r = r + (real_ll)n/ns;
        else r = r - (real_ll)n/ns;
        return;
    }
    f(i+1,s,c);
    f(i+1,s*a[i],c+1);
}

int main() {

    ri(n); ri(k);
    a.resize(k);
    F0R(i,k) ri(a[i]);
    r=0; f(0);
    wi(r); wc('\n');
    // cout <<"n = "<<n<<"\n";
}