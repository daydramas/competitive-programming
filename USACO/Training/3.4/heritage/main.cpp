/*
 ID: dongliu3
 TASK: heritage
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
string in, pre;

// functions
int FIND(string str, char s) {
	for (int i=0; i<str.length(); i++) if (str[i] == s) return i;
	return -1;
}
string SUBSTR(string str, int s, int e) {
	string rval = "";
	for (int i=s; i<=e; i++) rval += str[i];
	return rval;
}
string dfs(string P, string I) {
	if (P.length() == 0 || I.length() == 0) return "";
	int index = FIND(I, P[0]);
	if (index == -1) return string(1, P[0]);
	string left = dfs(SUBSTR(P, 1, index), SUBSTR(I, 0, index-1));
	string rght = dfs(SUBSTR(P, index+1, P.length()-1), SUBSTR(I,index+1, I.length()-1));
	return left+rght+P[0];
}
int main() {
	// local variables

	// fstream
	ifstream fin("heritage.in");
	ofstream fout("heritage.out");

	// input
	fin >> in >> pre;

	// main & output
	fout << dfs(pre, in) << endl;
	return 0;
}