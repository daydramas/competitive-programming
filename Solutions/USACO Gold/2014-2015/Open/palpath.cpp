/*
 ID: dongliu3
 TASK: change
 LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

// structures/defines

// global variables
int N;
string path[501];
long long dp[501][501];
int finalSz;
bool check(string s) {
	for (int i = 0; i < (finalSz / 2); i++) {
		if (s[i] != s[finalSz - (i + 1)]) {
			return false;
		}
	}
	return true;
}
long long dfs(int i, int j, string s) {
	s += path[i][j];
	int sz = s.size();
	if (dp[i][j]!=-1) return dp[i][j];
	if (sz - 1 >= finalSz / 2) {
		if (s[sz - 1] != s[finalSz - (sz)]) {
//			cout << s << endl;
			dp[i][j]=0;
//			return 0;
		}
	}
	//	cout << i << " " << j << " = " << s << endl;
	long long count = 0;
//	if (dp[i][j]) {
//		return dp[i][j];
//	}
	if (i == N and j == N) {
		count += check(s);
		if (check(s)) {
			cout << s << endl;
		}
	}
	if (i + 1 <= N) {
		count += dfs(i + 1, j, s);
	}
	if (j + 1 <= N) {
		count += dfs(i, j + 1, s);
	}
	dp[i][j] = count % 1000000007;
	return count % 1000000007;
}
//functions

int main() {
	// local variables

	// fstream
	ifstream fin("palpath.in");
	ofstream fout("palpath.out");

	// input
	cin >> N;
	finalSz = N + N - 1;
	for (int i = 1; i <= N; i++) {
		cin >> path[i];
		path[i] = " " + path[i];
	}
	// main
	cout << dfs(1, 1, "")<<endl;
//	cout << check("ABEDCBA");
	// output

	return 0;
}
