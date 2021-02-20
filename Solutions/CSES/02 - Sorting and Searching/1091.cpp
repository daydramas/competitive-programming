/*
============================================================================
 Name:		CSES Concert Tickets
 Link:		https://cses.fi/problemset/task/1091
 Author:	Dong Liu
 Date:		2021-02-13
============================================================================
*/

#include <iostream>
#include <set>
using namespace std;

#define N (1 << 18) // 2e5

int main() {
	cin.tie(0)->sync_with_stdio(0);

	static int n, m, h[N], t[N];
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> h[i];
	for (int i = 0; i < m; ++i)
		cin >> t[i];
	multiset<int, greater<int>> s;
	for (int i = 0; i < n; ++i)
		s.insert(h[i]);
	for (int i = 0; i < m; ++i) {
		auto it = s.lower_bound(t[i]);
		if (it == s.end()) {
			cout << "-1" << '\n';
		} else {
			cout << *it << '\n';
			s.erase(it);
		}
	}
}