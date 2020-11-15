```cpp
/*
 ID: dongliu3
 TASK: humble
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
#define INF 1000000000000
#define ui unsigned long long

// global variables
ui K, N;
int prime[100];
vector<ui> ans, start;
int csize = 1, clast = 1;

// functions

int main() {
	// local variables
	ans.push_back(1);

	// fstream
	ifstream fin("humble.in");
	ofstream fout("humble.out");

	// input
	fin >> K >> N;
	for (int i = 0; i < K; i++) {
		fin >> prime[i];
		start.push_back(0);
	}
	for (int i = 0; i <= N; i++)
		ans.push_back(0);
	// main
	for (; csize <= N; csize++) {
		ui min = INF;

		for (int i = 0; i < K; ++i) {
			for (int j = start[i]; j < csize; ++j) {
				int next = ans[j] * prime[i];
				if (next <= clast) {
					continue;
				}
				if (next < min) {
					min = next;
				}
				start[i] = j;
				break;
			}
		}

		ans[csize] = min;
		clast = min;
	}

	// output
	fout << ans[N] << endl;
	return 0;
}
```