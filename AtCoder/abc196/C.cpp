#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	scanf("%lld", &n);
	int ans = 0;
	for (int i = 1; i < n; ++i) {
		string s = to_string(i) + to_string(i);
		if (stoll(s) > n) break;
		ans++;
	}
	printf("%d\n", ans);
}