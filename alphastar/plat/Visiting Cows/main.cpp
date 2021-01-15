#include <bits/stdc++.h>
using namespace std;

#define pb push_back
const int maxn = 5e4+5;
int n, dp[maxn][2];
vector<int> adj[maxn];

void dfs(int a, int c=0) {
    dp[a][0]=0, dp[a][1]=1;
    for(int b : adj[a]) if(b!=c) {
        dfs(b, a);
        dp[a][0] += max(dp[b][0],dp[b][1]);
        dp[a][1] += dp[b][0];
    }
}
int main() {
    cin >> n;
    for(int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << "\n";
}