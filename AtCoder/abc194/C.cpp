#include <bits/stdc++.h>
using namespace std;

const int N = 300010;
const int M = 400;

int n, a[N], c[M + 1];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);	
		c[a[i] + 200]++;
	}
	long long ans = 0;
	for (int i = 0; i <= M; ++i)
		for (int j = i + 1; j <= M; ++j) {
			long long _i = i - 200, _j = j - 200;
			ans += (_j - _i) * (_j - _i) * c[i] * c[j];
		}
	printf("%lld\n", ans);
}