#include <bits/stdc++.h>
using namespace std;

int main() {
	long long h;
	scanf("%lld", &h);
	long long ans = 0, cnt = 1;
	while (h) {
		ans += cnt;
		cnt *= 2;
		h /= 2;
	}
	printf("%lld\n", ans);
}