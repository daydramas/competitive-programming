#include <bits/stdc++.h>
using namespace std;

const int N = 25;

int n, a[N];
long long ans = 1e18;

void f(int i, long long x) {
	if (i == n) {
		ans = min(ans, x);
		return;
	}
	for (int j = i + 1, o = 0; j <= n; ++j)
		f(j, x ^ (o |= a[j]));
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	f(0, 0);
	printf("%d\n", ans);
}