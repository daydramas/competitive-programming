#include <bits/stdc++.h>
using namespace std;

int n;

struct P {
	int i, j;
	P(int i, int j) : i(i), j(j) {}
	void next() {
		if (j + 2 >= n)
			++i;
		j = (j + 2) % n;
	}
	bool valid() {
		return i >= 0 && i < n && j >= 0 && j < n;
	}
} even(0, 0), odd(0, 1);

int main() {
	scanf("%d", &n);
	auto place = [&](P& x, int k) {
		printf("%d %d %d\n", k, x.i + 1, x.j + 1);
		fflush(stdout);
		x.next();
	};
	for (int t = 0, c; t < (n * n); ++t) {
		scanf("%d", &c);
		if (c == 1) {
			if (even.valid()) place(even, 2);
			else place(odd, 3);
		} else if (c == 2) {
			if (odd.valid()) place(odd, 1);
			else place(even, 3);
		} else {
			if (odd.valid()) place(odd, 1);
			else place(even, 2);
		}
	}
}