// https://cp-algorithms.com/algebra/gray-code.html

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0, x; i < (1 << n); ++i) {
		x = i ^ (i >> 1);
		for (int j = 0; j < n; ++j)
			printf("%d", bool(x & (1 << j)));
		printf("\n");
	}
}