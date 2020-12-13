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
string s;
int dp[maxn][maxn];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> s;
    int n = s.length();
    if(n%2) { cout << "0"; return 0; }
    s = " " + s;
    FOR(i,1,n) FOR(j,1,n) dp[i][j]=0;
    // FOR(i,1,n-1) if(s[i]==s[i+1]) dp[i][i+1]=1;
    FOR(x,2,n) if(x%2==0) FOR(i,1,n) {
        int j=i+x-1; if(j>n) break;
        if(x==2) if(s[i]==s[j]) { dp[i][j]=1; continue; }
        if(s[i] == s[j]) dp[i][j] = (dp[i][j]+dp[i+1][j-1]+1) % mod;
        if(s[i] == s[i+1]) dp[i][j] = (dp[i][j]+dp[i+2][j]+1) % mod;
        if(s[j] == s[j-1]) dp[i][j] = (dp[i][j]+dp[i][j-2]+1) % mod;
        cout <<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<endl;
    }
    cout << dp[1][n] <<"\n";
}