#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

struct P {
	int x, i;
} aa[N];

int n, x;

int main() {
	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; ++i)
		scanf("%d", &aa[i].x), aa[i].i = i + 1;
	sort(aa, aa + n, [&](const P& i, const P& j) {
		return i.x < j.x;
	});
	int i = 0, j = n - 1;
	while (i < j) {
		if (aa[i].x + aa[j].x == x)
			printf("%d %d\n", aa[i].i, aa[j].i), exit(0);
		else if (aa[i].x + aa[j].x < x)
			i++;
		else
			j--;
	}
	printf("IMPOSSIBLE\n");

}