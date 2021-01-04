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


const int MOD = 1e9+7;
const int mx = 751;

template<class T> struct BIT {
	int N; T *B;
	BIT() {}
	BIT(int N) { this->N=N; B = new int[N+1]; FOR(i,1,N) B[i]=0; }
	void upd(int i, T V) { for(; i<N; i+=i&(-i)) B[i]=(B[i]+V)%MOD; }
	T qry(int i) { T R=0; for(; i; i-=i&(-i)) R=(R+B[i])%MOD;
		return R; }
};

int r, c, k;
int **g, **ans;
map<int,int> ID;
BIT<int> a, *b;
vector<pi> *clr;

int main() {
    // freopen("hopscotch.in","r",stdin);
    // freopen("hopscotch.out","w",stdout);
    ri(r,c,k);
    g = new int*[r+1];
    ans = new int*[r+1];
    clr = new vector<pi>[k+1];
    FOR(i,1,r) {
        g[i] = new int[c+1];
        ans[i] = new int[c+1];
        FOR(j,1,c) {
            ri(g[i][j]);
            ID[g[i][j]]++;
            clr[g[i][j]].pb({i,j});
            ans[i][j]=0;
        }
    }
    int cnt=0; trav(x, ID) {
        if(x.s<=9) x.s=0;
        else {
            x.s=++cnt;
            clr[x.f].clear();
        }
    }
    a = BIT<int>(c);
    b = new BIT<int>[cnt+1];
    FOR(i,1,cnt) b[i]=BIT<int>(c);
    FOR(i,1,r) {
        ROF(j,1,c) {
            int C=ID[g[i][j]];
            int t = a.qry(j-1);
            if(C) t = (t-b[C].qry(j-1)+MOD)%MOD;
            else trav(x,clr[g[i][j]]) if(x.s<j && x.f<i) t = (t-ans[x.f][x.s]+MOD) % MOD;
            if(i==1 && j==1) t=(t+1)%MOD;
            while(t<0) t+=MOD;
            a.upd(j,t);
            if(C) b[C].upd(j,t);
            ans[i][j] = t;
        }
    }
    wi(ans[r][c]); wc('\n');
}