# Shuttle Puzzle
```cpp
/*
 ID: dongliu3
 TASK: shuttle
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
struct state {
	string curr, moves; int loc;
	state(string curr, string moves, int loc) : curr(curr), moves(moves), loc(loc) {}
};

// global variables
int N;
string ostr, gstr, ans;
set<string> mark;

// functions

// special defines
#define check(s) mark.find(s) == mark.end()

int main() {
	// local variables

	// fstream
	ifstream fin("shuttle.in");
	ofstream fout("shuttle.out");

	// input
	fin >> N;
	ostr = "", gstr = "", ans = "";
	for (int i=1; i<=N; i++) ostr += "W", gstr += "B";
	ostr += " ", gstr += " ";
	for (int i=1; i<=N; i++) ostr += "B", gstr += "W";

	// main
	queue<state> Q; Q.push(state(ostr, "", N));
	mark.insert(ostr);
	while(!Q.empty()) {
		string t = Q.front().curr, m = Q.front().moves;
		int l = Q.front().loc;
		Q.pop();
		if (t == gstr) { ans = m; break; }
		string tt;
		tt = t;
		if (l>1 && t[l-2] == 'W' && t[l-1] == 'B') {
			swap(tt[l], tt[l-2]);
			if (check(tt)) {
				Q.push(state(tt, m+to_string(l-1)+" ",l-2));
				mark.insert(tt);
			}
		}
		tt = t;
		if (l>0 && t[l-1] == 'W') {
			swap(tt[l], tt[l-1]);
			if (check(tt)) {
				Q.push(state(tt, m+to_string(l)+" ",l-1));
				mark.insert(tt);
			}
		}
		tt = t;
		if (l<t.size() && t[l+1] == 'B') {
			swap(tt[l], tt[l+1]);
			if (check(tt)) {
				Q.push(state(tt, m+to_string(l+2)+" ",l+1));
				mark.insert(tt);
			}
		}
		tt = t;
		if (l<t.size()-1 &&  t[l+2] == 'B' && t[l+1] == 'W') {
			swap(tt[l], tt[l+2]);
			if (check(tt)) {
				Q.push(state(tt, m+to_string(l+3)+" ",l+2));
				mark.insert(tt);
			}
		}
	}
	// output
	for (int i=0, done=0; i<ans.size(); i+=2, done++) {
		if (done%20 == 0 && i) fout << endl;
		if (done%20) fout <<" ";
		fout << ans[i];
		if (ans[i+1] != ' ') fout << ans[++i];
	}
	if (ans.size()%20) fout << endl;
	return 0;
}
```