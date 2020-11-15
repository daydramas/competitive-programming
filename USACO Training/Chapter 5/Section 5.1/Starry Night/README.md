# Starry Night
```cpp
/*
 ID: dongliu3
 TASK: starry
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
#define pii pair<int, int>
#define INF 1000000000
#define f first
#define s second

// global variables
int W, H;
bool grid[105][105], mark[105][105];
int pic[105][105];
int X[] = {1, 0, -1, 0, 1, 1, -1, -1};
int Y[] = {0, 1, 0, -1, 1, -1, 1, -1};
map<string, int> ok[165][165];
pii m, M;

// functions
void floodfill(int i, int j, int color) {
	pic[i][j] = color, mark[i][j] = true;
	m.f = min(m.f, i);
	m.s = min(m.s, j);
	M.f = max(M.f, i);
	M.s = max(M.s, j);
	for (int k=0; k<8; k++) {
		int x=i+X[k], y=j+Y[k];
		if (!(x>=1 && x<=H && y>=1 && y<=W)) continue;
		if (mark[x][y] || !grid[x][y]) continue;
		floodfill(x, y, color);
	}
}
int getID(int i, int j, int n, int m) { return i*m + j; }
string rotate1(string str, int n, int m) {
	string result = "";
	for (int i=0; i<m; i++) for (int j=0; j<n; j++)
		result += str[getID(n-j-1, i, n, m)];
	return result;
}
string flip1(string str, int n, int m) {
	string result = "";
	for (int i=0; i<n; i++) for (int j=0; j<m; j++)
		result += str[getID(i, m-j-1, n, m)];
	return result;
}
int main() {
	// local variables

	// fstream
	ifstream fin("starry.in");
	ofstream fout("starry.out");

	// input
	fin >> W >> H;
	for (int i=1; i<=H; i++) {
		string str; fin >> str;
		for (int j=1; j<=W; j++) {
			grid[i][j] = (str[j-1] == '1');
		}
	}
	// main
	memset(mark, false, sizeof(mark));
	int color = 0;
	for (int i=1; i<=H; i++) for (int j=1; j<=W; j++) {
		if (!mark[i][j] && grid[i][j]) {
			m = pii(INF, INF), M = pii(-INF, -INF);
			floodfill(i, j, ++color);
			string shape = "", shape2 = "";
			for (int k=m.f; k<=M.f; k++) for (int l=m.s; l<=M.s; l++)
				if (pic[k][l] == color) shape += "1";
				else shape += "0";
			int n1 = M.f-m.f+1, m1 = M.s-m.s+1;
			int newcolor = -1;
			for (int k=0; k<4; k++) {
				if (ok[n1][m1][shape]) {
					newcolor = ok[n1][m1][shape];
					break;
				}
				shape2 = flip1(shape, n1, m1);
				if (ok[n1][m1][shape2]) {
					newcolor = ok[n1][m1][shape2];
					break;
				}
				shape = rotate1(shape, n1, m1);
				swap(n1, m1);
			}
			if (newcolor == -1) {
				ok[n1][m1][shape] = color;
			} else {
				for (int k=m.f; k<=M.f; k++)
				for (int l=m.s; l<=M.s; l++)
					if (pic[k][l] == color) pic[k][l] = newcolor;
				color--;
			}
		}
	}
	// output
	for (int i=1; i<=H; i++) {
		for (int j=1; j<=W; j++) {
			if (!pic[i][j]) fout << pic[i][j];
			else fout << char(pic[i][j]+'a'-1);
		}
		fout << endl;
	}
	return 0;
}
```