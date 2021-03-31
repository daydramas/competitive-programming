#include <bits/stdc++.h>
using namespace std;

const int N = 10000;

int n, k;
int d[10];
int x; bool okay;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; ++i) {
		scanf("%d", &x); d[x] = 1;
	}
	
	while (1) {
		x = n, okay = 1;
		while (x) {
			if (d[x % 10])
				okay = false;
			x /= 10;
		}
		if (okay) break;
		n++;
	}
	printf("%d\n", n);
}