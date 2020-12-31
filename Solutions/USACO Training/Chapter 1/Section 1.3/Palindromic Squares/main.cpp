
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
		rval = string(1, reVal(decimal % B)) + rval;
		decimal /= B;
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
	cin >> B;
	// main
	for (int i=1; i<=300; i++) {
		string o = convert(i), os = convert(i*i);
		if (palindromic(os)) {
			cout << o << " " << os << endl;
		}

	}
	cout <<"100 = "<<convert(100)<<'\n';
	return 0;
}