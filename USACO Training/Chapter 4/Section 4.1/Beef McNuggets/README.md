# Beef McNuggets
```cpp
  
/*
 ID: dongliu3
 TASK: nuggets
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
// global variables
int N;
int I[11];
bool dp[1000001];

// functions

int main() {
	// local variables

	// fstream
	ifstream fin("nuggets.in");
	ofstream fout("nuggets.out");

	// input
	fin >> N;
	for (int i=1; i<=N; i++)
		fin >> I[i];

	// main
	memset(dp, false, sizeof(dp));
	dp[0] = true;
	for (int i=0; i<=1000000; i++) if (dp[i])
		for (int j=1; j<=N; j++) dp[i+I[j]] = true;

	// output
	int ans = 0;
	for (int i=1000000; i>=1; i--) if (!dp[i]) {
    		if (i <= 65536) ans = i;
    		else ans = 0;
    		break;
	}
	fout << ans << endl;
	return 0;
}
```