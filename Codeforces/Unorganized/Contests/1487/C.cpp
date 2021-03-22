/*
 *
 * Created on 2021-02-14
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N (1 << 18) // 2e5

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> vv(n + 1, vector<int>(n + 1, 0));
		for (int i = 1; i < n; i++) {
			for (int j = 1; j <= n; j++) {
				int k = (j + i) % n;
				if (!k)
					k = n;
				vv[j][k] = 1, vv[k][j] = -1;
			}
		}
		if (n % 2 == 0) {
			for (int i = 1; i <= n; i++) {
				int j = (i + n / 2) % n;
				if (!j)
					j = n;
				vv[i][j] = vv[j][i] = 0;
			}
		}
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++) {
				cout << vv[i][j] << ' ';
			}
		cout << '\n';
	}
}