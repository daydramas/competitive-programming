#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, int a, int b, int c) {
	if (n == 0) return;
	hanoi(n - 1, a, c, b);
	printf("%d %d\n", a, c);
	hanoi(n - 1, b, a, c);
}

int main() {
	int n;
	
	scanf("%d", &n);
	printf("%d\n", (1 << n) - 1);
	hanoi(n, 1, 2, 3);
}