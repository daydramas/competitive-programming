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

struct SEG { int x, y1, y2, t; };

int n, xtime;

pi pre, cur;
pi F(pi a) {
    if(a.f>a.s) swap(a.f,a.s);
    return a; }

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct SEGS {
    Tree<pi> t;
    SEGS() { t = {}; }
    void clear() {t.clear(); }
    void insert(int x, int T) { t.insert({x,T}); }
    void erase(int x, int T) { assert(t.find({x,T}) != t.end()); t.erase({x,T}); }
    int query(pi x) { return t.order_of_key({x.s-1,1e9+7}) - t.order_of_key({x.f,1e9+7}); };
};
SEGS BIT[100005];

void upd(int i, int inc, int x, int t) {
    // cout <<"UPD(t="<<i<<", inc="<<inc<<", x="<<x<<")\n";
    for(; i<=n; i+=i&(-i)) {
        if(inc==1) BIT[i].insert(x,t);
        else BIT[i].erase(x,t);
    }
}
int qry(int i, pi x) {
    int R=0; if(i<=0) return 0; int oi = i;
    for(; i; i-=i&(-i)) R+=BIT[i].query(x);
    // cout <<"QRY(t="<<oi<<", x={"<<x.f<<", "<<x.s<<"}) | R="<<R<<"\n";
    return R;
}

long long ans = 0;

struct Node { int x; int t; SEG y; };
bool cmp(Node a, Node b) {
    if(a.x == b.x) {
        if(a.t + b.t == 1) return a.t<b.t;
        else return a.t>b.t;
    }
    return a.x < b.x; }
vector<Node> A;
SEG ts;

void solve(vector<SEG>& ver, vector<SEG>& hor) {
    A.clear();
    F0R(i,sz(ver)) {
        ts = ver[i];
        A.pb({ts.x,0,ts});
    }
    F0R(i,sz(hor)) {
        ts = hor[i];
        A.pb({ts.y1,1,ts});
        A.pb({ts.y2,2,ts});
    }
    sort(all(A), cmp);
    trav(x, A) {
        if(x.t == 0) {
            ans += qry(x.y.t-xtime, {x.y.y1,x.y.y2});
        } else if (x.t == 1) {
            upd(x.y.t, 1, x.y.x, x.y.t);
        } else if (x.t == 2) {
            upd(x.y.t, -1, x.y.x, x.y.t);
        }
    }
}

int main() {
    vector<SEG> ver, hor;
    ri(n,xtime);
    ri(pre.f, pre.s);
    F0R(i,n-1) {
        ri(cur.f, cur.s);
        if(cur.f == pre.f) {
            pi t = F({cur.s, pre.s});
            ver.pb({cur.f, t.f, t.s, i+1});
        }
        else {
            pi t = F({cur.f, pre.f});
            hor.pb({cur.s, t.f, t.s, i+1});
        }
        pre = cur;
    }
    solve(hor, ver);
    FOR(i,1,n) BIT[i].clear();
    solve(ver, hor);
    wi(ans); wc('\n');
}
