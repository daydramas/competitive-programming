/*
 *
 * Created on 2021-02-14
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N (1 << 18) // 2e5

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int k[n], c[m];
		for (int i = 0; i < n; i++)
			cin >> k[i];
		for (int i = 0; i < m; i++)
			cin >> c[i];
	}
}