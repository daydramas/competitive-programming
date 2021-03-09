/*
 ID: dongliu3
 TASK: fracdec
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
#define INF 1000000000

// global variables
int N, D;
int printed = 0;
int mod, original, value;

ifstream fin("fracdec.in");
ofstream fout("fracdec.out");

// functions
void print(string str) {
	for (char ch : str) {
		fout << ch;
		printed++;
		if (printed % 76 == 0) fout << endl;
	}
}
void print(int s) {
	print(to_string(s));
}
int main() {
	// local variables

	// fstream


	// input
	fin >> N >> D;

	// main
	print(N / D);
	print(".");
	if (N % D == 0) {
		print("0");
		if (printed != 76) fout << endl;
		return 0;
	}
	mod = N % D;
	vector<int> sequence;
	map<int, int> m;

	while (true) {
		original = mod * 10;
		value = original / D;
		mod = original % D;
		if (mod == 0) {
			for (int i : sequence)
				print(i);
			print(value);
			break;
		}
		if (m.find(original) == m.end()) {
			m[original] = sequence.size();
			sequence.push_back(value);
		} else {
			int pos = m.find(original)->second;
			for (int i = 0; i < pos; ++i) {
				print(sequence[i]);
			}
			print("(");
			for (int i = pos; i < sequence.size(); ++i) {
				print(sequence[i]);
			}
			print(")");
			break;
		}
	}
	if (printed % 76 != 0) fout << endl;
	return 0;
}