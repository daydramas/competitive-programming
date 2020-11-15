```cpp
/*
 ID: dongliu3
 TASK: fence9
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
#define pii pair<int, int>
#define x first
#define y second

// global variables
int N, M, P;

// functions
int gcd(int a, int b) { return (b==0) ? a : gcd(b, a%b); }
int check(pii a, pii b) {
	if (a.x == b.x) return abs(a.y-b.y)-1;
	if (a.y == b.y) return abs(a.x-b.x)-1;
	return gcd(abs(a.x-b.x),abs(a.y-b.y))-1;
}

int findPoints(pii a, pii b, pii c) {
	int area = abs(a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)) + 2;
	area -= (check(a, b)+check(b, c)+check(c, a)+3);
	area /= 2;
	return area;
}
int main() {
	// local variables

	// fstream
	ifstream fin("fence9.in");
	ofstream fout("fence9.out");

	// input
	fin >> N >> M >> P;

	// main & output
	int ans = findPoints(pii(0, 0), pii(N, M), pii(P, 0));
	fout << ans << endl;
	return 0;
}
```