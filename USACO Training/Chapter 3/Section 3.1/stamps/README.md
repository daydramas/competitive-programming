```cpp
/*
 ID: dongliu3
 TASK: stamps
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
#define MAX 2000005

// global variables
int N, K, S[55], dp[MAX];
int cnt = 0;

// functions

int main() {
	// local variables

	// fstream
	ifstream fin("stamps.in");
	ofstream fout("stamps.out");

	// input
	fin >> K >> N;
	for (int i = 1; i <= N; i++)
		fin >> S[i];
	fill(dp + 1, dp + (K * 10000) + 1, 1000000000);
	// main
	dp[0] = 0;
	for (int i = 0; i <= (K * 10000); i++) {
		if (dp[i] > K) {
			cnt = i - 1;
			break;
		}
		for (int j = 1; j <= N; j++)
			if (i + S[j] <= (K * 10000)) {
				dp[i + S[j]] = min(dp[i + S[j]], dp[i] + 1);
			}
	}
	// output
	fout << cnt << endl;
	return 0;
}
```