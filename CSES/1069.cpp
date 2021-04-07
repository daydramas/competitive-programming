#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;

int n, ans = 1, cur = 1;
char s[N];

int main() {
	scanf("%s", s);
	n = strlen(s);
	for (int i = 1; i < n; ++i)
		if (s[i] == s[i - 1])	
			ans = max(ans, ++cur);
		else
			cur = 1;
	printf("%d\n", ans);
}