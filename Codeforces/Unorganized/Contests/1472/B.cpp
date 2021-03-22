/**
 * CF Fair Division
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

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		if (sum & 1) {
			cout << "NO" << '\n';
		} else {
			sum /= 2;
			int dp[sum + 5];
			for (int i = 0; i <= sum; i++)
				dp[i] = 0;
			dp[0] = 1;
			for (int i = 0; i < n; i++)
				for (int j = sum; j >= a[i]; j--)
					dp[j] |= dp[j - a[i]];
			cout << (dp[sum] ? "YES" : "NO") << '\n';
		}
	}
}