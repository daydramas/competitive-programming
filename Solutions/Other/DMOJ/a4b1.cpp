/**
 * Sorting
 * https://dmoj.ca/problem/a4b1
 */

#include <algorithm>
#include <iostream>
using namespace std;

#define N (1 << 18) // 2e5

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	static int n, a[100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << '\n';
	}
}