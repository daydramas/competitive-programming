# Street Race
```cpp
  
/*
 ID: dongliu3
 TASK: race3
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
int N;
vector<int> adj[105];
bool visited[2][105];
vector<int> ans1, ans2;

// functions
void dfs(int i, int j) {
	for (int k : adj[i]) if (!visited[j][k]) {
		visited[j][k] = true;
		dfs(k, j);
	}
}
int main() {
	// local variables

	// fstream
	ifstream fin("race3.in");
	ofstream fout("race3.out");

	// input
	N = 0; int in;
	while (fin >> in) {
		switch(in) {
			case -1:
				break;
			case -2:
				N++;
				break;
			default:
				adj[N].push_back(in);
				break;
		}
	}
	N--;
	// main
	for (int i=1; i<N; i++) {
		memset(visited[0], false, sizeof(visited[0]));
		visited[0][0] = visited[0][i] = true; // stops at point i
		dfs(0, 0);
		if (!visited[0][N]) { // needs to pass through point i
			ans1.push_back(i);
			memset(visited[1], false, sizeof(visited[1]));
			visited[1][i] = true; dfs(i, 1);
			bool ok = true;
			for (int j=0; j<=N; j++) {
				ok &= (i==j || (!visited[0][j] || !visited[1][j]));
			}
			if (ok) ans2.push_back(i);
		}
	}
	// output

	fout << ans1.size();
	for (int i=0; i<ans1.size(); i++) fout << " " << ans1[i];
	fout << endl << ans2.size();
	for (int j=0; j<ans2.size(); j++) fout<< " " << ans2[j];
	fout << endl;
	return 0;
}
```