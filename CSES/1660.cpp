#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, x, a[N];

int main() {
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	int ans = 0, cur = 0, j = 1;
	for (int i = 1; i <= n; ++i) {
		while (j <= n && cur < x) cur += a[j++];
		if (cur == x) ans++; cur -= a[i];
	}
	printf("%d\n", ans);
}