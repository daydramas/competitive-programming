/**
 * CSES Missing Number
 * https://cses.fi/problemset/task/1083
*/

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	static int n, x; 
	static long long sum;

	cin >> n;
	sum = 1LL * n * (n + 1) / 2; 
	while(--n) {
		cin >> x;
		sum -= x;
	}
	cout << sum << '\n';
}