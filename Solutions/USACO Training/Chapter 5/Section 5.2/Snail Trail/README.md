# Snail Trail
```cpp
/*
 ID: dongliu3
 TASK: snail
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
int N, B;
int land[121][121];
int ans = 0;
int X[] = {1, 0, -1, 0};
int Y[] = {0, 1, 0, -1};
bool visited[121][121];

// functions
int valid(int x, int y) {
	if (x<0 || x>=N || y<0 || y>=N) return 1;
	if (land[x][y] == 1) return 0;
	if (land[x][y] == 2) return 1;
	return 2;
}
int dfs(int x, int y, int dir) {
	int x1 = x, y1 = y, ans = 0;

	while (valid(x+X[dir],y+Y[dir]) == 2) {
		x += X[dir], y += Y[dir];
		land[x][y] = 1;
		ans++;
	} // walk until it reaches wall/boundaries

	if (ans == 0) return 0; //stuck...

	if (valid(x+X[dir],y+Y[dir]) == 1) {
		int a = dfs(x,y,(dir+1)%4);
		int b = dfs(x,y,(dir+3)%4);
		ans += max(a, b);
	} //split paths when reached wall

	while (x != x1 || y != y1) {
		land[x][y] = 0;
		x -= X[dir], y -= Y[dir];
	} //reset the visited cells

	return ans;
}
int main() {
	// local variables

	// fstream
	ifstream fin("snail.in");
	ofstream fout("snail.out");

	// input
	fin >> N >> B;
	for (int i=1; i<=B; i++) {
		string s; fin >> s;
		int y = (s[0]-'A');
		s.erase(s.begin());
		int x = stoi(s)-1;
		land[x][y] = 2;
	}
	// main
	land[0][0] = 1;

	// output

	fout << 1+max(dfs(0,0,0), dfs(0,0,1)) << endl;
	return 0;
}
```