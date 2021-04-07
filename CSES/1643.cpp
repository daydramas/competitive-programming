#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;

int n, x;
long long ans = -inf, cur = 0;

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		cur = max((long long) x, cur + x);
		ans = max(ans, cur);
	}
	printf("%lld\n", ans);
}