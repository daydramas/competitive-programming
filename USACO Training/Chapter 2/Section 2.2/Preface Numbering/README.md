```cpp
/*
 ID: dongliu3
 TASK: preface
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
int N;
char ch[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M'};
map<char, int> cnt;
// functions
void disect(string a) {
	for (int i=0; i<a.size(); i++) {
		cnt[a[i]]++;
	}
}
void getRoman(int number) {
	int num[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
	string sym[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D",
			"CM", "M" };
	int i = 12;
	while (number > 0) {
		int div = number / num[i];
		number = number % num[i];
		while (div--) {
			disect(sym[i]);
		}
		i--;
	}
}
int main() {
	// local variables

	// fstream
	ifstream fin("preface.in");
	ofstream fout("preface.out");

	// input
	fin >> N;
	// main
	for (int i=1; i<=N; i++) {
		getRoman(i);
	}
	// ouput
	for (int i=0; i<7; i++) {
		if (cnt[ch[i]]) {
			fout << ch[i] << " " << cnt[ch[i]] << endl;
		}
	}
	return 0;
}
```