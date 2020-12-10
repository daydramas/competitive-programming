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

using pii = pair<int,int>;
int n, x, w[20]; pii dp[1<<20];

int main() {

    cin >> n >> x;
    F0R(i,n) cin >> w[i];

    dp[0]={0,0};
    FOR(i,1,(1<<n)-1) dp[i] = {1e9,1e9};
    F0R(i,(1<<n)) F0R(j,n) { // i is bitmask, j is person adding
        if (i & (1<<j)) continue; // already used
        int s = dp[i].s + w[j];
        if (s <= x) dp[i+(1<<j)] = min(dp[i+(1<<j)], {dp[i].f, s});
        else dp[i+(1<<j)] = min(dp[i+(1<<j)], {dp[i].f+1, w[j]});
    } cout << dp[(1<<n)-1].f+1;
}