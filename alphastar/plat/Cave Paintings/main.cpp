#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
const int mod = 1e9+7;
int n, m;
string g[maxn];
int v[maxn], c[maxn][maxn], dp[maxn*maxn];
#define vi vector<int>
#define pb push_back
vector<vi> comps;
vector<pair<int,int>> adj[maxn][maxn];
using pi = pair<int,int>;
vector<pair<pi,pi>> todo;
int D[maxn][maxn];
void init() { for(int i=0; i<maxn; i++) for(int j=0; j<maxn; j++) D[i][j]=-1; }
int par(int x, int id) { return D[id][x]<0 ? x : D[id][x]=par(D[id][x], id); }
bool comb(int id, int x, int y) {
    // cout <<"comb("<<id<<","<<x<<","<<y<<") => ("<<par(x,id)<<","<<par(y,id)<<")\n";
    x=par(x, id), y=par(y, id); if(x==y) return 0;
    if(x>y) swap(x,y);
    // cout <<"merged I="<<id<<" | ("<<x<<", "<<y<<")\n";
    D[id][x]+=D[id][y], D[id][y]=x; return 1;
}
int id(int i, int j) {
    return i+1001*j;
}
void dfs(int i, int j) {
    dp[id(i,j)]=1;
    // sort(adj[i][j].begin(), adj[i][j].end());
    // adj[i][j].erase( unique( adj[i][j].begin(), adj[i][j].end() ), adj[i][j].end() );
    for(auto x : adj[i][j]) {
        dfs(x.first,x.second);
        dp[id(i,j)]=(1LL*dp[id(i,j)]*dp[id(x.first,x.second)]) % mod;

        // dp[i][j] = mod;
    }
    dp[id(i,j)]=(dp[id(i,j)]+1) % mod;
    // cout <<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<"\n";
    // return dp[i][j];
}

int main() {
    // cout <<"mod = "<<mod<<"\n";
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("cave_platinum_jan20/7.in", "r", stdin);
    cin >> n >> m;
    for(int i=1; i<=n; i++) { cin >> g[i]; g[i]=" "+g[i]; }
    init();
    memset(c, 0, sizeof(c));
    for(int i=n; i>=1; i--) {
        int ncomps=m;
        for(int j=1; j<=m; j++) {
            v[j]=-1; /*if(g[i][j]=='#') ncomps--; */}
        for(int j=1; j<m; j++) if(g[i][j]=='.' && g[i][j+1]=='.') {
            if(comb(i, j, j+1)) {} /*ncomps--;*/ }

        // cout <<"i="<<i<<" | sz="<<comps.size()<<"\n";
        if(i==n) {}
        else for(vi& x : comps) {
            // cout <<"x={"; for(auto y:x) cout <<y<<", "; cout <<"\n";
            if(x.empty()) {  continue; }
            int k=0;
            while(k<x.size() && g[i][x[k]]=='#') k++;
            // cout <<"k="<<k<<"\n";
            if(k<x.size()) {
                // if(g[i][x[k]]=='#') cout <<"this should not happen :|\n";
                // adj[i][par(x[k],i)].pb({i+1,par(x[k],i+1)});
                todo.pb({{i,par(x[k],i)},{i+1,par(x[k],i+1)}});
                if(i==6 && par(x[k],i)==2) {
                    // cout <<"pb({"<<i+1<<","<<par(x[k],i+1)<<"})\n";
                }
                // cout <<"edge( {"<<i<<","<<par(x[k],i)<<"}, {"<<i+1<<","<<par(x[k],i+1)<<"} )\n";
                // c[i+1][par(x[k],i+1)]++;
                for(int l=k+1; l<x.size(); l++) {
                    if(g[i][x[l]]=='#') continue;
                    if(comb(i, par(x[k],i), par(x[l],i))) {
                        // cout <<"merged (i="<<i<<", "<<par(x[k],i)<<","<<par(x[l],i)<<")\n";
                    }
                }
            } /*else {
                // cout <<"00 pb\n";
                adj[0][0].pb({i+1,par(x[k],i+1)});
            }*/
            // x.clear();
        }
        comps.clear(); comps.resize(ncomps); int in=0;
        for(int j=1; j<=m; j++) if(g[i][j]=='.') {
            if(v[par(j,i)] == -1) v[par(j,i)]=in++;
            comps[v[par(j,i)]].pb(j);
        }
        // if(in>ncomps) { cout <<"hmm\n"; }
    }
    #define f first
    #define s second
    for(auto x : todo) {
        adj[x.f.f][par(x.f.s,x.f.f)].pb({x.s.f,par(x.s.s,x.s.f)});
        c[x.s.f][par(x.s.s,x.s.f)]++;
    }
    // for(auto x : comps) {
    //     for(int k=0; k<x.size(); k++) {
    //         if(D[1][x[k]]<0 && g[1][x[k]]=='.') {
    //             adj[0][0].pb({1,x[k]});
    //         }
    //     }
    // }
    for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++) if(g[i][j]=='.' && D[i][j]<0 && c[i][j]==0) adj[0][0].pb({i,j});
    dfs(0,0);
    // cout <<"sz="<<adj[0][0].size()<<"\n";
    // ofstream fout("output2.txt");
    // for(auto x : adj[4][2]) {
    //     fout << x.first <<" "<<x.second << " -> "<<dp[id(x.first,x.second)] <<"\n";
    // }
    cout << (dp[0]+mod-1) % mod << "\n";

}