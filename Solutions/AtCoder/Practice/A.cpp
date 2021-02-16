/**
 * Welcome to AtCoder
 * https://atcoder.jp/contests/practice/tasks/practice_1
 * Created on 2021-02-14
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N (1 << 18) // 2e5

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int a, b, c;
	string s;
	cin >> a >> b >> c >> s;
	cout << a + b + c << ' ' << s << '\n';
}