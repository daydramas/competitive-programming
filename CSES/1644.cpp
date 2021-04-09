#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<class T> using Tree = tree<T, null_type, less<T>,
	rb_tree_tag, tree_order_statistics_node_update>;

const int N = 200010;

int n, a, b;
long long x[N], ans = -1e18;

Tree<pair<long long, int>> t;

int main() {
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", x + i);
		x[i] += x[i - 1];
	}
	for (int i = a; i <= n; ++i) {
		t.insert({x[i - a], i - a});
		if (i > b) t.erase({x[i - b - 1], i - b - 1});
		ans = max(ans, x[i] - t.begin()->first);
	}
	printf("%lld\n", ans);
}