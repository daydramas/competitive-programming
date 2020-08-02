/*
 ID: dongliu3
 TASK: subset
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
int N;
long long dp[1700];

// functions

int main() {
	// local variables

	// fstream
	ifstream fin("subset.in");
	ofstream fout("subset.out");

	// input
	fin >> N;
	// main
	int temp = N*(N+1)/2;
	if (temp%2 != 0) {
		fout << "0" <<endl;
		return 0;
	}
	temp /= 2;
	fill(dp, dp+1700, 0);
	dp[0] = 1;
	cout << temp << endl;
	for (int i=1; i<=N; i++) {
		for (int j=1700; j>=0; j--) {
			if (i+j > 1700) continue;
			dp[j+i] += dp[j];
		}
	}
	// output
	fout << dp[temp] / 2 << endl;
	return 0;
}