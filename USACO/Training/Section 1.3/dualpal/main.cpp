/*
 ID: dongliu3
 TASK: dualpal
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
int N, S;
// functions
char reVal(int num) {
	if (num >= 0 && num <= 9)
		return (char) (num + '0');
	else
		return (char) (num - 10 + 'A');
}
string convert(int decimal, int B) {
	string rval = "";
	while (decimal > 0) {
		rval = rval + reVal(decimal % B);
		decimal /= B;
	}
	int len = rval.length();
	for (int i = 0; i < len / 2; i++) {
		char temp = rval[i];
		rval[i] = rval[len - i - 1];
		rval[len - i - 1] = temp;
	}
	return rval;
}
bool palindromic(string str) {
	int len = str.length();
	for (int i = 0; i < len / 2; i++) {
		if (str[i] != str[len - i - 1]) {
			return false;
		}
	}
	return true;
}
int main() {
	// local variables

	// fstream
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");

	// input
	fin >> N >> S;
	S++;

	// main
	for (; N > 0; S++) {
		int P = 0;
		for (int i=2; i<=10; i++) {
			if (palindromic(convert(S, i))) {
				P++;
			}
		}
		if (P >= 2) {
			N--;
			fout << S << endl;
		}
	}
	// output

	return 0;
}