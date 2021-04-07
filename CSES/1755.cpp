#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;

int n, c[26];
char s[N];

int main() {
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; ++i)
		c[s[i] - 'A']++;
	int odds = 0;
	for (int i = 0; i < 26; ++i)
		if (c[i] & 1) odds++;
	if (odds > 1) {
		printf("NO SOLUTION\n");
	} else {
		for (int i = 0; i < 26; ++i)
			for (int j = 0; j < c[i] / 2; ++j)
				printf("%c", 'A' + i);
		for (int i = 0; i < 26; ++i)
			if (c[i] & 1)
				printf("%c", 'A' + i);
		for (int i = 25; i >= 0; --i)
			for (int j = 0; j < c[i] / 2; ++j)
				printf("%c", 'A' + i);
		printf("\n");
	}
}