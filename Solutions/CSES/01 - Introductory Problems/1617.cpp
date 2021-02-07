/**
 * CSES Bit Strings
 * https://cses.fi/problemset/task/1617
*/

#include <iostream>
using namespace std;

#define M	1000000007

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	static int n;
	static long long ans = 1;

	cin >> n;
	for(int i=1; i<=n; i++) {
		ans = (ans * 2) % M;
	}
	cout << ans << '\n';
}