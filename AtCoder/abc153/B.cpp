#include <bits/stdc++.h>
using namespace std;

int main() {
	int h, n, a[100000];
	scanf("%d%d", &h, &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		h -= a[i];
	}
	puts(h > 0 ? "No" : "Yes");
}