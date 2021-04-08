#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, x;

struct P {
	int i, x;
} ss[N];
int ii = 0;

int main() {
	scanf("%d", &n);
	ss[0] = {0, 0};
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &x);
		while (ii && ss[ii].x >= x)
			ii--;
		printf("%d ", ss[ii].i);
		ss[++ii] = {i, x};
	}
	printf("\n");
}