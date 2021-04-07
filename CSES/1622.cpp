#include <bits/stdc++.h>
using namespace std;

int n, c[26], ki = 0;
char s[10], f[10];
char *k[40320];

void permute(int j) {
	if (j == n)
		k[ki++] = strdup(f);
	else {
		for (int i = 0; i < 26; ++i) {
			if (!c[i]) continue;
			f[j] = 'a' + i, c[i]--;
			permute(j + 1);
			f[j] = '\0', c[i]++;
		}
	} 
}

int main() {
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; ++i)
		c[s[i] - 'a']++;
	permute(0);
	printf("%d\n", ki);
	for (int i = 0; i < ki; ++i)
		printf("%s\n", k[i]);
}