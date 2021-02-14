#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

//structures/defines
#define ll long long
#define pii pair<int, int>

//global variables
int n, m;
vector<int> adj[500005];
pii color[500005];
int colored[500005];

//functions
void solve() {

}
int main() {
	//local variables

	//input
	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i=1; i<=n; i++) {
		cin >> color[i].first;
		color[i].second = i;
		colored[i] = -1;
	}
	for (int i=1; i<=n; i++) {
		for (int j : adj[i]) {
			if (color[i].first == color[j].first) {
				cout << "-1"<<endl;
				return 0;
			}
		}
	}
	sort(color + 1, color + n + 1);

	//main
	int S[500005];
	for (int i=1; i<=n; i++) {
		int in = color[i].second;
		int cr = 1;
//		unordered_set <int> S;

//		for (int i1=1; i1<=n; i1++) cout << S[i1]<<" ";
//		cout << endl;
		for (int j : adj[in]) {
			if (colored[j] != -1) {
				S[colored[j]] = 1;
				if (colored[j]==cr) cr++;
			}
		}
		while(S[cr]) {
			cr++;
			if (cr > color[i].first) break;
		}
		if (cr != color[i].first) {
			cout << "-1"<<endl;
			return 0;
		}
		colored[in] = color[i].first;
		for (int j : adj[in]) {
			if (colored[j] != -1) {
				S[colored[j]] = 0;
			}
		}
	}
	//output
	for (int i=1; i<=n; i++) {
		cout << color[i].second <<" ";
	}cout << endl;

	return 0;
}
