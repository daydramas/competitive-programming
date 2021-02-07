/**
 * spiralprint
*/

#include <iostream>
using namespace std;

#define N	500

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	freopen("spiralprint.in", "r", stdin);
	freopen("spiralprint.out", "w", stdout);

	static int n, a[N][N], v[N][N];

	cin >> n;
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++) {
		cin >> a[i][j];
		v[i][j] = 0;
	}

	const int X[] = {0, 1, 0, -1};
	const int Y[] = {1, 0, -1, 0};
	int dir = 0;
	int i=0, j=0, x, y, done=0;
	while(done < n*n) {
		v[i][j] = 1, done++;
		cout << a[i][j] << '\n';
		x = i + X[dir], y = j + Y[dir];
		if(v[x][y] || x<0 || y<0 || x>=n || y>=n) {
			dir = (dir+1) % 4;
			x = i + X[dir], y = j + Y[dir];
		}
		i = x, j = y;
	}
}