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

const int maxn = 2505;

int n,m,d[maxn],p[maxn];
vi adj[maxn];
queue<int> Q;

int fro() {
    int x=Q.front(); Q.pop();
    return x;
}

int main() {

    cin >> n >> m;
    F0R(i,m) {
        int a,b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int ans = 1e9;
    FOR(i,1,n) {
        FOR(j,1,n) p[j]=0;
        d[i]=0; Q.push(i); p[i]=-1;
        while(!Q.empty()) {
            int x=fro();
            trav(y, adj[x]) {
                if (!p[y]) d[y]=d[x]+1, p[y]=x, Q.push(y);
                else if (p[x]!=y) ans=min(ans, d[x]+d[y]+1);
            }
        }
    }
    if (ans == 1e9) ans=-1;
    cout << ans;
}