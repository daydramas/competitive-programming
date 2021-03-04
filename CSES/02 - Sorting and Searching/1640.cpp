/**
 * CSES Sum of Two Values
 * https://cses.fi/problemset/task/1640
 * Created on 2021-02-17
 */

#include <iostream>
#include <map>
using namespace std;

#define N (1 << 18) // 2e5

int main() {
	cin.tie(0)->sync_with_stdio(0);

	static int n, x, a;
	map<int, int> m;
	cin >> n >> x;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		if (m[x - a]) {
			cout << m[x - a] << ' ' << i << '\n';
			return 0;
		}
		m[a] = i;
	}
	cout << "IMPOSSIBLE" << '\n';
	
}