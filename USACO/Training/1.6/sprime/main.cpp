/*
 ID: dongliu3
 TASK: sprime
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
#define vi vector<int>
// global variables
int N;
// functions
bool prime(int n) {
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;
	if (n % 2 == 0 || n % 3 == 0)
		return false;
	for (int i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
	return true;
}
vi solve(int n) {
	vi rval;
	if (n == 1) {
		rval.push_back(2);
		rval.push_back(3);
		rval.push_back(5);
		rval.push_back(7);
	} else {
		vi before = solve(n-1);
		for (int i : before) {
			for (int j=0; j<=9; j++) {
				int nxt = stoi(to_string(i)+to_string(j));
				if (prime(nxt)) {
					rval.push_back(nxt);
				}
			}
		}
	}
	return rval;
}
int main() {
	// local variables

	// fstream
	ifstream fin("sprime.in");
	ofstream fout("sprime.out");

	// input
	fin >> N;

	// main
	vi ans = solve(N);

	// output
	for (int i : ans) {
		fout << i << endl;
	}
	return 0;
}