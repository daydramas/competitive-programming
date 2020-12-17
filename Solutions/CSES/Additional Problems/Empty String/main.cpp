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

const int mod = 1e9+7;
const int maxn = 505;

int n; ll t;
string S;
int dp[maxn][maxn];
int BC[maxn][maxn]; // binomial coefficients

int main() {

    cin >> S; n=sz(S);

    F0R(i,n) {
        BC[i][0] = 1;
        FOR(j,1,i) BC[i][j] = (BC[i-1][j] + BC[i-1][j-1]) % mod;
    }
    F0R(i,n+1) dp[i][i]=1;
    for(int s=2; s<=n; s+=2) // size
    for(int i=0; i<=n-s; i++) // start
    for(int j=i+1; j<i+s; j+=2) {
        if (S[j] != S[i]) continue;
        t = 1LL * dp[i+1][j] * dp[j+1][i+s] % mod;
        t = 1LL * t * BC[s/2][(j-i+1)/2] % mod;
        dp[i][i+s] = (dp[i][i+s]+t) % mod;
    }
    cout << dp[0][n];
}