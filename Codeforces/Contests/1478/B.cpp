/**
 * CF 1478B
 * https://codeforces.com/contest/1478/problem/B
*/

#include <iostream>
using namespace std;

#define N	(1<<18) // 2e5

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	static int t, n, d, a; 
	cin >> t;
	while(t--) {
		cin >> n >> d;
		for(int i=0; i<n; i++) {
			cin >> a;
			if(a % d == 0) {
				cout << "YES\n";
				continue;
			}
			if (a >= (a % d + d * 10)) {
				cout << "YES\n";
				continue;
			}
			bool ok = false;
			for (int i = 1; i <= 100; i ++) {
				int r = a - d * i;
				if (r >= 0 && r % 10 == 0) ok = true;
			}
			if (ok) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}