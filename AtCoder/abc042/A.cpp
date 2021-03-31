#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[3];
	scanf("%d%d%d", a, a + 1, a + 2);
	sort(a, a + 3);
	bool ok = a[0] == 5 && a[1] == 5 && a[2] == 7;
	printf("%s\n", ok ? "YES" : "NO");
}