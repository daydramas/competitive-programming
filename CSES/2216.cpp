#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, a[N], ans = 1;

int main() {
	scanf("%d", &n);
	for (int i = 0, x; i < n; ++i)
		scanf("%d", &x), a[x] = i;
	for (int i = 1; i < n; ++i)
		if (a[i + 1] < a[i])
			ans++;
	printf("%d\n", ans);
}