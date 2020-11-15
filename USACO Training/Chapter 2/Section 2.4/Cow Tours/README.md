```cpp
  
/*
 ID: dongliu3
 TASK: cowtour
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
#define MAXN 151
#define INF 1000000000.0

// global variables
int N;
int x[MAXN], y[MAXN];
double d[MAXN][MAXN];
double mD[MAXN];
double ans;

// functions
double getD(int i, int j) {
    double dx = x[i]-x[j];
    double dy = y[i]-y[j];
    return sqrt(dx*dx + dy*dy);
}
int main() {
	// local variables

	// fstream
	ifstream fin("cowtour.in");
	ofstream fout("cowtour.out");

	// input
	fin >> N;
	for (int i=1; i<=N; i++) fin >> x[i] >> y[i];
	for (int i=1; i<=N; i++) {
		string str; fin >> str;
		for (int j=1; j<=N; j++) {
			if (str[j-1] == '1') d[i][j] = getD(i, j);
			else d[i][j] = INF;
			if (i==j) d[i][j] = 0;
		}
	}
	// main
	ans = INF;
	for (int k=1; k<=N; k++) for (int i=1; i<=N; i++) for (int j=1; j<=N; j++)
		if (d[i][k]+d[k][j] < d[i][j])
			d[i][j] = d[i][k]+d[k][j];
	for (int i=1; i<=N; i++) {
		mD[i] = -1;
		for (int j=1; j<=N; j++) if (d[i][j] != INF)
			mD[i] = max(mD[i], d[i][j]);
		for (int j=1; j<i; j++) if (d[i][j] == INF)
			ans = min(ans, mD[i]+mD[j]+getD(i, j));
	}
	for (int i=1; i<=N; i++) ans = max(ans, mD[i]);
	// output
	fout << fixed << setprecision(6) << ans << endl;
	return 0;
}
```