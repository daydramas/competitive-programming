# Frame Up
```cpp
/*
 ID: dongliu3
 TASK: frameup
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// global variables
const int maxn = 35;
int N, M;
int grid[maxn][maxn], after[maxn][maxn];
int inGrid[maxn], to[maxn], numInGrid;
vector<string>ans;

// structures/defines
#define INF 1000000000
struct frame {
	int T, B, L, R;
	void initialize() {
		T = INF, B = -INF, L = INF, R = -INF;
	}
	void update(int x, int y) {
		T = min(T, x), B = max(B, x);
		L = min(L, y), R = max(R, y);
	}
	void createAfter (int color) {
		for (int i=T; i<=B; i++) {
			if (grid[i][L] != color) after[color][grid[i][L]] = 1;
			if (grid[i][R] != color) after[color][grid[i][R]] = 1;
		}
		for (int i=L; i<=R; i++) {
			if (grid[T][i] != color) after[color][grid[T][i]] = 1;
			if (grid[B][i] != color) after[color][grid[B][i]] = 1;
		}
	}
} frames[maxn];

// functions
int ctoi (char ch) { return ch-'A'+1; }
void dfs(int did, string curr) {
	if (did == numInGrid) {
		ans.push_back(curr);
		return;
	}
	for (int i=1; i<=26; i++) {
		if (inGrid[i] && !to[i]) {
			inGrid[i] = false;
			for (int j=1; j<=26; j++)
				if (after[i][j]) to[j]--;
			dfs(did+1, curr+string(1, 'A'+i-1));
			inGrid[i] = true;
			for (int j=1; j<=26; j++)
				if (after[i][j]) to[j]++;
		}
	}
}
int main() {
	// local variables

	// fstream
	ifstream fin("frameup.in");
	ofstream fout("frameup.out");

	// input
	fin >> N >> M;
	for (int i=1; i<=26; i++) {
		frames[i].initialize();
	}
	for (int i=1; i<=N; i++) {
		string str; fin >> str;
		for (int j=1; j<=M; j++) if (isalpha(str[j-1])) {
			grid[i][j] = ctoi(str[j-1]);
			frames[ctoi(str[j-1])].update(i, j);
			inGrid[ctoi(str[j-1])] = 1;
		}
	}

	// main
	numInGrid = 0;
	for (int i=1; i<=26; i++) {
		if (inGrid[i]) { frames[i].createAfter(i); numInGrid++; }
	}
	for (int i=1; i<=26; i++)
	for (int j=1; j<=26; j++)
		if (after[i][j]) to[j]++;

	// output
	dfs(0, ""); sort(ans.begin(), ans.end());
	for (string s : ans) fout << s << endl;
	return 0;
}
```