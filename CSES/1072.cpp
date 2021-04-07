#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		printf("%lld\n", (1LL * (i - 1) * (i + 4) * (i * i - 3 * i + 4) / 2));
}