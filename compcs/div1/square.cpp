/**
 * square
*/

#include <iostream>
using namespace std;

#define N	(1<<18) // 2e5

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);

	int x, y, x1, y1, i, j, i1, j1;
	cin >> x >> y >> x1 >> y1 >> i >> j >> i1 >> j1;

	int X = max(x1, i1) - min(x, i);
	int Y = max(y1, j1) - min(y, j);
	cout << max(X,Y) * max(X,Y) << '\n';
}