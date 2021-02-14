/**
 * CSES Tower of Hanoi
 * https://cses.fi/problemset/task/2165/
 */

#include <iostream>
using namespace std;

#define N (1 << 18) // 2e5

void hanoi(int n, int a, int b, int c) {
	if (n == 0)
		return;
	hanoi(n - 1, a, c, b);
	cout << a << ' ' << c << '\n';
	hanoi(n - 1, b, a, c);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	static int n;
	cin >> n;

	cout << (1 << n) - 1 << '\n';
	hanoi(n, 1, 2, 3);
}