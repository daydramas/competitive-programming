#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, x, l;
long long ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x);
		ans += max(0, l - x);
		x += max(0, l - x);
		l = x;
	}
	printf("%lld\n", ans);
}