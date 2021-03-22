/*
============================================================================
 Name:		CSES Digit Queries
 Link:		https://cses.fi/problemset/task/2431
 Author:	Dong Liu
 Date:		2021-02-04
============================================================================
*/

#include <iostream>
using namespace std;
using LL = long long;

int digit(LL n, int i) {
	if (i == 0)
		return n % 10;
	return digit(n / 10, i - 1);
}
int query(LL n) {
	LL l = 1, p = 1;
	while (n > p * 9 * l) {
		n -= p * 9 * l;
		l++, p *= 10;
	}
	return digit(p + (n - 1) / l, l - 1 - (n - 1) % l);
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int q;
	cin >> q;
	while (q--) {
		LL n;
		cin >> n;
		cout << query(n) << '\n';
	}
}