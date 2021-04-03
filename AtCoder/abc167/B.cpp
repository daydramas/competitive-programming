#include <bits/stdc++.h>
using namespace std;

int a, b, c, k;

int main() {
	scanf("%d%d%d%d", &a, &b, &c, &k);
	int r = 0, x;
	x = min(k, a);
	k -= x, r += x;
	k -= min(k, b);
	x = min(k, c);
	k -= c, r -= x;
	printf("%d\n", r); 
}