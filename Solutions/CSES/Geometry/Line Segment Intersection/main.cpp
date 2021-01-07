#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll,ll>;
using vi = vector<int>;
#define x first
#define y second
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

struct line {
	pi p1, p2;
};
int ccw(pi p0, pi p1, pi p2) {
	ll dx1, dx2, dy1, dy2;
	dx1 = p1.x - p0.x; dy1 = p1.y - p0.y;
	dx2 = p2.x - p0.x; dy2 = p2.y - p0.y;
	if (dx1 * dy2 > dy1 * dx2) return +1;
	if (dx1 * dy2 < dy1 * dx2) return -1;
	if ((dx1 * dx2 < 0) || (dy1 * dy2 < 0)) return -1;
	if ((dx1 * dx1 + dy1 * dy1) < (dx2 * dx2 + dy2 * dy2)) return +1;
	return 0;
}
int intersect(struct line l1, struct line l2) {
	return ((ccw(l1.p1, l1.p2, l2.p1) * ccw(l1.p1, l1.p2, l2.p2)) <= 0)
			&& ((ccw(l2.p1, l2.p2, l1.p1) * ccw(l2.p1, l2.p2, l1.p2)) <= 0);
};

int main() {

    int q; ri(q);
    line a, b;
    while(q--) {
        ri(a.p1.x,a.p1.y,a.p2.x,a.p2.y,b.p1.x,b.p1.y,b.p2.x,b.p2.y);
        if(intersect(a,b)) ws("YES\n");
        else ws("NO\n");
    }

}