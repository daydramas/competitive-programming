#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

template<class T> using Tree = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>; 

const int N = 200010;

int n, k;
Tree<int> t;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		t.insert(i);
	int i = 0, j;
	for (int p = n; p >= 1; p--) {
		j = (i + k) % p;
		const auto &x = t.find_by_order(j);
		printf("%d ", (*x) + 1); t.erase(x);
		i = j;
	}
	printf("\n");

}