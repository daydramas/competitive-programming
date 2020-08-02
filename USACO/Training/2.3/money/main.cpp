/*
 ID: dongliu3
 TASK: money
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
int V, N;
int C[25];
long long dp[10001];

// functions

int main() {
	// local variables

	// fstream
	ifstream fin("money.in");
	ofstream fout("money.out");

	// input
	fin >> V >> N;
	for (int i=0; i<V; i++) fin >> C[i];
	for (int i=0; i<=N; i++) dp[i] = 0;
	// main
	dp[0] = 1;
	for (int j=0; j<V; j++)
		for (int i=0; i<=N; i++)
			if (i+C[j] <= N) dp[i+C[j]] += dp[i];
	// output
	fout << dp[N] << endl;

	return 0;
}