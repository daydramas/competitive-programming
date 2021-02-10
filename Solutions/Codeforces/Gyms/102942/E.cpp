/*
============================================================================
 Name:		problem
 Link:		link
 Author:	Dong Liu
 Date:		2021-02-08
============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

#define F           first
#define S           second
#define PB          push_back
#define ALL(x)      begin(x), end(x)
#define SZ(x)       int((x).size())
#define FOR(i,a,b)  for(int i=(a); i<=(b); i++)
#define F0R(i,x)    FOR(i,0,(x)-1)
#define ROF(i,a,b)  for(int i=(b); i>=(a); i--)
#define R0F(i,x)    ROF(i,0,(x)-1)
#define REP(x)      F0R(_,x)
#define EACH(a,x)   for(auto& a: x)

const int mod = 1e9+7;

ll solve() {
	int n; string s;
	cin >> n >> s;
	s = " " + s;
	ll dp[n+1][10]{};
	dp[0][1] = 1;
	FOR(i,1,n) {
		FOR(d,1,9) {
			FOR(dd,1,d) dp[i][d] = (dp[i][d] + dp[i-1][dd] ) % mod;
		}
		if(s[i] != '-') FOR(d,1,9) if(d != (s[i]-'0')) dp[i][d] = 0; 
	}
	ll ans = 0;
	FOR(d,1,9) ans = (ans + dp[n][d]) % mod;
	return ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	REP(t) {
		cout << solve() << '\n';
	}

}