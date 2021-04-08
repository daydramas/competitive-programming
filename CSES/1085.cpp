#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, k, a[N];

bool check(long long x) {
	int groups = 1;
	long long cur = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] > x) return false;
		if (cur + a[i] <= x) cur += a[i];
		else cur = a[i], groups++;
	}
	return groups <= k;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	long long lower = 1, upper = (long long) 1e18, mid, ans = -1;
	while (lower <= upper) {
		mid = (lower + upper) / 2;
		if (check(mid)) ans = mid, upper = mid - 1;
		else lower = mid + 1;
	}
	printf("%lld\n", ans);
}