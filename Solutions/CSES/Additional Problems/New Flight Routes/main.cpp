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
#define rsz resize

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

/* SCC from BenQ */
const int maxn = 1e5+5;
struct SCC {
	int N; vi adj[maxn], radj[maxn];
	// vi todo, comp, comps; vector<bool> vis;
    int comp[maxn]; vi comps, todo;
    bool vis[maxn];
	void init(int _N) { N = _N; }
	void ae(int x, int y) { adj[x].pb(y), radj[y].pb(x); }
	void dfs(int x) {
		vis[x] = 1; trav(y,adj[x]) if (!vis[y]) dfs(y);
		todo.pb(x); }
	void dfs2(int x, int v) {
		comp[x] = v;
		trav(y,radj[x]) if (comp[y] == -1) dfs2(y,v); }
	void gen() { // fills allComp
        FOR(i,1,N) comp[i]=-1, vis[i]=false;
		FOR(i,1,N) if (!vis[i]) dfs(i);
		reverse(all(todo));
        // cout <<"todo: {"; trav(x,todo) cout << x <<" "; cout <<"}\n";
		trav(x,todo) if (comp[x] == -1) dfs2(x,x), comps.pb(x);
	}
    bool gen2() { // fills allComp
        comps.clear(); todo.clear();
        FOR(i,1,N) comp[i]=-1, vis[i]=false;
		FOR(i,1,N) if (!vis[i]) dfs(i);
		reverse(all(todo));
        // cout <<"todo: {"; trav(x,todo) cout << x <<" "; cout <<"}\n";
		trav(x,todo) if (comp[x] == -1) {
            if(sz(comps)) return false;
            dfs2(x,x), comps.pb(x);
        }
        return 1;
	}
};

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ins insert
#define ers erase
#define oof order_of_key
#define fbo find_by_order

int n, m;
SCC S;
vector<pair<int,int>>E;
int IN[maxn], OUT[maxn], ID[maxn];
// vi in, rin, out, rout;
vi in,out;
// Tree<int> T[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    // cerr <<"\n+------ Starting\n"; clock_t startT = clock();
    cin >> n >> m;
    S.init(n);
    while(m--) {
        int a, b; cin >> a >> b;
        if(a==b) continue;
        S.ae(a, b);
        E.pb({a,b});
    }
    S.gen();
    if(sz(S.comps)==1) {
        cout <<"0\n";
        return 0;
    }
    // cout <<"{";FOR(i,1,n) cout << S.comp[i] <<" "; cout <<"}\n";
    FOR(i,1,n) IN[i]=OUT[i]=0, ID[S.comp[i]]=i;
    // cout <<"{"; FOR(i,1,n) cout << S.comp[i]<<" "; cout <<"}\n";
    trav(e, E) {
        if(S.comp[e.f]!=S.comp[e.s]) {
            IN[S.comp[e.s]]++;
            OUT[S.comp[e.f]]++;
            // T[S.comp[e.f]].ins(S.com[e.s])
        }
    }
    // cout <<"{";
    using pi = pair<int,int>;
    trav(i, S.comps) {
        if(!IN[i]) in.pb(i);
        if(!OUT[i]) out.pb(i);
    } //cout <<"}\n";
    // cout <<"in: {";trav(x,in) cout<<x<<" "; cout <<"}\n";
    // cout <<"out: {";trav(x,out) cout<<x<<" "; cout <<"}\n";
    cout << max(sz(in), sz(out)) <<"\n";
    int m = max(sz(in),sz(out));
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    // shuffle(all(in),default_random_engine(seed));
    // while(1) {
    int lb = 13e6/n;
    vector<pi> V;
    F0R(I,lb) {
        V.clear();

        shuffle(all(out),default_random_engine(seed));
        F0R(i,m) {
            int ii, jj=-1;
            if(i<sz(in)) ii=i;
            else ii = rand()%sz(in);
            if(i<sz(out)) { jj=i; }
            while(jj==-1 || ID[out[jj]]==ID[in[ii]]) jj = rand()%sz(out);
            V.pb({ID[out[jj]],ID[in[ii]]});
            S.ae(ID[out[jj]], ID[in[ii]]);
            // cout <<"edge: {"<<ID[out[jj]]<<", "<<ID[in[ii]]<<"}\n";
        }
        // cout <<"\n";
        if (S.gen2()) {
            trav(x, V) {
                cout << x.f <<" "<< x.s<<"\n";
            }
            return 0;
        } else {
            trav(x, V) {
                S.adj[x.f].pop_back();
                S.radj[x.s].pop_back();
            }
        };
    }
    trav(x, V) {
        cout << x.f <<" "<< x.s<<"\n";
    }
    // unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    // shuffle(all(in),default_random_engine(seed));
    // shuffle(all(out),default_random_engine(seed));
    // if(sz(in) > sz(out)) {
    //     F0R(i,sz(in)) {
    //         int ii;
    //         if(i<sz(out)) ii=i;
    //         else ii=rand()%sz(out);
    //         while(ii==-1 || ID[out[ii]]==in[i]) {
    //             ii=rand()%sz(out);
    //         }
    //         cout << ID[out[ii]]<< " "<<ID[in[i]] <<"\n";
    //     }
    //     // trav(x, in) cout << "1 "<<ID[x]<<"\n";
    // } else {
    //     F0R(i,sz(out)) {
    //         int ii;
    //         if(i<sz(in)) ii=i;
    //         else ii=rand()%sz(in);
    //         while(ii==-1 || ID[in[ii]]==out[i]) {
    //             ii=rand()%sz(in);
    //         }
    //         cout << ID[out[i]] <<" "<<ID[in[ii]]<<"\n";
    //     }
    //     // trav(x, out) cout <<ID[x]<<" 1\n";
    // }
    // cerr <<"+------ Ending | Time taken: "<<((float)(clock()-startT)/CLOCKS_PER_SEC)<<" seconds \n\n";
}