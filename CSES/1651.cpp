#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

long long bit[N];

long long query(int i) {
	long long ans = 0;
	while (i > 0) {
		ans += bit[i];
		i -= i & (-i);
	}
	return ans;
}

void update(int i, int x) {
	while (i < N) {
		bit[i] += x;
		i += i & (-i);
	}
}

int n, q, x[N];

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
		scanf("%d", x + i);
	
	for (int i = 0, t, a, b, c; i < q; ++i) {
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d%d%d", &a, &b, &c);
			update(a, c);
			update(b + 1, -c);
		} else {
			scanf("%d", &a);
			printf("%lld\n", x[a] + query(a));
		}
	}
}