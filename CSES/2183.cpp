#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, a[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	sort(a, a + n);
	if (a[0] != 1)
		printf("1\n");
	else {
		long long pp = 1;
		for (int i = 1; i < n; ++i)
			if (pp + 1 < a[i])
				printf("%lld\n", pp + 1), exit(0);
			else
				pp += a[i];
		printf("%lld\n", pp + 1);
	}
}