#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, a, b;
	
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &a, &b);
		if ((a + b) % 3) printf("NO\n");
		else if (a > 2 * b) printf("NO\n");
		else if (b > 2 * a) printf("NO\n");
		else printf("YES\n");
	}
}