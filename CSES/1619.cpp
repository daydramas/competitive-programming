#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

struct P {
	int x, t;
} aa[N * 2];

int n;

int main() {
	scanf("%d", &n);
	for (int i = 0, x, y; i < n; ++i) {
		scanf("%d%d", &x, &y);
		aa[i * 2] = {x, 1};
		aa[i * 2 + 1] = {y, -1};
	} 
	sort(aa, aa + n * 2, [&](const P& i, const P& j) {
		return i.x < j.x;
	});
	int ans = 0, cur = 0;
	for (int i = 0; i < n * 2; ++i) {
		cur += aa[i].t;
		ans = max(ans, cur);
	}
	printf("%d\n", ans);
}