/**
 * CF Winner
 * https://codeforces.com/contest/2/problem/A
 * Created on 2021-03-02
 */

#include <iostream>
#include <string>
#include <map>
using namespace std;

#define INF 0x3f3f3f3f

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	map<string, int> score;
	string winner; 
	int best = -INF;	

	cin >> n;
	for (int i = 0; i < n; ++i) {
		string name; int value;
		cin >> name >> value;
		score[name] += value;
		if (score[name] > best) {
			best = score[name];
			winner = name;
		}
	}

	cout << winner << '\n';
}