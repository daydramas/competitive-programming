#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int,int>;
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

void setIO(string s = "") {
	cin.tie(0)->sync_with_stdio(0); if (s.size()) {
		freopen((s+".in").c_str(), "r", stdin);
		freopen((s+".out").c_str(), "w", stdout); }
}

const int maxn = 1e5+5;
const int maxm = 30;

int n, m, k, c[maxm][maxm], ans;
string o;
int ps[maxn][maxm], dp[maxn][maxm], mn[maxn];

int main() {
	setIO("cowmbat");

	cin >> n >> m >> k >> o;
	F0R(i,m) F0R(j,m) cin >> c[i][j];
	F0R(k,m) F0R(i,m) F0R(j,m) c[i][j] = min(c[i][j], c[i][k]+c[k][j]);
	FOR(i,1,n) F0R(j,m) ps[i][j] = ps[i-1][j] + c[o[i-1]-'a'][j]; 
	F0R(i,n+1) F0R(j,m) dp[i][j] = i?1e9:0;
	FOR(i,k,n) F0R(j,m) {
		dp[i][j] = min(dp[i][j], dp[i-1][j] + c[o[i-1]-'a'][j]);
		if(i >= k) F0R(c,m) dp[i][j] = min(dp[i][j], dp[i-k][c] + ps[i][j] - ps[i-k][j]);
	} ans = 1e9;
	F0R(j,m) ans = min(ans, dp[n][j]);
	cout << ans << '\n';
}