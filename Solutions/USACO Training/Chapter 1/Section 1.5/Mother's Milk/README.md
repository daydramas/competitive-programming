# Mother's Milk
```cpp
/*
 ID: dongliu3
 TASK: milk3
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
int A, B, C;
bool visited[25][25][25];
vector<int> cnt;
// functions
void solve(int a, int b, int c) {
	if(visited[a][b][c]) return;
	visited[a][b][c] = true;

	if(a == 0){
		cnt.push_back(c);
	}
	solve(a+min(c,A-a),b,c-min(c,A-a));
	solve(a-min(C-c,a),b,c+min(C-c,a));
	solve(a+min(b,A-a),b-min(b,A-a),c);
	solve(a-min(B-b,a),b+min(B-b,a),c);
	solve(a,b+min(c,B-b),c-min(c,B-b));
	solve(a,b-min(C-c,b),c+min(C-c,b));
}
int main() {
	// local variables

	// fstream
	ifstream fin("milk3.in");
	ofstream fout("milk3.out");

	// input
	fin >> A >> B >> C;
	for (int i=0; i<=20; i++) for (int j=0; j<=20; j++) for (int k=0; k<=20; k++) {
		visited[i][j][k] = false;
	}
	//main
	solve(0, 0, C);
	// output
	sort(cnt.begin(), cnt.end());
	for (int i : cnt){
		fout << i;
		if (i != cnt.back()) {
			fout << " ";
		}
	}
	fout << endl;
	return 0;
}
```