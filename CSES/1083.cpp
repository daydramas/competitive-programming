#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	long long s;
	
	scanf("%d", &n);
	s = 1LL * n * (n + 1) / 2;
	while (--n) {
		scanf("%d", &x);
		s -= x;
	}
	printf("%lld\n", s);
}