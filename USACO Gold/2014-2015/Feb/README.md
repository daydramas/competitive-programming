<div align="center"> [cencoring.cpp](#0) | [fencing.cpp](#1) | [hopscotch.cpp](#2) </div>

# [cencoring.cpp](#0)
```cpp
/*
 _____     ______              ______                _______
 |     \   |      |  |\     |  |             |           |     |      |
 |	    \  |      |  | \    |  |             |           |     |      |
 |      |  |      |  |  \   |  |   ___       |           |     |      |
 |      |  |      |  |   \  |  |      |      |           |     |      |
 |      /  |      |  |    \ |  |      |      |           |     |      |
 |_____/   |______|  |     \|  |______|      |______  ___|___  |______|

 ___   ___        ___             ___   ___   ___  ___
 __ | __  |   | |    |   \   / |   | |___  |___| |    |   | \
     |___| |___| |___ |___/   \ |___|  ___| |   | |___ |___| /

 */

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include <iterator>
#include <stack>
#include <utility>
using namespace std;

// structures/defines

// global variables
string S;
vector<string> T;
int N;
int g[100001][30];
int out[100001], f[100001];
//functions
void build() {
	memset(out, 0, sizeof out);
	memset(g, -1, sizeof g);
	int states = 1;
	for (int i = 0; i < N; ++i) {
		const string &word = T[i];
//		string word = T[i];
		int currentState = 0;
		for (int j = 0; j < word.size(); ++j) {
			int ch = word[j] - 'a';
			if (g[currentState][ch] == -1)
				g[currentState][ch] = states++;

			currentState = g[currentState][ch];
		}

		//		out[currentState] |= (1 << i);
		out[currentState] = i + 1;
	}

	for (int ch = 0; ch < 26; ++ch)
		if (g[0][ch] == -1)
			g[0][ch] = 0;
	memset(f, -1, sizeof f);

	queue<int> q;

	for (int ch = 0; ch < 26; ++ch) {
		if (g[0][ch] != 0) {
			f[g[0][ch]] = 0;
			q.push(g[0][ch]);
		}
	}

	while (q.size()) {
		int state = q.front();
		q.pop();
		for (int ch = 0; ch <= 26; ++ch) {
			if (g[state][ch] != -1) {
				int failure = f[state];
				while (g[failure][ch] == -1)
					failure = f[failure];

				failure = g[failure][ch];
				f[g[state][ch]] = failure;
//				out[g[state][ch]] |= out[failure];
				q.push(g[state][ch]);
			}
		}
	}

}
int findNextState(int currentState, char nextInput) {
	int answer = currentState;
	int ch = nextInput - 'a';

	while (g[answer][ch] == -1)
		answer = f[answer];

	g[currentState][ch] = g[answer][ch];

	return g[answer][ch];
}

int main() {
	// local variables

	// fstream
	ifstream fin("censor.in");
	ofstream fout("censor.out");

	// input
	fin >> S >> N;
	for (int i = 0; i < N; i++) {
//		fin >> T[i];
		string tt;
		fin >> tt;
		T.push_back(tt);
//		out[i] = 0;
//		for(int j=0; j<=26; j++) {
//			g[i][j] = -1;
//		}
	}
//	for(int i=0; i<5; i++) {
//		cout << i << " "  << T[i]<<endl;
//	}
	/* Sort the search strings by length using a C++11 lambda expression. */
//	  sort(T.begin(), T.end(), [](const string& x, const string& y) -> bool {
//	                             return x.size() < y.size();
//	                           });
//	  cout <<endl;
	/*
	 *
	 *
	 */
//	for(int i=0; i<5; i++) {
//		cout << i << " "  << T[i]<<endl;
//	}
	build();
	// main
	string R = "";
	int R_i = 0;
	int bigJ[100001];
	bigJ[0] = 0;
	int currentState = 0;
	for (int i = 0; i < S.size(); ++i, R_i++) {
		R += S[i];
//		R[R_i+1] = S[i];
		currentState = findNextState(currentState, S[i]);
//		cout<<"R_i: "<<R_i<<" "<<currentState<<" " << R<<endl;
		bigJ[R_i] = currentState;

		// If match not found, move to next state
		if (out[currentState] == 0)
			continue;

		// Match found, print all matching words of arr[]
		// using output function.
		for (int j = 0; j < N; ++j) {
			if (out[currentState] == j + 1) {
//				if (out[currentState] & (1 << j)) {
				R_i = R_i - T[j].size();

				R.resize(R_i + 1);
//				R_i = R.size() - 1;
				currentState = bigJ[R_i];
//				cout<<i<<" "<<j<<" "<<bigJ[R_i]<<endl;
				break;
			}
		}
//		currentState = bigJ[R_i];

	}

	// output
	fout << R << endl;
	return 0;
}

```

# [fencing.cpp](#1)
```cpp
/*
 ID: dongliu3
 TASK: fencing
 LANG: C++
 */

//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

// structures/defines
#define Point pair<int, int>
#define x first
#define y second

// global variables
int N, Q;
Point points[200000];
Point p0;
vector<Point> polygon;
pair<Point,
Point> side[200000];
vector<pair<double,
pair<Point, Point> > > v;
//functions
int distSq(Point p1, Point p2) {
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}
double getSlope(Point p1, Point p2) {
	if (p2.x - p1.x == 0) {
		return 0;
	}
	if (p2.y - p1.y == 0) {
		return -10000000;
	}
	return -1 / ((p2.y - p1.y) * 1.0 / (p2.x - p1.x) * 1.0);
}
int orientation(Point p, Point q, Point r) {
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

	if (val == 0)
		return 0;  // colinear
	return (val > 0) ? 1 : 2; // clock or counterclock wise
}
int compare(const void *vp1, const void *vp2) {
	Point *p1 = (Point*) vp1;
	Point *p2 = (Point*) vp2;

	int o = orientation(p0, *p1, *p2);
	if (o == 0)
		return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;

	return (o == 2) ? -1 : 1;
}
Point nextToTop(stack<Point> &S) {
	Point p = S.top();
	S.pop();
	Point res = S.top();
	S.push(p);
	return res;
}
void convexHull() {
	int ymin = points[0].y, min = 0;
	for (int i = 1; i < N; i++) {
		int y = points[i].y;
		if ((y < ymin) || ((ymin == y && points[i].x < points[min].x))) {
			ymin = points[i].y, min = i;
		}
	}
	swap(points[0], points[min]);
	p0 = points[0];
	qsort(&points[1], N - 1, sizeof(Point ), compare);
	int m = 1;
	for (int i = 1; i < N; i++) {
		while (i < N - 1 && orientation(p0, points[i], points[i + 1]) == 0)
			i++;
		points[m] = points[i];
		m++;
	}
	if (m < 3) {
		return;
	}
	stack<Point> S;
	S.push(points[0]);
	S.push(points[1]);
	S.push(points[2]);
	for (int i = 3; i < m; i++) {
		while (orientation(nextToTop(S), S.top(), points[i]) != 2)
			S.pop();
		S.push(points[i]);
	}
	while (!S.empty()) {
		polygon.push_back(Point(S.top().x, S.top().y));
		S.pop();
	}
}
void calculateSide() {
//	cout << N << " " << Q << endl;
	for (int i = 0; i < N; i++) {
		int nxt = (i + 1) % N;
//		cout << points[i].x << " " << points[i].y << "  to " << points[nxt].x
//				<< " " << points[nxt].y << endl; //"  is "
//				<< getSlope(points[i], points[nxt]) << endl;
		v.push_back(
				make_pair(getSlope(points[i], points[nxt]),
						make_pair(points[i], points[nxt])));
	}
//	cout << N << " " << Q << endl;
	sort(v.begin(), v.end());
//	cout << N << " " << Q << endl;
	double m = 1000000000, M = -1000000000;
	Point mi, Mi;
	for (int i = 0; i < N; i++) {
		double temp = points[i].y * v[0].first + points[i].x;
//		cout << points[i].x << " " << points[i].y << " with slope "
//				<< v[0].first << " : " << temp << endl;
		if (temp < m) {
			m = temp;
			mi = points[i];
		}
		if (temp > M) {
			M = temp;
			Mi = points[i];
		}
	}
//	cout << "0: " << mi.x << " " << mi.y << " and " << Mi.x << " " << Mi.y
//			<< endl;
	side[0] = { mi, Mi };
	for (int j = 1; j < v.size(); j++) {
//		double t1 = mi.second - v[j].first * mi.first;
//		double t2 = Mi.second - v[j].first * Mi.second;
//		double t3 = v[j].second.first.second
//				- v[j].first * v[j].second.first.first;
//		double t4 = v[j].second.second.second
//				- v[j].first * v[j].second.second.first;
		double t1 = mi.second * v[j].first + mi.first;
		double t2 = Mi.second * v[j].first + Mi.first;
		double t3 = v[j].second.first.second * v[j].first
				+ v[j].second.first.first;
		double t4 = v[j].second.second.second * v[j].first
				+ v[j].second.second.first;
//		cout << t1 << " " << t2 << " " << t3 << " " << t4 << endl;
		if (t3 < t1 && t3 < t2 && t3 < t4) {
			m = t3;
			mi = v[j].second.first;
		} else if (t4 < t4 && t4 < t2 && t4 < t3) {
			m = t4;
			mi = v[j].second.second;
		}

		if (t3 > t1 && t3 > t2 && t3 > t4) {
			M = t3;
			Mi = v[j].second.first;
		} else if (t4 > t4 && t4 > t2 && t4 > t3) {
			M = t4;
			Mi = v[j].second.second;
		}
		side[j] = { mi, Mi };
	}
}
int binarySearch(double slope) {
	int s = 0, b = v.size();
	while (s < b) {
		int m = (s + b) / 2;
		if (s == m) {
			break;
		}
		if (slope < v[m].first) {
			b = m - 1;
		} else {
			s = m;
		}
	}
	return s;
}
int main() {
// local variables

// fstream
	ifstream fin("3.in");
	ofstream fout("fencing.out");
// input
	fin >> N >> Q;
	for (int i = 0; i < N; i++) {
		fin >> points[i].x >> points[i].y;
	}
// main
//	cout << N << " " << Q << endl;
	convexHull();
//	cout << N << " " << Q << endl;
	calculateSide();
// output
//	cout << N << " " << Q << endl;
	for (int i = 1; i <= Q; i++) {
		int a;
		fin >> a;
		if (a == 1) {
			int b, c;
			fin >> b >> c;
			points[N++] = make_pair(b, c);
			convexHull();
			calculateSide();
		} else {
			long long A, B, C;
			fin >> A >> B >> C;
			double slope;
			if (A == 0) {
				slope = -10000000;
			} else if (B == 0) {
				slope = 0;
			} else {
				slope = 1 / (A * (1.0) / B * (1.0));
			}
//			cout << A << " " << B << " " << C << " = " << slope << endl;
			int in = binarySearch(slope);
			double A1 = A * side[in].first.x + B * side[in].first.y - C;
			double A2 = A * side[in].second.x + B * side[in].second.y - C;

//			cout << side[in].first.x << " " << side[in].first.y << endl;
//			cout << side[in].second.x << " " << side[in].second.y << endl;
			if (A1 * A2 > 0) {
				cout << "YES" << endl;
			} else
				cout << "NO" << endl;
		}
	}
	return 0;
}

```

# [hopscotch.cpp](#2)
```cpp
#include <bits/stdc++.h>
using namespace std;

// structures/defines
#define MAX 101
// global variables
struct BIT {
	int bit[MAX];
};
int N, M, K;
int grid[MAX][MAX];
BIT BITs[MAX * MAX];
int allbit[MAX];
//map<int, int> toIn;
//int toIn[564001];
//functions
int getBIT(int color, int y, int x) {
	int tx = x, ty = y;
	int sum = 0;
	for (x = tx; x > 0; x -= x & -x)
//		for (y = ty; y > 0; y -= y & -y) {
		sum = (sum + BITs[color].bit[x]) % 1000000007;
//		}
	return sum;
}
void updateBIT(int color, int y, int x, int val) {
	int tx = x, ty = y;
	for (x = tx; x <= N; x += (x & -x))
//		for (y = ty; y <= M; y += (y & -y)) {
		BITs[color].bit[x] = (BITs[color].bit[x] + val) % 1000000007;

//		}
}
int getAll(int y, int x) {
	int tx = x, ty = y;
	int sum = 0;
	for (x = tx; x > 0; x -= x & -x)
//		for (y = ty; y > 0; y -= y & -y)
		sum = (sum + allbit[x]) % 1000000007;
	return sum;
}
void updateAll(int y, int x, int val) {
	int tx = x, ty = y;
	for (x = tx; x <= N; x += (x & -x))
//		for (y = ty; y <= M; y += (y & -y))
		allbit[x] = (allbit[x] + val) % 1000000007;
}
int main() {
	// local variables

	// fstream
	ifstream fin("hopscotch.in");
	ofstream fout("hopscotch.out");
	// input
	fin >> N >> M >> K;
	int in = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			fin >> grid[i][j];
//			if (!toIn[grid[i][j]]) {
//				toIn[grid[i][j]] = in++;
//			}
//			grid[i][j] = toIn[grid[i][j]];
		}
	}
//	cout << "hi" << endl;
	for (int i = 1; i < N; i++) {
		vector<int> temp;
		for (int j = 1; j <= M; j++) {
//			cout << i << " " << j << endl;
			int a = (getAll(i - 1, j - 1) - getBIT(grid[i][j], i - 1, j - 1)
					+ 1000000007) % 1000000007;
			temp.push_back(a + (i == 1 && j == 1));
		}
		for (int j = 0; j < temp.size(); j++) {
//			cout << i << " " << j<< " " << grid[i][j+1],  << endl;
			updateBIT(grid[i][j + 1], i, j + 1, temp[j]);
			updateAll(i, j + 1, temp[j]);
		}
	}
//	cout << "hi" << endl;
	// output
	int ans = (getAll(N - 1, M - 1) - getBIT(grid[N][M], N - 1, M - 1)
			+ 1000000007) % 1000000007;
	fout << ans << endl;

	return 0;
}

```

