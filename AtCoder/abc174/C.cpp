#include <bits/stdc++.h>
using namespace std;

int main() {
	long long k, p = 7;
	scanf("%lld", &k);
	for (int i = 1; i <= k; ++i) {
		if (p % k == 0) {
			return printf("%d\n", i), 0;
		}
		p = (p * 10 + 7) % k;
	}
	printf("-1\n");

}