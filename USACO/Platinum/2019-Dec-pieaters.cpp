#include <bits/stdc++.h>

using namespace std;

// defines
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define F0R1(i, a) for (int i=1; i<=(a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define F0Rd1(i, a) for (int i=a; i>0; i--)
#define SORT(a) sort(a.begin(), a.end())
#define trav(a,x) for (auto& a: x)

#define INT_INF 1000000000
#define LL_INF 4500000000000000000
#define pA first
#define pB second
#define mp make_pair
#define pb push_back
#define PI acos(-1.0)
#define MOD (int)(2e+9+11)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;

// structures

// global variables
int n, m;
int w[90005], l[90005], r[90005];
int mx[305][305][305];
int dp[305][305];

// functions
void M(int *a, int b) {
	*a = max(*a, b);
}
int main() {

	// local variables
	ios::sync_with_stdio(0);
	cin.tie(0);

	// input
	cin >> n >> m;
	for(int i=1; i<=m; i++) {
		cin >> w[i] >> l[i] >> r[i];
		for(int j=l[i]; j<=r[i]; j++) {
			M(&mx[j][l[i]][r[i]], w[i]);
		}
	}

	// main
	for (int i=1; i<=n; i++) {
		for (int j=i; j>=1; j--) {
			for (int k=i; k<=n; k++) {
				M(&mx[i][j-1][k], mx[i][j][k]);
				M(&mx[i][j][k+1], mx[i][j][k]);
			}
		}
	}
	for (int sz=1; sz<=n; sz++) {
		for (int i=1; (i+sz-1)<=n; i++) {
			int j=i+sz-1;
			for (int k=i; k<j; k++) {
				M(&dp[i][j], dp[i][k]+dp[k+1][j]);
			}
			for (int k=i; k<=j; k++) {
				M(&dp[i][j], mx[k][i][j]+dp[i][k-1]+dp[k+1][j]);
			}
		}
	}
	// output
	cout << dp[1][n] << endl;
	return 0;
}
