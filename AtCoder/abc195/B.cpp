#include <bits/stdc++.h>
using namespace std;

int aa, bb;

int main() {
	int a, b, w;
	scanf("%d%d%d", &a, &b, &w); w *= 1000;
	aa = 1e9, bb = 0;
	for (int n = 1; n <= 1000000; ++n) {
		if (a * n <= w && w <= b * n)
			aa = min(aa, n), bb = max(bb, n);
	}
	if (!bb) puts("UNSATISFIABLE");
	else printf("%d %d\n", aa, bb);
}