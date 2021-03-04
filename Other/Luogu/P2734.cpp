/**
 * A Game
 * Created on 2021-02-20
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N 105

int main() {
	cin.tie(0)->sync_with_stdio(0);

	static int n, a[N], sum;
	cin >> n;
	sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	static int dp[N][N];
	for (int i = 1; i <= n; ++i)
		dp[i][i] = a[i];
	for (int i = n - 1; i >= 1; --i)
		for (int j = i + 1; j <= n; ++j) {
			dp[i][j] = max(a[i] - dp[i + 1][j],
							a[j] - dp[i][j - 1]);
		}
	int one = (sum + dp[1][n]) / 2;
	int two = sum - one;
	cout << one << ' ' << two << '\n';
}