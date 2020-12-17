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

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ins insert
#define ers erase
#define oof order_of_key
#define fbo find_by_order

const int maxn = 1e5+5;
int n;
vi adj[maxn][2];
vi c[maxn][2];
// string ans[maxn][2];

string dfs(int par, int cur, int it) {
    string res=""; vector<string> child;
    trav(chi, adj[cur][it]) if(chi!=par)
        child.pb(dfs(cur, chi, it));
    sort(all(child));
    res += "["; trav(x,child) res += x;
    res += "]"; child.clear();
    return res;
}
void solve() {
    cin >> n; //cerr << "n="<<n<<endl;
    FOR(i,1,n) adj[i][0].clear(), adj[i][1].clear();
    FOR(i,0,n+1) c[i][0].clear(), c[i][1].clear();
    F0R(i,2) F0R(j,n-1) {
        int a,b; cin >> a >> b;
        adj[a][i].pb(b);
        adj[b][i].pb(a);
    }
    F0R(i,2) FOR(j,1,n) c[adj[j][i].size()][i].pb(j);
    FOR(i,0,n+1) {
        if(sz(c[i][0]) != sz(c[i][1])) { cout <<"NO\n"; return; }
    }
    if(n <= 10000) {
        int touse=4; if(touse>n) touse=n;
        string a = dfs(-1, touse, 0);
        FOR(i,1,n) if(adj[i][1].size() == adj[touse][0].size()) {
            Tree<int>S;
            trav(x, adj[touse][0]) S.insert(adj[x][0].size());
            bool ok = true;
            trav(x, adj[i][1]) if(S.find(adj[x][1].size()) == S.end()) { ok=false; break; }
            if(!ok) continue;
            string b = dfs(-1, i, 1);
            if(b==a) { cout <<"YES\n"; return; }
        } cout <<"NO\n";
        return;
    }
    cout <<"YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    // cerr <<"\n+------ Starting\n"; clock_t startT = clock();
    int t; cin >> t;
    while(t--) {
        solve();
    }
    // cerr <<"+------ Ending | Time taken: "<<((float)(clock()-startT)/CLOCKS_PER_SEC)<<" seconds \n\n";
}