/*
============================================================================
 Name:		Vacation
 Link:		https://atcoder.jp/contests/dp/tasks/dp_c
 Author:	Dong Liu
 Date:		2021-02-04
============================================================================
 * dp[i][a] = maximum happiness ending with using a
 * dp[i][b] = maximum happiness ending with using b
 * dp[i][c] = maximum happiness ending with using c
 * base case: dp[0][a] = dp[0][b] = dp[0][c] = 0
 * transitions:
 	* dp[i+1][a] = a[i+1] + max(dp[i][b], dp[i][c])
 	* dp[i+1][b] = b[i+1] + max(dp[i][a], dp[i][c])
	* dp[i+1][c] = c[i+1] + max(dp[i][a], dp[i][b])
 * answer: max(dp[n][a], dp[n][b], dp[n][c])
============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using VI = vector<int>;
using PI = pair<int, int>;

#define F			first
#define S			second
#define PB			push_back
#define ALL(x)		begin(x), end(x)
#define SZ(x)		int((x).size())
#define F0R(i,a)	for(int i=0; i<(a); i++)
#define FOR(i,a,b)	for(int i=(a); i<=(b); i++)
#define R0F(i,a)	for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b)	for(int i=(b); i>=(a); i--)
#define EACH(a,x)	for (auto& a: x)


int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n; cin >> n;
	int A, B, C, a, b, c;
	cin >> A >> B >> C;
	F0R(i,n-1) {
		cin >> a >> b >> c;
		int X = a + max(B, C);
		int Y = b + max(A, C);
		int Z = c + max(A, B);
		A = X, B = Y, C = Z;
	}
	cout << max({A, B, C}) << '\n';

}