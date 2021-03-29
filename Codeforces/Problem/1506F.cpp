#include <bits/stdc++.h>
using namespace std;

#define P pair<int, int>
#define r first
#define c second

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		P a[n];
		for (int i = 0; i < n; ++i)
			cin >> a[i].r;
		for (int i = 0; i < n; ++i)
			cin >> a[i].c;
		sort(a, a, + n);
	}
}