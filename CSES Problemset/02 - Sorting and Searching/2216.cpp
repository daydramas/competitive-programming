/**
 * CSES Collecting Numbers
 * https://cses.fi/problemset/task/2216
 * Created on 2021-03-14
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N (1 << 18) // 2e5

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, x;
	static int a[N];

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x; a[x] = i;
	}
	
	int m = 1;
	for (int i = 1; i < n; ++i)
		if (a[i + 1] < a[i])
			++m;
	cout << m << '\n';
}