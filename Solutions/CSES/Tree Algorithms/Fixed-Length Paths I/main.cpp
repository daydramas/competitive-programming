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

int n, k;
vi *adj;

using di = deque<int>;
ll combine(di& a, di& b) {
    if (a.size() < b.size()) swap(a, b);
    int as = a.size();
    int bs = b.size();
    ll res = 0;
    for (int i = max(0, (k - bs) + 1); i < min(k + 1, as); ++i)
        res += a[i] * b[k-i];
    for (int i = 0; i < bs; ++i) a[i] += b[i];
    return res;
}

pair<ll, di> solve(int i, int p) {
    pair<ll, di> res = {(k == 0), {1}};
    for (int t : adj[i]) {
        if (t == p) continue;
        auto sub = solve(t, i);
        sub.second.push_front(0);
        res.first += sub.first + combine(res.second, sub.second);
    }
    return res;
}

int main() {

    ri(n,k); int a,b;
    adj = new vi[n+1];
    F0R(i,n-1) {
        ri(a,b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    ll ans = solve(1, 1).first;
    wi(ans); wc('\n');
}