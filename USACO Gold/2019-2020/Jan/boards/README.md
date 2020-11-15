# boards
```cpp
/*
 ID: dongliu3
 TASK: boards
 LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

// structures/defines
#define pii pair<int, int>
#define ppii pair<pii, pii>
#define x first
#define y second
// global variables
int N, P;
vector<ppii> pnt;
map <int,
int> m;
int ans[100001];
//functions
void update(int y1, int value) {
//	cout << "hi" << endl;
	map<int, int>::iterator it = prev(m.upper_bound(y1));
//	cout << "hi" << endl;
	if (it->y > value) {
		++it;
		while (it != m.end() && it->y > value) {
			m.erase(it++);
//			it++;
		}
		m[y1] = value;
	}
}
int main() {
	// local variables

	// fstream
	ifstream fin("boards.in");
	ofstream fout("boards.out");
	// input
	fin >> N >> P;
	for (int i = 1; i <= P; i++) {
		pii a, b;
		fin >> a.x >> a.y >> b.x >> b.y;
		pnt.push_back(ppii(a, pii(i, 1)));
		pnt.push_back(ppii(b, pii(i, -1)));
	}
	// main
//	cout << "hi" <''< endl;
	sort(pnt.begin(), pnt.end());
//	cout << "hi" << endl;
	m[0] = 0;
//	m[-1] = 0;
	for (ppii p : pnt) {
//		cout << "hi2" << endl;
		if (p.y.y == 1) { // start
//			cout << "hi3" << endl;
			ans[p.y.x] = p.x.x + p.x.y + prev(m.upper_bound(p.x.y))->y;
//			cout << "hi3" << endl;
		} else { //end
//			cout << "hi4" << endl;
			update(p.x.y, ans[p.y.x] - p.x.x - p.x.y);
//			cout << "hi4" << endl;

		}
	}
//	cout << "hi" << endl;
	// output
	fout << (m.rbegin()->y) + (2 * N) << endl;

	return 0;
}

```