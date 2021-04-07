#include <bits/stdc++.h>
using namespace std;

const int N = 20;
const long long INF = 1e18;

int n, p[N];
long long a, b, ans = INF;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", p + i);
	for (int i = 0; i < (1 << n); ++i) {
		a = b = 0;
		for (int j = 0; j < n; ++j)
			if (i & (1 << j)) a += p[j];
			else b += p[j];
		ans = min(ans, abs(a - b));
	}
	printf("%lld\n", ans);
}