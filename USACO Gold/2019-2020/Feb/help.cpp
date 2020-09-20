/*
 ID: dongliu3
 TASK: help
 LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

// structures/defines
#define MOD (int)(1e9+7)
// global variables
int N;
int interval[200001];
int power2[100001];
//functions
int main() {
	// local variables

	// fstream
	ifstream fin("help.in");
	ofstream fout("help.out");
	// input
	fin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		fin >> a >> b;
		interval[a] = -1;
		interval[b] = 1;
	}
	power2[0] = 1;
	for (int i = 1; i <= N; i++) {
		power2[i] = (power2[i - 1] * 2) % MOD;
	}
	// main
	int count = N;
	int ans = 0;
	for (int i = 1; i <= 2 * N; i++) {
		count += interval[i];
		if (interval[i] == -1) {
			ans = (ans + power2[count]) % MOD;
		}
	}

// output
	cout << ans << endl;
	return 0;
}
