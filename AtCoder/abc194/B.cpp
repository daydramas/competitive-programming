#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, a[N], b[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", a + i, b + i);
	int ans = 1e9;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
				if (i == j)
					ans = min(ans, a[i] + b[j]);
				else
					ans = min(ans, max(a[i], b[j]));
	printf("%d\n", ans);
}