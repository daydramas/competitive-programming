#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	double ans = 0;
	for (int i = 1; i < n; ++i) {
		ans = ans + (1.0 * n / i);
	}
	printf("%.12f\n", ans);
}