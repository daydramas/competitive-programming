#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

struct P {
	int x, y;
} aa[N];

int n, ans = 0, cur = 0;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &aa[i].x, &aa[i].y);
	sort(aa, aa + n, [&](const P& i, const P& j) {
		return i.y < j.y;
	});
	for (int i = 0 ; i < n; ++i)
		if (aa[i].x >= cur)
			ans++, cur = aa[i].y;
	printf("%d\n", ans);
}