#include <bits/stdc++.h>

using namespace std;

// defines
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define f(i, a, b) for(ll i = a; i < b; i++)
#define rf(i, a, b) for(ll i = a; i >= b; i--)
#define w(a) while(a--)
#define arrin(a,n) f(i,0,n) { cin >> a[i]; }
#define arrout(a,n) f(i,0,n) { cout << a[i]<<" "; }
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll gcd(ll a,ll b){ return (b==0) ? a : gcd(b,a%b); }
ll lcm(ll a,ll b){ return (a * b) / gcd(a,b); }

// structures

// global variables
int n;
string s;
int dp[1005][1005];
int bal[1005];

// functions
int solve(int i, int Hbal) {
	if (i==n) return 1;
	if(dp[i][Hbal] >= 0) {
		return dp[i][Hbal];
	}
	int Gbal = bal[i]-Hbal;
	dp[i][Hbal] = 0;
	if (s[i]=='(') {
		dp[i][Hbal] += solve(i+1, Hbal); // G
		dp[i][Hbal] += solve(i+1, Hbal+1); // H
		dp[i][Hbal] %= 2012;
	} else {
		if (Hbal) dp[i][Hbal] += solve(i+1, Hbal-1); // H
		if (Gbal) dp[i][Hbal] += solve(i+1, Hbal); // G
		dp[i][Hbal] %= 2012;
	}
	return dp[i][Hbal];
}
int main() {

	// local variables

	// input
	fastio;
	cin >> s;
	n = s.length();
	// main
	f(i, 0, n) f(j, 0, n) {
		dp[i][j] = -1;
	}
	bal[0] = 0;
	f(i, 0, n) bal[i+1] = bal[i] + (s[i]=='('?1:-1);

	// output
	cout << solve(0, 0) << endl;
	return 0;
}
