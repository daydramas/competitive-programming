#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> t;

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		const auto& it = upper_bound(t.begin(), t.end(), x);
		if (it == t.end())
			t.emplace_back(x);
		else
			*it = x;
	}
	printf("%d\n", (int) t.size());
}