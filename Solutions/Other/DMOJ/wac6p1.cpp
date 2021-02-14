/**
 * Wesley's Anger Contest 6 Problem 1 - Timbit Sales
 * https://dmoj.ca/problem/wac6p1
 */

#include <iomanip>
#include <iostream>
using namespace std;

#define N (1 << 18) // 2e5

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	static int n;
	static double p, o, c;

	cin >> n;
	cout << fixed << setprecision(10);
	while (n--) {
		cin >> p;
		cin >> c;
		o = 100.0 * p / (c + 100);
		cout << o << '\n';
	}
}