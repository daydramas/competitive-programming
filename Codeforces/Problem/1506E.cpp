#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class T> using Tree = tree<T, null_type, less<T>,
	rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		static int a[200005];
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		Tree<int> t;
		auto clear = [&]() -> void {
			t.clear();
			for (int i = 1; i <= n; ++i)
				t.insert(i);
		};
		auto add = [&](int x) -> void {
			t.erase(x);
			cout << x << ' ';
		};
		clear(); add(a[1]);
		for (int i = 2; i <= n; ++i) {
			if (a[i] != a[i - 1]) {
				add(a[i]);
			} else {
				int x = *t.begin();
				add(x);
			}
		}
		cout << '\n';

		clear(); add(a[1]);
		int x = a[1];
		for (int i = 2; i <= n; ++i) {
			if (a[i] != a[i - 1]) {
				add(a[i]);
				x = a[i];
			} else {
				auto it = t.lower_bound(x); --it;
				add(*it);
			}
		}
		cout << '\n';
	}
}