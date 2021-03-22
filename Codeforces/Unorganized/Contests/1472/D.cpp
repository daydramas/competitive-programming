/**
 * CF Even-Odd Game
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
		static int n, a[N];
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		bool t = 1;
		long long sum = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (t) {
				if (a[i] % 2 == 0)
					sum += a[i];
			} else {
				if (a[i] % 2 == 1)
					sum -= a[i];
			}
			t = !t;
		}
		if (sum > 0)
			cout << "Alice\n";
		else if (sum < 0)
			cout << "Bob\n";
		else
			cout << "Tie\n";
	}
}