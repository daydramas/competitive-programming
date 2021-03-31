#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>,
	rb_tree_tag, tree_order_statistics_node_update>;

const int N = 200010;

int n, ll[N], rr[N], ii[N], aa[N], bb[N];
Tree<pair<int, int>> t;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", ll + i, rr + i);
		ii[i] = i;
	}
	sort(ii, ii + n, [&](int i, int j) {
		if (ll[i] == ll[j]) return rr[i] < rr[j];
		return ll[i] > ll[j];
	});
	for (int i = 0; i < n; ++i) {
		aa[ii[i]] = t.order_of_key({rr[ii[i]], N});
		t.insert({rr[ii[i]], i});
	}
	t.clear();
	for (int i = n - 1; i >= 0; --i) {
		bb[ii[i]] = t.size() - t.order_of_key({rr[ii[i]], -1});
		t.insert({rr[ii[i]], i});
	}
	for (int i = 0; i < n; ++i)
		printf("%d ", aa[i]);
	printf("\n");
	for (int i = 0; i < n; ++i)
		printf("%d ", bb[i]);
	printf("\n");
}