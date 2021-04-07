#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, p = 1;

	scanf("%d", &n);	
	while (n--)
		(p *= 2) %= 1000000007;
	printf("%d\n", p);
}