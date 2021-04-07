#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	long long x, y;

	scanf("%d", &t);
	while (t--) {
		scanf("%lld%lld", &x, &y);
		if (x > y) {
			if (x & 1) printf("%lld\n", (x - 1) * (x - 1) + y);
			else printf("%lld\n", x * x - y + 1);
		} else {
			if (y & 1) printf("%lld\n", y * y - x + 1);
			else printf("%lld\n", (y - 1) * (y - 1) + x);
		}
	}
}