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

template<int SZ> struct TopoSort {
    vi adj[SZ], res; int w[SZ];
    TopoSort() {
        F0R(i,SZ) w[i]=0;
    }
    void ae(int a, int b) {
        adj[a].pb(b); w[b]++;
    }
    bool sort(int N) {
        // queue<int> Q;
        // priority_queue<int, vi, greater<int>> Q;
        priority_queue<int> Q;

        FOR(i,1,N) if(!w[i]) Q.push(i);
        while(!Q.empty()) {
            int a=Q.top(); Q.pop(); res.pb(a);
            trav(b, adj[a]) if (!(--w[b])) Q.push(b);
        }
        return sz(res)==N;
    }
};

int n, m;
TopoSort<100005> ts;

int main() {

    cin >> n >> m;
    while(m--) {
        int a,b; cin >> a >> b;
        ts.ae(b,a);
    }
    FOR(i,1,n) sort(all(ts.adj[i]));
    ts.sort(n); reverse(all(ts.res));
    trav(x, ts.res) cout << x <<" ";

}