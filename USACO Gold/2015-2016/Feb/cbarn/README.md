# cbarn
```cpp
/*
 ID: dongliu3
 TASK: change
 LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

// structures/defines

// global variables
int N, c[100000];
int step[100000];
//functions
int getDist(int i, int j) {
	if (j > i)
		return j - i;
	else
		return N - i + j;
}
int main() {
	// local variables
	queue<int> Q;

	// fstream
	ifstream fin("cbarn.in");
	ofstream fout("cbarn.out");

	// input
	fin >> N;
	for (int i = 0; i < N; i++) {
		fin >> c[i];
		step[i] = 0;
	}
	for (int i = N - 1; i >= 0; i--) {
		if (c[i] == 0) {
			Q.push(i);
		}
	}
	// main
	long long ans = 0;
	while (!Q.empty()) {
		int t = Q.front();
		Q.pop();
		for (int i = (t - 1 + N) % N; i != t; i = (i - 1 + N) % N) {
			if (c[i]) {
				c[i]--, c[t]++;
				step[t] = step[i] + getDist(i, t);
				ans += step[t] * step[t] - step[i] * step[i];
				if (c[i] == 0) {
					Q.push(i);
				}
				break;
			}
		}
	}

	// output
	fout << ans << endl;
	return 0;
}

```