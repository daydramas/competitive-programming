/*
 ID: dongliu3
 TASK: msquare
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// global variables
string O;
string ans = "";
set<string> visited;

// structures/defines
#define vi vector<int>
struct state {
	string s; string c;
	void init(string s2, string c2) { s = s2; c = c2; }
	bool check() { return (O == s); }
};


// functions

int main() {
	// local variables

	// fstream
	ifstream fin("msquare.in");
	ofstream fout("msquare.out");

	// input
	O = "";
	for (int i=0; i<8; i++) {
		string in; fin >> in;
		O += in;
	}
	// main
	state s;
	queue<state> Q;
	s.init("12345678", "");
	Q.push(s);
	while(!Q.empty()) {
		state f = Q.front(); Q.pop();

		if (visited.count(f.s)) continue;
		visited.insert(f.s);

		if (f.check()) {
			ans = f.c;
			break;
		}

		//A
		string temp = f.s;
		reverse(temp.begin(), temp.end());
		s.init(temp, f.c+"A");
		Q.push(s);

		//B
		string temp2 = f.s.substr(3, 1) + f.s.substr(0, 3) + f.s.substr(5, 3)
				+ f.s.substr(4, 1);
		s.init(temp2, f.c+"B");
		Q.push(s);

		//C
		string temp3 = f.s.substr(0, 1) + f.s.substr(6, 1) + f.s.substr(1, 1)
				+ f.s.substr(3, 2) + f.s.substr(2, 1) + f.s.substr(5, 1)
				+ f.s.substr(7, 1);
		s.init(temp3, f.c+"C");
		Q.push(s);
	}
	// output
	int did = 0;
	fout << ans.length() << endl;
	for (char ch : ans) {
		fout << ch;
		if (did && did%60 == 0) fout << endl;
		did++;
	}
	if (!did || did%60 != 0) fout << endl;
	return 0;
}