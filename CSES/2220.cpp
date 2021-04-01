#include <bits/stdc++.h>
using namespace std;
 
long long pp[20];
 
void init() {
	pp[0] = 1;
	for (int i = 1; i < 20; ++i)
		pp[i] = pp[i - 1] * 9;
}
 
long long query(long long x) {
	if (x < 0) return 0;
 
	int d[20] = {0}, n = 0;
	while (x) {
		d[n++] = x % 10;
		x /= 10;
	}
	long long c = 0;
	for (int i = 0; i < n - 1; ++i)
		c += pp[i];
	for (int i = n - 1; i >= 0; i--) {
		c += d[i] * pp[i];
		if (i != n - 1 && d[i + 1] > d[i]) c -= pp[i];
		if (i != n - 1 && d[i + 1] == d[i])
			return c; 
	}
	return c + 1;
}
 
int main() {
	init();
	long long a, b;
	scanf("%lld%lld", &a, &b);
	printf("%lld\n", query(b) - query(a - 1));
}