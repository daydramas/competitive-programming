/**
 * CF Guess the Number
 * https://codeforces.com/gym/101021
 * Created on 2021-02-17
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N (1 << 18) // 2e5

string query(int x) {
	cout << x << '\n';
	cout.flush();
	string s;
	cin >> s;
	return s;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int low = 1, high = 1e6;
	while (low < high) {
		int middle = (low + high + 1) / 2;
		string s = query(middle);
		if (s == "<")
			high = middle - 1;
		else
			low = middle;
	}
	cout << "! " << low << '\n';
	cout.flush();
}