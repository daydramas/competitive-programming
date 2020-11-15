```cpp
/*
 ID: dongliu3
 TASK: nocows
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
#define MOD 9901

// global variables
int N, K;
int dp[201][101];

// functions

int main() {
	// local variables

	// fstream
	ifstream fin("nocows.in");
	ofstream fout("nocows.out");
 
	// input
	fin >> N >> K;

	// main
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=K; j++) {
			if (i==1) dp[i][j] = 1;
			else {
				for(int l=1; l <= i-2; l++)
					dp[i][j] = (dp[i][j] + dp[l][j-1] * dp[i-l-1][j-1]) % MOD;
			}
		}
	}
	// output
	fout << ((dp[N][K]-dp[N][K-1]+MOD) % MOD) << endl;

	return 0;
}
```