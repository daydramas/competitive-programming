#include <bits/stdc++.h>
using namespace std;

const int n = 8;
int ans = 0;
char s[n + 2][n + 2];
bool c[n + 2], d1[n * 2], d2[n * 2];

void place(int r) {
	if (r == 8)
		ans++;
	else {
		for (int i = 0; i < 8; ++i)
			if (s[r][i] == '.' && !c[i] && !d1[r + i] && !d2[r - i + 7]) {
				c[i] = d1[r + i] = d2[r - i + 7] = 1;
				place(r + 1);
				c[i] = d1[r + i] = d2[r - i + 7] = 0;
			}
	}
}

int main() {
	for (int i = 0; i < n; ++i)
		scanf("%s", s[i]);
	place(0);
	printf("%d\n", ans);
}