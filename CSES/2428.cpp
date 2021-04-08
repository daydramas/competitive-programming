#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

struct D {
	int x, i;
} dd[N];

int n, k, a[N], oo[N];

int main() {
	scanf("%d%d", &n, &k);
	dd[0] = {0, 0};
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i), dd[i] = {a[i], i};
	sort(dd + 1, dd + n + 1, [&](const D& i, const D& j) {
		return i.x < j.x;
	});
	for (int i = 1; i <= n; ++i)
		if (dd[i].x == dd[i - 1].x)
			a[dd[i].i] = a[dd[i - 1].i];
		else
			a[dd[i].i] = a[dd[i - 1].i] + 1;
	long long ans = 0;
	for (int i = 1, j = 1, l = 0; i <= n; ++i) {
		while (j <= n && (l < k || oo[a[j]])) {
			if (!oo[a[j]]) l++;
			oo[a[j++]]++;
		}
		ans += j - i;
		if (oo[a[i]] == 1) l--;
		oo[a[i]]--;
	}
	printf("%lld\n", ans);
}