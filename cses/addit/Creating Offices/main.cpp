#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

const int maxn = 2e5+5;
int n, d;
vi adj[maxn], ans;
int D[maxn], D2[maxn], F[maxn];

void dfs(int cur, int par, int dis) {
    // cout <<"cur="<<cur<<" | par="<<par<<" | d1: "<<dis<<"\n";
    D[cur] = dis; int dis2=1e9, f2=-1, f;
    trav(nex, adj[cur]) if(par!=nex) {
        dfs(nex, cur, dis+1);
        dis2 = min(dis2, D2[nex]);
        if((f=F[nex])==-1) continue;
        if((D[f]-dis)*2 >= d) {
            ans.pb(f), dis2=min(dis2, D[f]);
        } else if(f2==-1 || D[f2]<D[f]) f2=f;
    }
    D2[cur]=dis2;
    if(f2!=-1 && D[f2]-dis-dis+dis2 < d) f2=-1;
    if(f2==-1 && dis2-dis >= d) f2=cur;
    F[cur]=f2;
}

int main() {

    cin >> n >> d;
    F0R(i,n-1) {
        int a,b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1,1,0); if(F[1]!=-1)ans.pb(F[1]);
    cout << sz(ans) <<"\n";
    // FOR(i,1,n) cout <<"i="<<i<< " | d1: "<<D[i]<<" | d2: "<<D2[i]<<"\n";
    trav(x, ans) cout << x <<" ";

}
