#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, a[N], x;
long long ans = 0;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	sort(a, a + n); x = a[n / 2];
	for (int i = 0; i < n; ++i)
		ans += abs(a[i] - x);
	printf("%lld\n", ans);

}