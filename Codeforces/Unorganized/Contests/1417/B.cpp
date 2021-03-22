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

	static int t, n, T, a, x;
	cin >> t;
	while(t--) {
		cin >> n >> T;
		x = 0;
		for(int i=1; i<=n; i++) {
			cin >> a;
			if(T%2==0 && a*2==T) {
				cout << x; x = 1-x;
			} else if (a*2 > T) {
				cout << 0;
			} else {
				cout << 1;
			}
			cout << ' ';
		}
		cout << '\n';

	}
}