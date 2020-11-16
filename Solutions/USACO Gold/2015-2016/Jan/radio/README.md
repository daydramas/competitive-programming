# radio
```cpp
/*
 ID: dongliu3
 TASK: radio
 LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

// structures/defines
#define Pair pair<int, int>
#define x first
#define y second

// global variables
int N, M;
Pair f, b;
string sF, sB;
int dp[1001][1001];
Pair pF[1001], pB[1001];
map<char, int> X, Y;

//functions
int sq(int i) {
	return i * i;
}
int getDist(int F, int B) {
//	cout <<"dist btwn: "<<F<<" and "<<B<<" is "<<sq(abs(pF[F].x - pB[B].x)) + sq(abs(pF[F].y - pB[B].y))<<endl;
	return sq(abs(pF[F].x - pB[B].x)) + sq(abs(pF[F].y - pB[B].y));
}
int main() {
// local variables

// fstream
	ifstream fin("radio.in");
	ofstream fout("radio.out");

// input
	fin >> N >> M;
	fin >> f.x >> f.y >> b.x >> b.y;
	fin >> sF >> sB;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			dp[i][j] = 1000000000;
		}
	}

	X['N'] = 0, Y['N'] = 1;
	X['S'] = 0, Y['S'] = -1;
	X['E'] = 1, Y['E'] = 0;
	X['W'] = -1, Y['W'] = 0;
	pF[0] = f, pB[0] = b;
	for (int i = 1; i <= N; i++) {
		pF[i].x = X[sF[i - 1]] + pF[i - 1].x;
		pF[i].y = Y[sF[i - 1]] + pF[i - 1].y;
	}
	for (int i = 1; i <= M; i++) {
		pB[i].x = X[sB[i - 1]] + pB[i - 1].x;
		pB[i].y = Y[sB[i - 1]] + pB[i - 1].y;
//		cout << pB[i].x << " " << pB[i].y << endl;
	}
// main
	dp[0][0] = 0;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
//			cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
			if (i + 1 <= N) {
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + getDist(i + 1, j));
			}
			if (j + 1 <= M) {
				dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + getDist(i, j + 1));
			}
			if (i + 1 <= N && j + 1 <= M) {
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1],
						dp[i][j] + getDist(i + 1, j + 1));
			}
		}
	}
// output
	fout << dp[N][M] << endl;
	return 0;
}

```