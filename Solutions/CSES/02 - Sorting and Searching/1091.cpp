/*
============================================================================
 Name:		CSES Concert Tickets
 Link:		https://cses.fi/problemset/task/1091
 Author:	Dong Liu
 Date:		2021-02-13
============================================================================
*/

#include <iostream>
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
}