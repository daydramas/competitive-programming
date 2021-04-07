#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	if (n == 1) {
		printf("1\n");
	} else if (n <= 3) {
		printf("NO SOLUTION\n");
	} else {
		for (int i = (n & 1 ? n : n - 1); i >= 1; i -= 2)
			printf("%d ", i);
		for (int i = (n & 1 ? n - 1 : n); i >= 2; i -= 2)
			printf("%d ", i);
		printf("\n");
	}
}