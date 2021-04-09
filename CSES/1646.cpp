#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, q;

long long x[N];

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", x + i);
		x[i] += x[i - 1];
	}	
	for (int i = 0, a, b; i < q; ++i) {
		scanf("%d%d", &a, &b);
		printf("%lld\n", x[b] - x[a - 1]);
	}
}