# Prime Palindromes
```cpp
/*
 ID: dongliu3
 TASK: pprime
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
int a, b;

ifstream fin("pprime.in");
ofstream fout("pprime.out");

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
bool check(int num) {
	return (num >= a && num <= b && prime(num));
}
void solve() {
	int palindrome, d1, d2, d3, d4;
	//1
	for (d1 = 1; d1 <= 9; d1 += 2) {
		palindrome = d1;
		if (check(palindrome)) {
			fout << palindrome << endl;
		}
	}
	//2
	for (d1 = 1; d1 <= 9; d1 += 2) {
		palindrome = d1*10 + d1;
		if (check(palindrome)) {
			fout << palindrome << endl;
		}
	}
	//3
	for (d1 = 1; d1 <= 9; d1 += 2) {
		for (d2 = 0; d2 <= 9; d2++) {
			palindrome = d1*100 + d2*10 + d1;
			if (check(palindrome)) {
				fout << palindrome << endl;
			}
		}
	}
	//4
	for (d1 = 1; d1 <= 9; d1 += 2) {
		for (d2 = 0; d2 <= 9; d2++) {
			palindrome = d1*1000 + d2*100 + d2*10 + d1;
			if (check(palindrome)) {
				fout << palindrome << endl;
			}
		}
	}
	//5
	for (d1 = 1; d1 <= 9; d1 += 2) {
		for (d2 = 0; d2 <= 9; d2++) {
			for (d3 = 0; d3 <= 9; d3++) {
				palindrome = 10000*d1 + 1000*d2 + 100*d3 + 10*d2 + d1;
				if (check(palindrome)) {
					fout << palindrome << endl;
				}
			}
		}
	}
	//6
	for (d1 = 1; d1 <= 9; d1 += 2) {
		for (d2 = 0; d2 <= 9; d2++) {
			for (d3 = 0; d3 <= 9; d3++) {
				palindrome = 100000*d1 + 10000*d2 + 1000*d3 + 100*d3 + 10*d2 + d1;
				if (check(palindrome)) {
					fout << palindrome << endl;
				}
			}
		}
	}
	//7
	for (d1 = 1; d1 <= 9; d1 += 2) {
		for (d2 = 0; d2 <= 9; d2++) {
			for (d3 = 0; d3 <= 9; d3++) {
				for (d4 = 0; d4 <= 9; d4++) {
					palindrome = 1000000*d1 + 100000*d2 + 10000*d3+ 1000*d4 + 100*d3 + 10*d2 + d1;
					if (check(palindrome)) {
						fout << palindrome << endl;
					}
				}
			}
		}
	}
	//8
	for (d1 = 1; d1 <= 9; d1 += 2) {
		for (d2 = 0; d2 <= 9; d2++) {
			for (d3 = 0; d3 <= 9; d3++) {
				for (d4 = 0; d4 <= 9; d4++) {
					palindrome = 10000000*d1 + 1000000*d2 + 100000*d3+ 10000*d4 + 1000*d4 + 100*d3 + 10*d2 + d1;
					if (check(palindrome)) {
						fout << palindrome << endl;
					}
				}
			}
		}
	}
}
int main() {
	// local variables

	// fstream

	// input
	fin >> a >> b;
	// main
	solve();

	return 0;
}
```