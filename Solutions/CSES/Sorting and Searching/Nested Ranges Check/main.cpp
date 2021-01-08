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

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int mn = 200005;
int n, c[mn], d[mn];
vector<pi> a; vi ord;
map<int,int> M;

template<class T> struct BIT {
    int N; vector<T> t; BIT() {}
    BIT(int N) : N(N), t(N+1) {}
    void upd(int i, T V) { for(; i<=N; i+=i&(-i)) t[i]+=V; }
    T qry(int i) { T R=0; for(; i; i-=i&(-i)) R+=t[i]; return R; }
    T qry(int l, int r) { return qry(r)-qry(l-1); }
};

BIT<int> t;


bool comp(int i, int j) {
    if(a[i].s==a[j].s) return a[i].f>a[j].f;
    return a[i].s<a[j].s;
}

int main() {

    ri(n); a.resize(n);
    F0R(i,n) ord.pb(i);
    F0R(i,n) { ri(a[i].f,a[i].s);
        M[a[i].f]=1; }
    int cnt=0; trav(x, M) x.s=++cnt;
    t = BIT<int>(cnt); int x;
    sort(all(ord), comp);
    trav(i, ord) {
        x = M[a[i].f];
        c[i] = t.qry(cnt)-t.qry(x-1);
        t.upd(x,1);
    } t = BIT<int>(cnt); reverse(all(ord));
    trav(i, ord) {
        x = M[a[i].f];
        d[i] = t.qry(x);
        t.upd(x,1);
    }
    F0R(i,n) { wi((bool)c[i]); wc(' '); } wc('\n');
    F0R(i,n) { wi((bool)d[i]); wc(' '); } wc('\n');
}