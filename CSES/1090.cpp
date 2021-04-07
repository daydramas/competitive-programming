#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, x, p[N], aa = 0;

int main() {
	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; ++i)
		scanf("%d", p + i);
	sort(p, p + n);
	int i = 0, j = n - 1;
	while (i <= j) {
		if (p[i] + p[j] <= x) i++, j--, aa++;
		else j--, aa++;
	}
	printf("%d\n", aa);
}