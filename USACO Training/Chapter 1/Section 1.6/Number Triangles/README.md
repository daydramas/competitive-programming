```cpp
  
/*
 ID: dongliu3
 TASK: numtri
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
int N;
int val[1005][1005], dp[1005][1005];
// functions

int main() {
	// local variables

	// fstream
	ifstream fin("numtri.in");
	ofstream fout("numtri.out");

	// input
	fin >> N;
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=i; j++) {
			fin >> val[i][j];
			dp[i][j] = 0;
		}
	}
	// main
	dp[1][1] = val[1][1];
	int cnt = 0;
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=i; j++) {
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]+val[i+1][j]);
			dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+val[i+1][j+1]);
			if (i == N) {
				cnt = max(cnt, dp[i][j]);
			}
//			cout << "dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<endl;
		}
	}
	// output
	fout << cnt << endl;
	return 0;
}
```