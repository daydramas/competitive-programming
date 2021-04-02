#include <bits/stdc++.h>
using namespace std;

char s[200];

int main() {
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i < n; ++i)
		if (s[i] == '.')
			break;
		else
			printf("%c", s[i]);
	printf("\n");
}