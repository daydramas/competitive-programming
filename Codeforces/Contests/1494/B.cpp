#include <iostream>
using namespace std;

#define N	100000

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	while (t--) {
		int n, a[4];
		cin >> n;
		for (int i = 0; i < 4; ++i)
			cin >> a[i];
		bool ok = 0;
		for (int i = 0; i < 16; ++i) {
			int b[4];
			for (int j = 0; j < 4; ++j)
				b[j] = a[j];
			for (int j = 0; j < 4; ++j) {
				if (i & (1 << j)) {
					b[j]--; b[(j+1) % 4]--;
				}
			}
			bool ok2 = 1;
			for (int j = 0; j < 4; ++j)
				if (b[j] < 0 || b[j] > n - 2)
					ok2 = 0; 
			if (ok2) ok = 1;
		}

		cout << (ok ? "YES" : "NO") << '\n';

	}
}