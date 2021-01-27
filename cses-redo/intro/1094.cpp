/**
 * CSES Increasing Array
 * https://cses.fi/problemset/task/1094
*/

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	static int n, x, y;
	static long long ans = 0;

	cin >> n >> x;
	for(int i=1; i<n; i++) {
		cin >> y;
		if(y < x) ans += x-y;
		else x = y;
	}
	cout << ans << '\n';
}