#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

struct E {
	int x, i, t;
} aa[N * 2];

int n, col = 0, ans[N];

int main() {
	scanf("%d", &n);
	for (int i = 0, l, r; i < n; ++i) {
		scanf("%d%d", &l, &r);
		aa[i * 2] = {l, i, 0};
		aa[i * 2 + 1] = {r, i, 1}; 
	}
	sort(aa, aa + n * 2, [&](const E& i, const E& j) {
		if (i.x == j.x) return i.t < j.t;
		return i.x < j.x;
	});
	queue<int> q;
	for (int i = 0; i < n * 2; ++i) {
		if (aa[i].t == 1) q.push(aa[i].i);
		else if (q.empty()) ans[aa[i].i] = ++col;
		else ans[aa[i].i] = ans[q.front()], q.pop();
	}
	printf("%d\n", col);
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]);
	printf("\n");
}