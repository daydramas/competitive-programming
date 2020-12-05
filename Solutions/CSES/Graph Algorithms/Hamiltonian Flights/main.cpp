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

const int M=20;
const int MOD = 1e9+7;

int n, m;
// int adj[M][M];
vi adj[M];
int dp[M][1<<M];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    F0R(i,n) F0R(j,n) dp[i][j]=0;
    F0R(i,m) {
        int a,b; cin >> a >> b;
        adj[--a].pb(--b);
    }
    dp[0][1]=1;
    dp[0][1] = 1;
    int MX=1<<n;
    F0R(j,MX) F0R(i,n) if (j&(1<<i) && dp[i][j])
        trav(k,adj[i]) if (!(j&(1<<k)))
            dp[k][j^(1<<k)] = (dp[k][j^(1<<k)]+dp[i][j])%MOD;
    cout << dp[n-1][MX-1];

}