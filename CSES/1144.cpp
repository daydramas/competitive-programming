#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

// Order Statistic Tree (G++)

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class T> using Tree = tree<T, null_type, less<T>,
	rb_tree_tag, tree_order_statistics_node_update>;

Tree<pair<int, int>> tr;

int n, q, x[N];

int query(int a, int b) {
	return tr.order_of_key({b, N}) - tr.order_of_key({a - 1, N});
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", x + i);
		tr.insert({x[i], i});
	}
	scanf("\n");
	char t;
	for (int i = 0, a, b; i < q; ++i) {
		scanf("%c %d %d\n", &t, &a, &b);
		if (t == '!') {
			tr.erase({x[a], a});
			tr.insert({x[a] = b, a});
		} else {
			printf("%d\n", query(a, b));
		}
	}
}