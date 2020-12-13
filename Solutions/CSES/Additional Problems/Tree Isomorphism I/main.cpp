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

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

const int maxn = 1e5+5;

int n, d[maxn],pa[maxn][2],c[maxn][2];
vi order, adj[maxn][2];
vector<string> t;
string ans[maxn];

void dfs1(int par, int cur, int it) {
    trav(chi, adj[cur][it]) if(chi!=par) {
        d[chi] = d[cur]+1;
        // pa[chi] = cur;
        // cout <<"d["<<chi<<"]["<<it<<"] = "<<d[chi][it]<<"\n";
        dfs1(cur, chi, it);
    }
}
void dfs(int par, int cur, int it) {
    trav(chi, adj[cur][it]) if(chi!=par) {
        d[chi] = d[cur]+1;
        pa[chi][it] = cur;
        // cout <<"d["<<chi<<"]["<<it<<"] = "<<d[chi][it]<<"\n";
        dfs(cur, chi, it);
    }
}
bool comp(int i, int j) {
    return d[i] > d[j];
}
string solve2(int it) {
    d[1]=0; dfs(-1, 1, it);
    order.clear();
    FOR(i,1,n) order.pb(i), ans[i]="";
    sort(all(order), comp); //cout <<"{";
    trav(x, order) {
        //cout << x <<" ";
        ans[x]="["; t.clear();
        trav(y, adj[x][it]) if(y!=pa[x][it]) t.pb(ans[y]);
        sort(all(t)); trav(y,t) ans[x]+=y;
        ans[x]+="]";
    } //cout <<"}\n";
    return ans[1];
}
void F() {
    cin >> n;
    FOR(i,1,n) F0R(j,2) adj[i][j].clear(), c[i][j]=d[i]=pa[i][j]=0;

    F0R(it,2) FOR(i,1,n-1) {
        int a,b; cin >> a >> b;
        adj[a][it].pb(b);
        adj[b][it].pb(a);
    }

    if(n <= (1e4)) {
        string a=solve2(0);
        string b=solve2(1);
        cout << (a==b?"YES":"NO") <<"\n";
        return;
    }


    d[1]=1; dfs1(-1,1,0); FOR(i,1,n) c[d[i]][0]++;
    d[1]=1; dfs1(-1,1,1); FOR(i,1,n) c[d[i]][1]++;
    FOR(i,1,n) if(c[i][0] != c[i][1]) { cout<<"NO\n"; return; }
    FOR(i,1,n) F0R(j,2) c[i][j]=0;
    F0R(it,2) FOR(i,1,n) c[adj[i][it].size()-(bool)(i!=1)][it]++;
    FOR(i,1,n) if(c[i][0] != c[i][1]) { cout <<"NO\n"; return; }
    if(adj[1][0].size() != adj[1][1].size()) { cout <<"NO\n"; return; }
    F0R(it,2) FOR(i,1,n) c[i][it]=0;
    F0R(it,2) trav(x, adj[1][it]) c[adj[x][it].size()-1][it]++;
    FOR(i,1,n) if(c[i][0] != c[i][1]) { cout <<"NO\n"; return; }
    cout <<"YES\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--) F();

}
/*
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

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

const int maxn = 1e5+5;
int n, d[maxn],pa[maxn];
vi order, adj[maxn][2];
string t[maxn];
// string ans[maxn];
array<char,maxn>

void dfs(int par, int cur, int it) {
    trav(chi, adj[cur][it]) if(chi!=par) {
        d[chi] = d[cur]+1;
        pa[chi] = cur;
        // cout <<"d["<<chi<<"]["<<it<<"] = "<<d[chi][it]<<"\n";
        dfs(cur, chi, it);
    }
}
bool comp(int i, int j) {
    return d[i] > d[j];
}
string solve2(int it) {
    d[1]=pa[1]=0; dfs(-1, 1, it);
    cerr <<"done dfsing..." <<endl;
    order.clear();
    FOR(i,1,n) order.pb(i), ans[i]="";
    sort(all(order), comp); //cout <<"{";
    cerr <<"beginning to calculate..." <<endl;
    // trav(x, order) {
    F0R(idk, n) {
        int x=order[idk];
        //cout << x <<" ";
        ans[x]="["; int tsz=0;
        trav(y, adj[x][it]) if(y!=pa[x]) t[tsz++]=ans[y];
        sort(t, t+tsz); F0R(idk2,tsz) ans[x].append(t[idk2]);
        ans[x]+="]";
    } //cout <<"}\n";
    cerr <<"returning answer..." <<endl;
    return ans[1];
}
void solve() {
    cin >> n;
    FOR(i,1,n) F0R(j,2) adj[i][j].clear();
    F0R(j,2) F0R(it,n-1) {
        int a,b; cin >> a >> b;
        adj[a][j].pb(b);
        adj[b][j].pb(a);
    }
    // cerr <<"gonna dfs"<<endl;
    // dfs(-1, 1,0); string a = ans[1];
    // cerr <<"dfsed 1"<<endl;
    // dfs(-1, 1,1); string b = ans[1];
    // cerr <<"dfsed 2"<<endl;
    cerr <<"starting to solve #1..."<<endl;
    string a=solve2(0);
    cerr <<"starting to solve #2..."<<endl;
    string b=solve2(1);
    cerr <<"done..."<<endl;
    cout << (a==b?"YES":"NO") <<"\n";
}

int main() {

    cerr <<"\n+------ Starting\n"; clock_t startT = clock();
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("input.in","r",stdin);
	freopen("output.in","w",stdout);

    int t; cin >> t;
    while(t--) solve();
    cerr <<"+------ Ending | Time taken: "<<((float)(clock()-startT)/CLOCKS_PER_SEC)<<" seconds "<<endl<<endl;
}
*/