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

int n, m;
ll adj[501][501];

ll flow[501];
bool vis[501];
int pa[501];
ll src, maxflow, maxloc, pathcapacity, totalflow = 0, currnode, nextnode;


int main() {
    cin >> n >> m;
    FOR(i,1,n) FOR(j,1,n) adj[i][j]=0;
    F0R(i,m) {
        ll a,b,c; cin >> a >> b >> c;
        adj[a][b] += c;
    }
    while (true) {
        memset(flow, 0, sizeof(flow));
        memset(vis, false, sizeof(vis));
        memset(pa, -1, sizeof(pa));
        src = 1, flow[src] = 1e18;
        while (true) {
            maxflow = 0, maxloc = -1;
            for (int i=1; i<=n; i++) if (!vis[i] && flow[i]>maxflow)
                maxflow = flow[i], maxloc = i;
            if (maxloc == -1 || maxloc == n) break;
            vis[maxloc] = true;
            for (int i=1; i<=n; i++) if (adj[maxloc][i]) {
                if (flow[i] < min(maxflow, adj[maxloc][i])) {
                    pa[i] = maxloc;
                    flow[i] = min(maxflow, adj[maxloc][i]);
                }
            }
        }
        if (maxloc == -1) break;
        pathcapacity = flow[n];
        totalflow += pathcapacity;

        currnode = n;
        while(currnode != src) {
            nextnode = pa[currnode];
            adj[nextnode][currnode] -= pathcapacity;
            adj[currnode][nextnode] += pathcapacity;
            currnode = nextnode;
        }

    }
    cout << totalflow;
}