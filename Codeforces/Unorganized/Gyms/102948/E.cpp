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


int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n; cin >> n;
	int a[n][n]{};
	F0R(i,n) F0R(j,n) cin >> a[i][j];
	int p[n]{};
	F0R(i,n) p[i]=i;
	int ans = 0;
	do {
		int sum = 0;
		F0R(i,n) sum += a[i][p[i]];
		ans = max(ans, sum);
	} while(next_permutation(p,p+n));
	cout << ans << '\n';

}