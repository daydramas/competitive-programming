#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef string str;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<str> vs;

#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define pb push_back

#define for0(a,n) for(int a = 0; a < (n); ++a)
#define for1(a,n) for(int a = 1; a <= (n); ++a)
#define rof0(a,n) for(int a = (n-1); a >= 0; --a)
#define rof1(a,n) for(int a = (n); a >= 1; --a)
#define trav(a,x) for (auto& a: x)

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
const ll INF = 1e18;
const double PI = acos(-1);
const int X[4] = {1,0,-1,0}, Y[4] = {0,1,0,-1};
const str D[4] = {"D", "R", "U", "L"};

/* Source: Benq (https://github.com/bqi343/USACO) [Modified] */

template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

namespace IO {
    void setIO(string PROB = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (sz(PROB)) {
            freopen((PROB+".in").c_str(),"r",stdin);
            freopen((PROB+".out").c_str(),"w",stdout);
        }
    }

    /* Input */
    template<class A, class B> void re(pair<A,B>& p);
    template<class A> void re(vector<A>& v);
    template<class T> void re(T& x) { cin >> x; }
    template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }
    template<class A, class B> void re(pair<A,B>& p) { re(p.f,p.s); }
    template<class A> void re(vector<A>& x) { trav(a,x) re(a); }

    /* To String */
    str ts(int i) { return to_string(i); }
    str ts(bool b) { return b ? "true" : "false"; }
    str ts(char c) { str s=""; s+=c; return s; }
    str ts(str s) { return s; }
    str ts(const char* s) { return (str)s; }
    template<class T> str ts(vector<T> v) {
        bool fst=1; str res="{";
        trav(a, v) {
            if (!fst) res += ", ";
            fst = 0; res += ts(a);
        }
        res+="}"; return res;
    }

    /* Output */
    template<class A> void pr(A x) { cout << ts(x); }
    template<class H, class... T> void pr(const H& h, const T&... t) {
        pr(h); pr(t...); }
    void pl() { cout << "\n"; }
}
using namespace IO;

/* ============================ */

int main() {
    setIO("");

    int n,m; re(n,m);
    vs g(n); re(g);
    vvi v(n, vi(m, 0));
    pair<pii,str> back[n][m];
    pii a, b;
    for0(i,n) for0(j,m) {
        if (g[i][j]=='A') a={i,j};
        if (g[i][j]=='B') b={i,j};
    }
    queue<pii> Q;
    Q.push(a); v[a.f][a.s]=1;
    str ans = "NO";
    while(!Q.empty()) {
        pii c=Q.front();
        Q.pop();
        if(c == b) { ans="YES"; }

        for0(k,4) {
            int x=c.f+X[k],y=c.s+Y[k];
            if (x>=0 && x<n && y>=0 && y<m)
                if (g[x][y]!='#' && !v[x][y]) {
                    Q.push({x,y});
                    v[x][y]=1;
                    back[x][y]={c,D[k]};
                }

        }
    }
    cout << ans <<"\n";
    if(ans == "YES") {
        str anss="";
        while(b!=a) {
            anss+=back[b.f][b.s].s;
            b=back[b.f][b.s].f;
        }
        reverse(all(anss));
        cout << sz(anss)<<"\n"<<anss;
    }

}