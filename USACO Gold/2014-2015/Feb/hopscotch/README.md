# hopscotch
```cpp
#include <bits/stdc++.h>
using namespace std;

// structures/defines
#define MAX 101
// global variables
struct BIT {
	int bit[MAX];
};
int N, M, K;
int grid[MAX][MAX];
BIT BITs[MAX * MAX];
int allbit[MAX];
//map<int, int> toIn;
//int toIn[564001];
//functions
int getBIT(int color, int y, int x) {
	int tx = x, ty = y;
	int sum = 0;
	for (x = tx; x > 0; x -= x & -x)
//		for (y = ty; y > 0; y -= y & -y) {
		sum = (sum + BITs[color].bit[x]) % 1000000007;
//		}
	return sum;
}
void updateBIT(int color, int y, int x, int val) {
	int tx = x, ty = y;
	for (x = tx; x <= N; x += (x & -x))
//		for (y = ty; y <= M; y += (y & -y)) {
		BITs[color].bit[x] = (BITs[color].bit[x] + val) % 1000000007;

//		}
}
int getAll(int y, int x) {
	int tx = x, ty = y;
	int sum = 0;
	for (x = tx; x > 0; x -= x & -x)
//		for (y = ty; y > 0; y -= y & -y)
		sum = (sum + allbit[x]) % 1000000007;
	return sum;
}
void updateAll(int y, int x, int val) {
	int tx = x, ty = y;
	for (x = tx; x <= N; x += (x & -x))
//		for (y = ty; y <= M; y += (y & -y))
		allbit[x] = (allbit[x] + val) % 1000000007;
}
int main() {
	// local variables

	// fstream
	ifstream fin("hopscotch.in");
	ofstream fout("hopscotch.out");
	// input
	fin >> N >> M >> K;
	int in = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			fin >> grid[i][j];
//			if (!toIn[grid[i][j]]) {
//				toIn[grid[i][j]] = in++;
//			}
//			grid[i][j] = toIn[grid[i][j]];
		}
	}
//	cout << "hi" << endl;
	for (int i = 1; i < N; i++) {
		vector<int> temp;
		for (int j = 1; j <= M; j++) {
//			cout << i << " " << j << endl;
			int a = (getAll(i - 1, j - 1) - getBIT(grid[i][j], i - 1, j - 1)
					+ 1000000007) % 1000000007;
			temp.push_back(a + (i == 1 && j == 1));
		}
		for (int j = 0; j < temp.size(); j++) {
//			cout << i << " " << j<< " " << grid[i][j+1],  << endl;
			updateBIT(grid[i][j + 1], i, j + 1, temp[j]);
			updateAll(i, j + 1, temp[j]);
		}
	}
//	cout << "hi" << endl;
	// output
	int ans = (getAll(N - 1, M - 1) - getBIT(grid[N][M], N - 1, M - 1)
			+ 1000000007) % 1000000007;
	fout << ans << endl;

	return 0;
}

```