#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

struct P {
	long long x, y;
	long long d() {
		return x * x + y * y;
	}
};

int n; long long d;
P a;

int main() {
	scanf("%d%lld", &n, &d);
	d *= d;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%lld%lld", &a.x, &a.y);
		if (a.d() <= d)
			ans++;
	}
	printf("%d\n", ans);
}