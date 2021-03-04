/**
 * CSES Apple Division
 * https://cses.fi/problemset/task/1623
 */

#include <iostream>
using namespace std;

#define N 20

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	static int n, p[N];
	static long long ans, s1, s2;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	ans = 1e12;
	for (int j = 0; j < (1 << n); j++) {
		s1 = s2 = 0;
		for (int i = 0; i < n; i++) {
			if (j & (1 << i))
				s1 += p[i];
			else
				s2 += p[i];
		}
		ans = min(ans, abs(s1 - s2));
	}
	cout << ans << '\n';
}