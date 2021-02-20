/**
 * CF Theatre Square
 * https://codeforces.com/contest/1/problem/A
 * Created on 2021-02-17
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N (1 << 18) // 2e5

long long cdiv(long long a, long long b) {
	return (a / b + (a % b ? 1 : 0));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	static long long n, m, a;
	cin >> n >> m >> a;
	cout << cdiv(n, a) * cdiv(m, a) << '\n';
}