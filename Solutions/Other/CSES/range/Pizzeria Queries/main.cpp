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

template<class T> struct SegTree {
    T U = 1e18; T F(T a, T b) { return min(a,b); }
    int N; vector<T> t; SegTree() {}
    SegTree(int N) : N(N), t(4*N,U) {}
    void upd(int I, T V) { upd(I,V,1,1,N); }
    void upd(int I, T V, int i, int l, int r) {
        if(l==r) { t[i]=V; return; } int m=(l+r)/2;
        if(l<=I && I<=m) upd(I,V,i*2,l,m);
        if(m+1<=I && I<=r) upd(I,V,i*2+1,m+1,r);
        t[i] = F(t[i*2], t[i*2+1]); }
    T qry(int L, int R) { return qry(L,R,1,1,N); }
    T qry(int L, int R, int i, int l, int r) {
        if(L<=l && r<=R) return t[i];
        if(R<l || L>r) return U; int m=(l+r)/2;
        return F(qry(L,R,i*2,l,m), qry(L,R,i*2+1,m+1,r)); }
};

int n, q, *v;
SegTree<ll> D, U;

int main() {

    ri(n, q);
    D = SegTree<ll>(n);
    U = SegTree<ll>(n);
    v = new int[n+1];
    FOR(i,1,n) {
        ri(v[i]);
        D.upd(i,v[i]-i);
        U.upd(i,v[i]+i);
    }
    int t, a, b;
    while(q--) {
        ri(t);
        if(t==1) {
            ri(a,b); v[a]=b;
            D.upd(a,b-a);
            U.upd(a,b+a);
        } else {
            ri(a);
            b=min(D.qry(1,a)+a, U.qry(a,n)-a);
            wi(b); wc('\n');
        }
    }

}