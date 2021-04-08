#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

struct P {
	int a, b;
} aa[N];

int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &aa[i].a, &aa[i].b);
	sort(aa, aa + n, [&](const P& i, const P& j) {
		if (i.a == j.a) return i.b < j.b;
		return i.a < j.a;
	});
	long long ans = 0, ti = 0;
	for (int i = 0; i < n; ++i)
		ans += aa[i].b - (ti += aa[i].a);
	printf("%lld\n", ans);
}