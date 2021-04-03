#include <bits/stdc++.h>
using namespace std;

char s[15], t[15];

int main() {
	scanf("%s", s);
	scanf("%s", t);
	int n = strlen(s);
	bool ok = 1;
	for (int i = 0; i < n; ++i)
		if (s[i] != t[i]) ok = 0;
	puts(ok ? "Yes" : "No");
}