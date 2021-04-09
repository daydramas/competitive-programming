#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<class T> using Tree = tree<T, null_type, less<T>,
	rb_tree_tag, tree_order_statistics_node_update>;

const int N = 200010;

int n, k, m;
int a[N];


Tree<pair<int, int>> t;

int main() {
	scanf("%d%d", &n, &k);
	m = (k - 1) / 2;
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (int i = 0; i < k; ++i)
		t.insert({a[i], i});
	printf("%d ", t.find_by_order(m)->first);
	for (int i = k; i < n; ++i) {
		t.erase({a[i - k], i - k});
		t.insert({a[i], i});
		printf("%d ", t.find_by_order(m)->first);
	}
	printf("\n");
}