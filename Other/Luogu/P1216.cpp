/**
 * Number Triangles
 * Created on 2021-02-16
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N (1 << 18) // 2e5

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	int a[n + 1][n + 1]{};
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++) {
			cin >> a[i][j];
			a[i][j] += max(a[i - 1][j], a[i - 1][j - 1]);
		}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, a[n][i]);
	cout << ans << '\n';
}