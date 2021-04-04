#include <bits/stdc++.h>
using namespace std;

char s[200010]{0};
int n; 
long long k, sum;

vector<int> c, m;

int main() {
	scanf("%s", s + 1);
	scanf("%lld", &k);
	n = strlen(s + 1);
	for (int i = 0; i < n; ++i)
		c.push_back(i);
	while (c.size()) {
		char f;
		for (f = 'a'; f <= 'z'; ++f) {
			sum = 0;
			for (int i : c) if (s[i + 1] == f)
				sum += n - i;
			if (sum < k)
				k -= sum;
			else break;
		}
		printf("%c", f);

		sum = 0; m.clear();
		for (int i : c) if (s[i + 1] == f) {
			sum++;
			if (i + 1 < n) m.push_back(i + 1);
		}
		if (sum >= k) {
			break;
		}
		k -= sum;
		c = m;
	}
	printf("\n");
}