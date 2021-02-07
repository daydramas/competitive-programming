#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
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

struct SCC {
	int N; vi *g, *rg;
	vi td, cmps; int *cmp; bool *v;
	void init(int N) { this->N = N;
        g = new vi[N+1], cmp = new int[N+1];
        rg = new vi[N+1], v = new bool[N+1]; }
	void ae(int x, int y) {
        g[x].pb(y), rg[y].pb(x); }
	void t1(int x) { v[x]=1;
        trav(y,g[x]) if(!v[y]) t1(y);
		td.pb(x); }
	void t2(int x, int z) { cmp[x]=z;
		trav(y,rg[x]) if(!cmp[y]) t2(y,z); }
	void scc() {
		FOR(i,1,N) if(!v[i]) t1(i); reverse(all(td));
		trav(x,td) if(!cmp[x]) t2(x,x), cmps.pb(x);
	}
};
struct TopoSort {
    int N, *w; vi *g, r;
    void init(int N) {
        this->N=N; g = new vi[N+1];
        w = new int[N+1]; }
    void ae(int a, int b) {
        g[a].pb(b); w[b]++; }
    bool sort() {
        queue<int> Q; r.clear();
        for(int i=1; i<=N; i++) if(!w[i]) {
            Q.push(i); }
        while(Q.size()) {
            int a=Q.front(); Q.pop(); r.pb(a);
            for(int b : g[a]) if(!--w[b]) {
                Q.push(b); }
        }
        return r.size()==N;
    }
};
int n, m, *dp, *DP, *cnt;
SCC G; TopoSort T;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    dp = new int[n+1];
    DP = new int[n+1];
    cnt = new int[n+1];
    G.init(n); T.init(n);
    FOR(i,1,n) dp[i]=DP[i]=-1e9;
    while(m--) {
        int a, b; cin >> a >> b;
        G.ae(a,b);
    }
    // cout <<"DONE INPUT"<<endl;
    G.scc();
    // cout <<"DONE SCC"<<endl;
    vi *g3 = new vi[n+1];
    FOR(i,1,n) cnt[G.cmp[i]]++;
    FOR(i,1,n) trav(j,G.g[i]) { if(G.cmp[i]!=G.cmp[j])
        T.ae(G.cmp[i],G.cmp[j]), g3[G.cmp[i]].pb(G.cmp[j]); }
    // cout <<"DONE +EDGES"<<endl;
    T.sort();
    // cout <<"DONE TSORT"<<endl;
    dp[G.cmp[1]] = cnt[G.cmp[1]];
    trav(i,T.r) trav(j,g3[i]) dp[j]=max(dp[j],dp[i]+cnt[j]);
    reverse(all(T.r));
    trav(i,T.r) {
        if(i!=G.cmp[1])trav(j,g3[i]) {
        // cout << "DP["<<i<<"]=max("<<DP[i]<<","<<DP[j]<<"+"<<cnt[i]<<'\n';
            DP[i]=max(DP[i],DP[j]+cnt[i]);
        }
        if(i==G.cmp[1]) DP[i]=0;
    }
    int ans=0;
    FOR(i,1,n) if(G.cmp[i]==i) {
        trav(j,g3[i]) {
            // cout <<"dp["<<j<<"]+"<<"DP["<<i<<"]-cnt["<<i<<"] = "<< dp[j]<<"+"<<DP[i]<<"-"<<cnt[i]<<"\n";
            ans=max(ans,dp[j]+DP[i]);
        }
    }
    cout << ans << '\n';
}