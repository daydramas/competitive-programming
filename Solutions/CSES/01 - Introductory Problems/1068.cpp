/**
 * CSES Weird Algorithm
 * https://cses.fi/problemset/task/1068
 */

#include <stdio.h>
using namespace std;

int main() {
	static long long n;
	scanf("%lld", &n);
	while (n != 1) {
		printf("%lld ", n);
		n = (n & 1 ? n * 3 + 1 : n >> 1);
	}
	printf("1\n");
}