#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, t, k[N];

bool check(long long x) {
	long long f = 0;
	for (int i = 1; i <= n; ++i) {
		f += x / k[i];
		if (f >= t) return true;
	}
	return f >= t;
}

int main() {
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; ++i)
		scanf("%d", k + i);
	
	long long lower = 0, upper = (long long) 1e18, mid, ans = -1;
	while (lower <= upper) {
		mid = (lower + upper) / 2;
		if (check(mid)) ans = mid, upper = mid - 1;
		else lower = mid + 1;
	}
	printf("%lld\n", ans);
}