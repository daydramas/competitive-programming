#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(), x.end()

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

// using pii = pair<int,int>;
const int maxn = 2e5+5;
const int m = 1e6;
const int k = 20;

int n,q,dp[k][m];

int main() {

    cin >> n >> q;

    F0R(i,m) dp[0][i] = m;
    F0R(i,n) {
		int a, b;
        cin >> a >> b; a--, b--;
		dp[0][a] = min(dp[0][a], b);
	}

    ROF(i,0,m-2) dp[0][i] = min(dp[0][i], dp[0][i + 1]);
    FOR(i,1,k-1) F0R(j,m) dp[i][j] = (dp[i - 1][j] < m ? dp[i - 1][dp[i - 1][j]] : m);

    F0R(i,q) {
		int a, b, ans=0;
		cin >> a >> b; a--, b--;
        R0F(j,k) if(dp[j][a]<=b){
            ans += (1 << j);
            a = dp[j][a];
		}
		cout << ans << "\n";
	}

}