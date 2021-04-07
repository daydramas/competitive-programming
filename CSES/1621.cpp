#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, a[N], aa = 1;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	sort(a, a + n);
	for (int i = 1; i < n; ++i)
		if (a[i] != a[i - 1]) aa++;
	printf("%d\n", aa);
}