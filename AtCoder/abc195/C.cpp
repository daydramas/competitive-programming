#include <bits/stdc++.h>
using namespace std;

long long n;

int main() {
	scanf("%lld", &n);
	long long ans = 0;
	if (n >= 1000LL) ans += n - 999LL;
	if (n >= 1000000LL) ans += n - 999999LL;
	if (n >= 1000000000LL) ans += n - 999999999LL;
	if (n >= 1000000000000LL) ans += n - 999999999999LL;
	if (n >= 1000000000000000LL) ans += n - 999999999999999LL;
	printf("%lld\n", ans);
}