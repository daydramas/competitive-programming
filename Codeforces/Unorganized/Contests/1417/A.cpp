/**
 * problem-name
 * problem-link
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define N	(1<<18) // 2e5

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	static int t, n, k, a[N];
	cin >> t;
	while(t--) {
		cin >> n >> k;
		for(int i=1; i<=n; i++) {
			cin >> a[i];
		}
		sort(a+1, a+n+1);
		if(a[n] > k) {
			cout << "0\n";
		} else {
			int moves = 0;
			for(int i=2; i<=n; i++) {
				while(a[1] + a[i] <= k) {
					a[i] += a[1];
					moves++;
				}
			}
			while(a[1] + a[2] <= k) {
				a[1] += a[2];
				moves++;
			}
			cout << moves << '\n';
		}
	}
}