#include <bits/stdc++.h>
using namespace std;

int n, x, mx = 0;
long long sum = 0;

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		sum += x;
		if (x > mx) mx = x;
	}
	printf("%lld\n", max(sum, 2LL * mx));
}