/*
 ID: dongliu3
 TASK: change
 LANG: C++
 */

#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

// structures/defines
// global variables
int N;
int mylogger[101];
int dp[101][101][101];

//functions
int main() {
	// local variables
//	cout << "hi" << endl;
	// fstream
	ifstream fin("taming.in");
	ofstream fout("taming.out");
//	fout << "hi" << endl;
	// input
//	cout << "hi" << endl;
	fin >> N;
	for (int i = 0; i < N; i++) {
		fin >> mylogger[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k <= N; k++) {
				dp[i][j][k] = 1000000000;
			}
		}
	}
//	cout << "hi" << endl;
	// main
	dp[0][0][1] = !(mylogger[0] == 0);
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			for (int k = 1; k <= i + 1; k++) {
//				if (k > i || j > i || j > k)
//					continue;
				if (j < i)
					dp[i][j][k] = dp[i - 1][j][k];
				else
					for (int j1 = 0; j1 < i; j1++)
						dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j1][k - 1]);
				if (mylogger[i] != i - j)
					dp[i][j][k]++;
//				cout << "dp[" << i << "][" << j << "][" << k << "] = "
//						<< dp[i][j][k] << endl;
			}
		}
	}
//	cout << "hi" << endl;
	// output
	for (int a = 1; a <= N; a++) {
		int ans = 1000000000;
		for (int i = 0; i < N; i++) {
			ans = min(ans, dp[N - 1][i][a]);
		}
		cout << ans << endl;
		fout << ans << endl;
	}
	return 0;
}
