#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vpi = vector<pi>;
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

const int maxn = 2e5+5;
int n, m;
vi *g; vpi g2;
int p[maxn][30];
ll *d, *l, *h;
ll ans=0;

void dfs(int a, int c=0) {
    p[a][0]=c;
    d[a]=d[c]+1;
    trav(b,g[a]) if(b!=c) dfs(b,a);
}
void dfs2(int a, int c=0) {
    int ol = l[a];
    trav(b,g[a]) if(b!=c) {
        dfs2(b, a); l[a]+=l[b]; }
    ans += h[a]*(l[a]-ol);
}
void pull() {
    FOR(i,1,29) FOR(j,1,n) {
        p[j][i] = p[p[j][i-1]][i-1]; }
}
int fetch(int a, int b) {
    if(d[a] < d[b]) swap(a,b);
    int D = (d[a]-d[b]);
    F0R(i,30) if((1<<i) & D) a=p[a][i];
    if(a==b) return a;
    R0F(i,30) if(p[a][i] != p[b][i]) {
        a=p[a][i], b=p[b][i]; }
    if(a!=b) { a=p[a][0], b=p[b][0]; }
    assert(a==b);
    return a;
}
int jump(int a, int D) {
    F0R(i,30) if((1<<i) & D) a=p[a][i];
    return a;
}
int main() {
    // ifstream fin("exercise.in");
    ifstream fin("exercise_platinum_jan19/5.in");
    ofstream fout("exercise.out");
    fin >> n >> m;
    g = new vi[n+1];
    d = new ll[n+1];
    h = new ll[n+1];
    l = new ll[n+1];
    FOR(i,1,n-1) {
        int a, b; fin >> a >> b;
        g[a].pb(b); g[b].pb(a);
    }
    d[0]=-1; dfs(1); pull();
    FOR(i,n,m) {
        int a, b; fin >> a >> b;
        int c = fetch(a,b);
        h[c]++; l[a]++, l[b]++, g2.pb({a,b});
    }
    dfs2(1); ans=0;
    cout << ans << '\n';
    F0R(i,sz(g2)) {
        g2[i].f = jump(g2[i].f, d[g2[i].f]-1);
        g2[i].s = jump(g2[i].s, d[g2[i].s]-1);
        g2[i] = {min(g2[i].f,g2[i].s),max(g2[i].f,g2[i].s)};
    }
    F0R(i,sz(g2)) FOR(j,i+1,sz(g2)-1) {
        if(g2[i] != g2[j]) {
            if(g2[i].f==g2[j].f||g2[i].f==g2[j].s ||
               g2[i].s==g2[j].f||g2[i].s==g2[j].s)
                ans++;
        }
    }
    cout << ans << '\n';
}