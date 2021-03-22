/**
 * Odd Divisor
 * https://codeforces.com/contest/1475/problem/A
*/

#include <iostream>
using namespace std;

#define N	(1<<18) // 2e5

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	static int t;
	static long long n;
	cin >> t;
	while(t--) {
		cin >> n;
		while(n%2 == 0) n /= 2;
		cout << (n > 1 ? "YES" : "NO") << '\n';
	}
}