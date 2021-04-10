/*
 ID: dongliu3
 TASK: game1
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
int N;
int B[202];
int dp[202][202];
int sum[202][202];

// functions

int main() {
	// local variables

	// fstream
	ifstream fin("game1.in");
	ofstream fout("game1.out");

	// input
	fin >> N;
	for (int i=1; i<=N; i++){
		fin >> B[i];
		dp[i][i] = sum[i][i] = B[i];
	}
	// main
	for (int i=1; i<=N; i++)
	for (int j=i+1; j<=N; j++)
		sum[i][j] = sum[i][j-1]+B[j];
	for (int sz=1; sz<N; sz++)
	for (int i=1; i+sz<=N; i++)
		dp[i][i+sz] = sum[i][i+sz]-min(dp[i][i+sz-1], dp[i+1][i+sz]);

	// output
	fout << dp[1][N] << " " << sum[1][N]-dp[1][N] << endl;
	return 0;
}