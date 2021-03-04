#include <iostream>
using namespace std;

#define N	100000

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		bool found = 0;
		for (int i = 0; i <= 1 && !found; ++i)
			for (int j = 0; j <= 1 && !found; ++j)
				for (int k = 0; k <= 1 && !found; ++k) {
					bool ok = 1;
					int del = 0;
					for (char c : s) {
						if (c == 'A') {
							if (i == 0) del++;
							else del--;
						} else if (c == 'B') {
							if (j == 0) del++;
							else del--;
						} else {
							if (k == 0) del++;
							else del--;
						}
						if (del < 0) ok = 0;
					}
					if (del == 0 && ok) {
						found = 1;
						// cout << i << j << k << '\n';
					}
				}
		cout << (found ? "YES" : "NO") << '\n';
	}
}