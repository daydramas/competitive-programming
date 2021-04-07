#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, m;
multiset<int, greater<int>> h;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0, x; i < n; ++i) { 
		scanf("%d", &x);
		h.insert(x);
	}
	for (int i = 0, x; i < m; ++i) {
		scanf("%d", &x);
		const auto &it = h.lower_bound(x);
		if (it == h.end())
			printf("-1\n");
		else {
			printf("%d\n", *it);
			h.erase(it);
		}
	}
}