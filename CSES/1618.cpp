#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, ans = 0;
	
	scanf("%d", &n);
	while (n) {
		n /= 5;
		ans += n;
	}
	printf("%d\n", ans);
}