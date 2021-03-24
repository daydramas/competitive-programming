#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	string name; int score;
	vector<pair<string, int>> todo;
	map<string, int> m, M;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> name >> score;
		todo.push_back({name, score});
		m[name] += score;
	}

	int winning_score = 0;

	for (auto& x : m)
		winning_score = max(winning_score, x.second);

	string winner = "none";
	for (auto& x : todo) {
		M[x.first] += x.second;
		if (m[x.first] == winning_score && M[x.first] >= winning_score) {
			winner = x.first;
			break;
		}
	}
	cout << winner << '\n';
}