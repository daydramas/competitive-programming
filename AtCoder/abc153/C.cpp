#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	long long ans = 0, a[n];
	for (int i = 0; i < n; ++i)
		scanf("%lld", a + i);
	sort(a, a + n);
	for (int i = 0; i < n - k; ++i)	
		ans += a[i];
	printf("%lld\n", ans);
}