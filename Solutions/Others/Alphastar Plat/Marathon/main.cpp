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

/* from bqi343 */
template<class T> struct Seg { // comb(ID,b) = b
	const T ID = 0; T comb(T a, T b) { return a+b; }
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*(n+1),ID); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
	T qry(int l, int r) {	// sum on interval [l, r]
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
};
template<class T> struct RMQ { // comb(ID,b) = b
	const T ID = 1e9; T comb(T a, T b) { return min(a,b); }
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*(n+1),ID); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
	T qry(int l, int r) {	// sum on interval [l, r]
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
};

int n, q;
pi *p;
Seg<ll> d;\
RMQ<ll> m;

ll dist(int i, int j) {
    return abs(p[i].f-p[j].f)+abs(p[i].s-p[j].s);
}
void upd1(int i) {
    if(i<1 || i>n) return;
    if(i!=1) d.upd(i, dist(i,i-1));
}
void upd2(int i) {
    if(i<1 || i>n) return;
    if(i==1 || i==n) return;
    m.upd(i,dist(i-1,i+1)-dist(i,i-1)-dist(i,i+1));
}
int main() {

    ri(n, q);
    p = new pi[n+1];
    d.init(n); m.init(n);
    FOR(i,1,n) ri(p[i].f,p[i].s);
    FOR(i,1,n) upd1(i),upd2(i);
    while(q--) {
        char ch=nc();
        if(ch == 'Q') {
            int a, b; ri(a,b);
            wi(d.qry(a+1,b) + m.qry(a+1,b-1)); wc('\n');
        } else {
            int a; ri(a); ri(p[a].f,p[a].s);
            upd1(a); upd1(a+1);
            upd2(a-1); upd2(a); upd2(a+1);
        }
    }
}