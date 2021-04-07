#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, m, k, a[N], b[N];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (int j = 0 ; j < m; ++j)
		scanf("%d", b + j);
	sort(a, a + n); sort(b, b + m);
	int i = 0, j = 0, aa = 0;
	while (i < n && j < m) {
		if (abs(a[i] - b[j]) <= k) i++, j++, aa++;
		else if (a[i] < b[j]) i++;
		else j++;
	}
	printf("%d\n", aa);
}