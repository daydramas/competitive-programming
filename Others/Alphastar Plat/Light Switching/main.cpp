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


template<class T> struct LSeg {
	int N; T *st, *lz;
	T ID=0; T comb(T i, T j) { return i+j; }
    LSeg() {}
	LSeg(int N) { this->N = N;
		st = new T[4*(N+1)]; lz = new T[4*(N+1)]; }
	void pull(int i) {
		st[i] = comb(st[i*2],st[i*2+1]); }
	void push(int i, int l, int r) {
		if(lz[i]&1) st[i]=(r-l+1)-st[i];
		if(l!=r) lz[i*2]+=lz[i], lz[i*2+1]+=lz[i];
		lz[i]=0; }
	void upd(int L, int R, int i, int l, int r) {
		push(i,l,r); if(R<l || L>r) return;
		if(L<=l && R>=r) { lz[i]++; push(i,l,r); return; }
		int m=(l+r)/2; upd(L,R,i*2,l,m);
		upd(L,R,i*2+1,m+1,r); pull(i); }
	T qry(int L, int R, int i, int l, int r) {
		push(i,l,r); if(R<l || L>r) return ID;
		if(L<=l && R>=r) return st[i]; int m=(l+r)/2;
		return comb(qry(L,R,i*2,l,m), qry(L,R,i*2+1,m+1,r)); }
};

int n, m, a, b, c;
LSeg<int> t;

int main() {

    ri(n,m);
    t = LSeg<int>(n);
    while(m--) {
        ri(a,b,c);
        if(a) {
            wi(t.qry(b,c,1,1,n)); wc('\n');
        } else {
            t.upd(b,c,1,1,n);
        }
    }

}