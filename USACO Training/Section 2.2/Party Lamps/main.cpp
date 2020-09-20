/*
 ID: dongliu3
 TASK: lamps
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
#define vi vector<int>
// global variables
int N, C;
vi On;
vi Off;
int cnt = 0;
map<vi, bool> mark;
vector<string> ans;
ofstream fout("lamps.out");
// functions
bool check(vi a) {
	for (int i : On) if (a[i] == 0) return false;
	for (int i : Off) if (a[i] == 1) return false;
	return true;
}
vi change1(vi a) {
	for (int i=1; i<=N; i++) a[i] = 1-a[i];
	return a;
}
vi change2(vi a) {
	for (int i=1; i<=N; i+=2) a[i] = 1-a[i];
	return a;
}
vi change3(vi a) {
	for (int i=2; i<=N; i+=2) a[i] = 1-a[i];
	return a;
}
vi change4(vi a) {
	for (int i=1; i<=N; i+=3) a[i] = 1-a[i];
	return a;
}
void dfs(vi s, int changed, int a, int b, int c, int d) {
	if (mark[s]) return;
	if (check(s)) {
		cnt++;
		string str = "";
		for (int i=1; i<=N; i++) {
			str += to_string(s[i]);
		}
		ans.push_back(str);
		mark[s] = true;
	}
	if (changed == C) return;
	if (a == 0) dfs(change1(s), changed+1, a+1, b, c, d);
	if (b == 0)dfs(change2(s), changed+1, a, b+1, c, d);
	if (c == 0)dfs(change3(s), changed+1, a, b, c+1, d);
	if (d == 0)dfs(change4(s), changed+1, a, b, c, d+1);
}
int main() {
	// local variables

	// fstream
	ifstream fin("lamps.in");

	// input
	fin >> N >> C;
	int Lmp;
	fin >> Lmp;
	while(Lmp != -1) {
		On.push_back(Lmp);
		fin >> Lmp;
	}
	fin >> Lmp;
	while(Lmp != -1) {
		Off.push_back(Lmp);
		fin >> Lmp;
	}
	// main
	vi T(N+1, 1);
	dfs(T, 0, 0, 0, 0, 0);
	// output
	sort(ans.begin(), ans.end());
	if (cnt == 0) {
		fout <<"IMPOSSIBLE"<<endl;
	} else {
		for (string i : ans) {
			fout << i << endl;
		}
	}
	return 0;
}