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
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x).size()

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

using Node = pair<ll,int>;
const int maxn = 1e5+5;
const int mod = 1e18+7;
int n, m;
vector<Node> adj[maxn], radj[maxn];
ll dist[maxn], dp[maxn], DP[maxn];

void dijkstra() {
    FOR(i,1,n) dist[i]=1e18;
    priority_queue<Node, vector<Node>, greater<Node> > PQ;
    PQ.push({dist[1]=0,1});
    while(!PQ.empty()) {
        Node F = PQ.top(); PQ.pop();
        if (F.f != dist[F.s]) continue;
        for(auto &e : adj[F.s]) {
            if (F.f+e.f < dist[e.s])
                PQ.push({dist[e.s]=F.f+e.f, e.s});
        }
    }
}
bool comp(int i, int j) { return dist[i]<dist[j]; }
int main() {

    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);

    cin >> n >> m;
    while(m--) {
        int a,b; ll c; cin >> a >> b >> c;
        adj[a].pb({c,b});
        radj[b].pb({c,a});
    }
    dijkstra();
    vi ord; FOR(i,1,n) ord.pb(i);
    sort(rall(ord), comp); DP[1]=dp[n]=1;
    trav(x, ord) if(x!=n) trav(e, adj[x]) if(dist[x]+e.f==dist[e.s])
        dp[x] = (dp[x] + dp[e.s]) % mod;
    reverse(all(ord));
    trav(x, ord) if(x!=1) trav(e, radj[x]) if(dist[x] == dist[e.s]+e.f)
        DP[x] = (DP[x] + DP[e.s]) % mod;
    vi ans; FOR(i,1,n) if((DP[i]*dp[i])%mod == dp[1]) ans.pb(i);
    cout << sz(ans)<<"\n"; trav(x, ans)cout<<x<<" ";
    // cerr << sz(ans)<<"\n"; trav(x, ans)cerr<<x<<" ";


}