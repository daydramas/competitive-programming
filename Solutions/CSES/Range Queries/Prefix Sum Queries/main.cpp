#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
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

template<class T> struct LSegTree {
	int N; vector<T> t, lz; T U=-1e18;
    T F(T i, T j) { return max(i,j); } LSegTree() {}
	LSegTree(int N) : N(N), t(4*N,U), lz(4*N,0) {}
	void pull(int i) { t[i] = F(t[i*2],t[i*2+1]); }
	void push(int i, int l, int r) {
		t[i]+=lz[i];
		if(l!=r) lz[i*2]+=lz[i], lz[i*2+1]+=lz[i];
		lz[i]=0; }
    void build(vi& v) { build(v,1,1,N); }
    void build(vi&v, int i, int l, int r) {
        if(l==r) { t[i]=v[l]; return; } int m=(l+r)/2;
        build(v,i*2,l,m); build(v,i*2+1,m+1,r); pull(i);
    }
	void upd(int L, int R, T v) { upd(L,R,v,1,1,N); }
	void upd(int L, int R, T v, int i, int l, int r) {
		push(i,l,r); if(R<l || L>r) return;
		if(L<=l && R>=r) { lz[i]+=v; push(i,l,r); return; }
		int m=(l+r)/2; upd(L,R,v,i*2,l,m);
		upd(L,R,v,i*2+1,m+1,r); pull(i); }
	T qry(int L, int R) { return qry(L,R,1,1,N); }
	T qry(int L, int R, int i, int l, int r) {
		push(i,l,r); if(R<l || L>r) return U;
		if(L<=l && R>=r) return t[i]; int m=(l+r)/2;
		return F(qry(L,R,i*2,l,m), qry(L,R,i*2+1,m+1,r)); }
};

int n, m;

int main() {

    ri(n,m);
    vi v(n+1);
    FOR(i,1,n) ri(v[i]);
    LSegTree<ll> st(n);
    FOR(i,2,n) {
        v[i] += v[i-1];
    }
    st.build(v);
    while(m--) {
        int a; ll b, c; ri(a,b,c);
        if(a==1) {
            st.upd(b,n,c-v[b]); v[b]=c;
        } else {
            cout << st.qry(b,c)-st.qry(b-1,b-1) << '\n';
        }
    }

}