#include <bits/stdc++.h>
using namespace std;

const int N = 500;

struct P {
	int i, j;
};

int n, dd[N];
P ii[N * N];
char s[5];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", dd + i);
	int c = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j) {
			if (dd[i] > dd[j]) ii[c++] = {i, j};
			else ii[c++] = {j, i};
		}
	sort(ii, ii + c, [](P a, P b) {
		return dd[a.i] - dd[a.j] > dd[b.i] - dd[b.j];
	});
	auto query = [](int x, int y) {
		printf("? %d %d\n", x, y);
		fflush(stdout);
		scanf("%s", s);
		return strcmp(s, "Yes") == 0;
	};
	auto answer = [](int x, int y) {
		printf("! %d %d\n", x, y);
		fflush(stdout);
		exit(0);
	};
	for (int i = 0; i < c; ++i)
		if (query(ii[i].i + 1, ii[i].j + 1))
			answer(ii[i].i + 1, ii[i].j + 1);
	answer(0, 0);
}