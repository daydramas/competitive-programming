```cpp
  
/*
 ID: dongliu3
 TASK: palsquare
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
int B;

// functions
char reVal(int num) {
	if (num >= 0 && num <= 9)
		return (char) (num + '0');
	else
		return (char) (num - 10 + 'A');
}
string convert(int decimal) {
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
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");

	// input
	fin >> B;
	// main
	for (int i=1; i<=300; i++) {
		string o = convert(i), os = convert(i*i);
		if (palindromic(os)) {
			fout << o << " " << os << endl;
		}

	}

	return 0;
}
```