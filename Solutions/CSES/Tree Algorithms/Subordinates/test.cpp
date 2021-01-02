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

int n;
vi* adj;
int* ans;

int dfs(int i) {
    ans[i]=1;
    for(int j : adj[i]) ans[i] += dfs(j);
    return ans[i];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    adj = new vi[n+1];
    ans = new int[n+1];
    FOR(i,2,n) {
        int j; cin >> j;
        adj[j].pb(i);
    }
    dfs(1);
    FOR(i,1,n) cout << --ans[i] << ' ';
}