#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

#define N	200005

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	while (t--) {
		int n, m;
		static int a[N], b[N];
		map<int, int> mp;

		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			++mp[a[i]];
		}
		for (int j = 0; j < m; ++j)
			cin >> b[j];
		int k = 0, l = 0;
		while (k < n && a[k] < 0)
			k++;
		while (l < m && b[l] < 0)
			l++;
		static int c[N];
		for (int i = 0; i < l; ++i) {
			c[i] = mp[b[i]];
			if (i) c[i] += c[i - 1];
			// cout << "c[" << i <<"] = " << c[i] << '\n';
		}
		for (int i = m - 1; i >= l; --i) {
			c[i] = mp[b[i]];
			if (i != m - 1) c[i] += c[i + 1];
			// cout << "c[" << i <<"] = " << c[i] << '\n';
		}
		// cout << "HERE" << endl;
		int jj = 0;
		int a1 = 0;
		for (int i = l; i < m; ++i) {
			while (jj + k < n && b[i] >= a[jj + k]) jj++;
			// int d = (jj + k + 1) - (lower_bound(b, b + m, b[jj + k] - jj) - b);
			int d = (i) - (lower_bound(b, b + m, b[i] - jj + 1) - b);
			a1 = max(a1, c[i + 1] + d + 1);
		}
		// cout << "OOPS" << endl;
		int a2 = 0; jj = 0;
		for (int i = l - 1; i >= 0; --i) {
			while (k - jj - 1 >= 0 && b[i] <= a[k - jj - 1]) {
				jj++;
				// cout << "JJ = " << jj << endl;
			}
			// int d = (upper_bound(b, b + m, b[k - jj - 1] + jj) - b) - (k - jj - 2);
			int d = (upper_bound(b, b + m, b[i] + jj) - b) - (i - 1);
			a2 = max(a2, (i ? c[i - 1] : 0) + d);
		}
		// cout << "OKAY" << endl;
		cout << a1 << " " << a2 << '\n';

	}
}