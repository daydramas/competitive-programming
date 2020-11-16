# Shopping Offers
```cpp
/*
 ID: dongliu3
 TASK: shopping
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
#define pii pair<int, int>
#define INF 1000000000
struct offer { int P, pro[6]; };
// global variables
int S, B;
offer O[110];
int dp[6][6][6][6][6];
int p[6], code[1000], cindex = 0;

// functions
int encode(int C) {
	if (code[C] == 0) code[C] = ++cindex;
	return code[C];
}
int main() {
	// local variables

	// fstream
	ifstream fin("shopping.in");
	ofstream fout("shopping.out");

	// input
	fin >> S;
	for (int i1=0; i1<=5; i1++)
	for (int i2=0; i2<=5; i2++)
	for (int i3=0; i3<=5; i3++)
	for (int i4=0; i4<=5; i4++)
	for (int i5=0; i5<=5; i5++)
		dp[i1][i2][i3][i4][i5] = INF;
	for (int i=1; i<=S; i++) {
		int n; fin >> n;
		for (int j=0; j<n; j++) {
			int k, c; fin >> c >> k;
			O[i].pro[encode(c)] = k;
		}
		fin >> O[i].P;
	}
	fin >> B;
	for (int i=1; i<=B; i++) {
		int c;
		fin >> c;
		fin >> p[encode(c)] >> O[S+i].P;
		O[S+i].pro[encode(c)] = 1;
	}
	// main
	dp[0][0][0][0][0] = 0;
	for (int i1=0; i1<=p[1]; i1++)
	for (int i2=0; i2<=p[2]; i2++)
	for (int i3=0; i3<=p[3]; i3++)
	for (int i4=0; i4<=p[4]; i4++)
	for (int i5=0; i5<=p[5]; i5++)
	for (int j=1; j<=(B+S); j++) {
		int j1 = i1 + O[j].pro[1];
		int j2 = i2 + O[j].pro[2];
		int j3 = i3 + O[j].pro[3];
		int j4 = i4 + O[j].pro[4];
		int j5 = i5 + O[j].pro[5];
		if (j1 > 5 || j2 > 5 || j3 > 5 || j4 > 5 || j5 > 5) continue;
		dp[j1][j2][j3][j4][j5] =
				min(dp[j1][j2][j3][j4][j5], (dp[i1][i2][i3][i4][i5] + O[j].P));
	}

	// output
	fout << dp[p[1]][p[2]][p[3]][p[4]][p[5]] << endl;
	return 0;
}
```