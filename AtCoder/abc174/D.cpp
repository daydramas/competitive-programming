#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n;
char s[N];

int R, W, r, w;

int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);

	for (int i = 1; i <= n; ++i)
		(s[i] == 'W' ? W++ : R++);

	int ans = 0x3f3f3f3f;
	for (int i = 0; i <= n; ++i) {
		if (i) (s[i] == 'W' ? w++ : r++);
		ans = min(ans, max(w, R - r));
	}
	printf("%d\n", ans);
}