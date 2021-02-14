/*
============================================================================
Name:		Deque
Link:		https://atcoder.jp/contests/dp/tasks/dp_l
Author:	Dong Liu
Date:		2021-02-13
============================================================================
*/

#include <iostream>
using namespace std;
using ll = long long;

#define LL long long
#define N 3000

int main() {
	cin.tie(0)->sync_with_stdio(0);

	static int n;
	static LL a[N]; 
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	LL dp[n][n]{};
	for (int l = n - 1; l >= 0; --l)
		for (int r = l; r < n; ++r)
			if (l == r)
				dp[l][r] = a[l];
			else
				dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
	cout << dp[0][n - 1] << '\n';
}