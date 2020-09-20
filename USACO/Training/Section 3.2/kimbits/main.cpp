  
/*
 ID: dongliu3
 TASK: kimbits
 LANG: C++
 */

#include <bits/stdc++.h>
#include <cstdint>

using namespace std;

// structures/defines
#define ll unsigned long long int
#define MN 40

// global variables
int N, L; ll I;
ll C[MN], C2[MN];
ll c[MN][MN];
ll F[MN][MN];

// functions
ll choose(int n, int k) {
	if (F[n][k] != -1) return F[n][k];
	return (F[n][k] = choose(n-1, k-1)+choose(n-1, k));
}

int main() {
	// local variables

	// fstream
	ifstream fin("kimbits.in");
	ofstream fout("kimbits.out");

	// input
	fin >> N >> L >> I;

	// main
	for (int i=0; i<=N; i++)
	for (int j=0; j<=N; j++)
		F[i][j] = -1;
	for (int i=0; i<=N; i++) F[i][0] = F[i][i] = 1;
	for (int i=1; i<=L; i++) c[0][i] = 1;
	for (int i=1; i<=N; i++) c[i][0] = 0;

	for (int l=1; l<=L; l++) {
		for (int i=1; i<=N; i++)
			c[i][l] = (1<<i);
		for (int i=l+1; i<=N; i++)
			for (int j=0; j<=(i-l-1); j++)
				c[i][l] -= choose(i, j);
	}
	// output
	string ans = "";
	int lin = L;
	for (int i=N; i>=1; i--) {
		if (I > c[i-1][lin] && lin) {
			ans += "1";
			I -= (c[i-1][lin--]);
		} else ans += "0";
	}
	fout << ans << endl;
	return 0;
}