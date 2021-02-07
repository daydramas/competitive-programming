#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;
const int maxm = 1e4;
const int mod = 1e9+7;
int n, x;
int t[maxn+5];
long long dp[maxn+5][maxm+5],
    DP[maxn+5][maxm+5];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> x;
    for(int i=0; i<n; i++) cin >> t[i];
    sort(t, t+n);
    dp[0][5000] = 1;
    for(int k=0; k<n; k++) {
        int x = t[k];
        for(int i=0; i<=maxn; i++)
        for(int j=0; j<=maxm; j++) if(dp[i][j]) {
            if(i+1 <= maxn && j-x>=0) DP[i+1][j-x] = ( DP[i+1][j-x] + dp[i][j] ) % mod;
            if(i && j+x<=maxm) DP[i-1][j+x] = (DP[i-1][j+x] + i*dp[i][j]) % mod;
            DP[i][j] = (DP[i][j] + (i+1)*(dp[i][j])) % mod;
        }
        for(int i=0; i<=maxn; i++) {
            swap(dp[i], DP[i]);
            for(int j=0; j<=maxm; j++) DP[i][j]=0;
        }
    }
    long long ans = 0;
    for(int i=5000; i<=5000+x; i++) ans = (ans+dp[0][i]) % mod;
    cout << ans;
}