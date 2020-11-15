# camelot
```cpp
/*
 ID: dongliu3
 TASK: camelot
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
#define pii pair<int, int>
#define f first
#define s second

// global variables
int N, M;
pii KG; vector<pii> KT;
int X[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int Y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int D[35][35][35][35];

// functions
bool good(int i, int j, int x, int y, int nd) {
	return (x >= 1 && x <= N && y >= 1 && y <= M && (D[i][j][x][y]==-1 || D[i][j][x][y]>nd));
}
int main() {
	// local variables

	// fstream
	ifstream fin("camelot.in");
	ofstream fout("camelot.out");

	// input
	fin >> N >> M;
	char a1; int b1; fin >> a1 >> b1;
	KG = pii(b1, a1-'A'+1);
	char a; int b;
	while(fin >> a >> b) {
		KT.push_back(pii(b, a-'A'+1));
	}
	// main
	for (int i=1; i<=N; i++)
	for (int j=1; j<=M; j++)
	for (int k=1; k<=N; k++)
	for (int l=1; l<=M; l++)
		D[i][j][k][l] = 1000000000;
	for (int i=1; i<=N; i++)
	for (int j=1; j<=M; j++) {
		D[i][j][i][j] = 0;
		queue<pii> Q; Q.push(pii(i, j));
		while(!Q.empty()) {
			pii fr = Q.front(); Q.pop();
			for (int k=0; k<8; k++) {
				int x = fr.f+X[k];
				int y = fr.s+Y[k];
				if (good(i, j, x, y, D[i][j][fr.f][fr.s]+1)) {
					D[i][j][x][y] = D[i][j][fr.f][fr.s]+1;
					Q.push(pii(x, y));
				}
			}
		}
	}
	int ans = 1000000000;
	int si = max(KG.f-2, 1);
	int sj = max(KG.s-2, 1);
	int ei = min(KG.f+2, N);
	int ej = min(KG.s+2, M);
	for (int i=1; i<=N; i++)
	for (int j=1; j<=M; j++) {
		int tdist1 = 0, tdist2 = max(abs(KG.f-i),abs(KG.s-j));
		for (pii kn : KT){
			tdist1 += D[kn.f][kn.s][i][j];
			for (int i2=si; i2<=ei; i2++)
			for (int j2=sj; j2<=ej; j2++)
				tdist2 = min(tdist2, max(abs(KG.f-i2),abs(KG.s-j2))
						+D[kn.f][kn.s][i2][j2]+D[i2][j2][i][j]
						-D[kn.f][kn.s][i][j]);
		}
		if (tdist1 <0 || tdist2 <0) continue;
		ans = min(ans, tdist1+tdist2);
	}

	// output
	fout << ans << endl;
	return 0;
}
```