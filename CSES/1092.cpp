#include <bits/stdc++.h>
using namespace std;

bool f[1000010];

int main() {
	int n;
	scanf("%d", &n);

	long long t = 1LL * n * (n + 1) / 2;
	if (t & 1) {
		printf("NO\n");
	} else {
		printf("YES\n");
		t /= 2;
		int m = 0;
		for (int i = n; i >= 1; --i)
			if (t >= i) m++, f[i] = 1, t -= i;
		printf("%d\n", m);
		for (int i = 1; i <= n; ++i)
			if (f[i]) printf("%d ", i);
		printf("\n%d\n", n - m);
		for (int i = 1; i <= n; ++i)
			if (!f[i]) printf("%d ", i);
		printf("\n");
	}
}