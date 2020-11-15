<div align="center"> <a href="#0">angry.cpp</a> | <a href="#1">lightsout.cpp</a> | <a href="#2">radio.cpp</a> </div>

# [angry.cpp](#0)
```cpp
/*
 ============================================================================
 Name        : cpp_template.cpp
 Author      : Dong Liu
 Website     : dongliu.template.com
 ============================================================================
 */
#include <algorithm>
#include <bitset>
#include <complex>
#include <cstring>
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

// declare any structures
#define ll long long
struct s2b {
	bool operator()(ll i, ll j) {
		return (i < j);
	}
} s2b;
// declare any global variables
ll N;
vector<ll> loc;
ll cleft = 1000000000, cright = 0;
// declare any functions
bool possibleFirst(ll start, ll r) {
	if (cleft < start - r) {
		long curr = loc[lower_bound(loc.begin(), loc.end(), start - r)
				- loc.begin()];
		long currRadius = r - 2;
		while (curr != cleft) {
			long next = loc[lower_bound(loc.begin(), loc.end(),
					curr - currRadius) - loc.begin()];
			if (next >= curr) {
				return false;
			}
			curr = next;
			currRadius -= 2;
		}
	}
	return true;
}
bool possibleLast(ll start, ll r) {
	if (cright > start + r) {
		long curr = loc[upper_bound(loc.begin(), loc.end(), start + r)
				- loc.begin() - 1];
		long currRadius = r - 2;
		while (curr != cright) {
			long next = loc[upper_bound(loc.begin(), loc.end(),
					curr + currRadius) - loc.begin() - 1];
			if (next <= curr) {
				return false;
			}
			curr = next;
			currRadius -= 2;
		}
	}
	return true;
}
int main() {

	// fstream
	ifstream fin("angry.in");
	ofstream fout("angry.out");

	// input
	fin >> N;
	for (int i = 0; i < N; i++) {
		int L;
		fin >> L;
		loc.push_back(2 * L);
	}
	sort(loc.begin(), loc.end(), s2b);
	cleft = loc[0];
	cright = loc[N - 1];
	// main
//	for(int i=0; i<N; i++) cout << loc[i] << endl;
//	cout << endl;
//	cout << upper_bound (loc.begin(), loc.end(), 6)-loc.begin()-1 << endl;
//	cout << lower_bound (loc.begin(), loc.end(), 20)-loc.begin()-1 << endl;
	ll min = 0;
//	cout << cleft << " " << cright << endl;
	ll max = 1000000000;
	while (min != max) {
		ll mid = (min + max) / 2;
		ll l = cleft;
		ll r = cright;
		while (l < r) {
			long m = (l + r + 1) / 2;
			if (possibleFirst(m, mid)) {
				l = m;
			} else {
				r = m - 1;
			}
		}
		if (possibleLast(l, mid)) {
//			cout << min << " " << max <<" " << mid <<" true "<<endl;
			max = mid;
		} else {
//			cout << min << " " << max <<" " << mid <<" false "<<endl;
			min = mid + 1;
		}
	}
	// output
	fout << fixed << setprecision(1) << min / 2.0 << endl;
	//close
	fout.close();
	return 0;
}

```

# [lightsout.cpp](#1)
```cpp
/*
 ID: dongliu3
 TASK: lightsout
 LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

// structures/defines
#define ll long long
#define pii pair<ll, ll>
#define x first
#define y second
#define PI 3.1415926535
#define HM 10000000007
#define HA 1000000007
#define HB 1001
// global variables
int N;
pii barn[200], nbarn[200], d[200];
ll slope[200], dist[200], rdist[200], pdist[200], angle[200];
multiset<ll> H[201];
ll ans = -1;
//functions
ll hext(ll h, ll ch) {
	return (1ll * h * HA + ch + HB) % HM;
}
int getLength(pii X, pii Y) {
	ll xDiff = X.first - Y.first;
	ll yDiff = X.second - Y.second;
	return xDiff * xDiff + yDiff * yDiff;
}
void calculateAngle(int i, pii A, pii B, pii C) {
	// Square of lengths be a2, b2, c2
	ll a2 = getLength(B, C);
	ll b2 = getLength(A, C);
	ll c2 = getLength(A, B);

	// length of sides be a, b, c
	float a = sqrt(a2);
	float b = sqrt(b2);
	float c = sqrt(c2);

	// From Cosine law
	float alpha = acos((b2 + c2 - a2) / (2 * b * c));

	// Converting to degree
	alpha = alpha * 180 / PI;

	// printing all the angles
	int na = alpha;
	if (B.x < A.x || B.y < A.y) {

		na = 360 - na;
	}
	angle[i] = (na);
//	cout << "angle[" << i << "] = " << na << "\n";
}
int main() {
//  local variables
//  fstream
	ifstream fin("lightsout.in");
	ofstream fout("lightsout.out");

//  initialize
	fin >> N;
	for (int i = 0; i < N; i++) {
		fin >> barn[i].x >> barn[i].y;
	}
	for (int i = 0; i < N; i++) {
		int pi = max(0, i - 1), ni = (i + 1) % N;
		dist[ni] = abs(barn[ni].x - barn[i].x) + abs(barn[ni].y - barn[i].y);
		d[ni] = pii(barn[ni].x - barn[i].x, barn[ni].y - barn[i].y);
		pdist[i] = pdist[pi] + dist[i];
//		cout << "dist[" << ni << "] = " << dist[ni] << endl;
	}
//	cout << pdist[0] << " pdist0" << endl;
//	for (int i = 0; i < N; i++) {
//		cout << pdist[i] << " vs " << pdist[N - 1] + dist[0] - pdist[i] << endl;
//	}
//	for (int i = 0; i < N; i++) {
//		int pi = (i + N - 1) % N, ni = (i + 1) % N;
//		calculateAngle(i, barn[i], barn[pi], barn[ni]);
//	}
	for (int i = 0; i < N; i++) {
		int last = (i - 1 + N) % N;
		int next = (i + 1) % N;
		double x1 = barn[i].x - barn[last].x;
		double y1 = barn[i].y - barn[last].y;
		double x2 = barn[next].x - barn[i].x;
		double y2 = barn[next].y - barn[i].y;
		double theta1 = atan2(y1, x1) * 180 / 3.1415926358979323;
		double theta2 = atan2(y2, x2) * 180 / 3.1415926358979323;
		angle[i] = (180 + theta1 - theta2 + 360);
		while (angle[i] > 360)
			angle[i] -= 360;
//		cout << "angle[" << i << "] = " << angle[i] << endl;
	}
//  main
	for (int i = 1; i < N; i++) {
		ll chsh = hext(0, angle[i]);
//		H.insert(chsh);
//		cout << "1hsh = " << chsh << endl;
		int sz = 0;
		for (int j = i + 1; j != i; j++) {
			j %= N;
			if (j == 0) {
				break;
			}
//			chsh = hext(chsh, dist[j]);
			chsh = hext(chsh, d[j].x);
			chsh = hext(chsh, d[j].y);
//			cout << "2hsh = " << chsh << endl;
			chsh = hext(chsh, angle[j]);
//			cout << "2hsh = " << chsh << endl;
//			cout << i << " to " << j << " = " << chsh << endl;
			H[sz].insert(chsh);
			if (j == 0) {
				break;
			}
			sz++;
		}
	}
//	for (multiset<ll>::iterator it = H.begin(); it != H.end(); ++it) {
//		cout << *it << " c: " << H.count(*it) << endl;
//	}
	for (int i = 1; i < N; i++) {
		ll cdist = 0;
		ll chsh = hext(0, angle[i]);
//		cout << "0" << endl;
		int sz = 0;

		for (int j = i + 1; j != i; j++, j %= N) {
			j %= N;
//			chsh = hext(chsh, dist[j]);
			chsh = hext(chsh, d[j].x);
			chsh = hext(chsh, d[j].y);
			chsh = hext(chsh, angle[j]);
			cdist += dist[j];
//			cout << i << " to " << j << " dist = " << cdist << endl;
//			cout << "cdist: " << cdist << " hsh: " << chsh << endl;
			if (H[sz].count(chsh) <= 1 || j == 0) {
//				if (j == 0) {
//					cout << "hi" << endl;
//				}
				ll odist = min(pdist[i], pdist[N - 1] + dist[0] - pdist[i]);
				cdist = min(cdist + pdist[j],
						cdist + pdist[N - 1] + dist[0] - pdist[j]);
//				cout << i << " to " << j << endl;
//				cout << cdist << " vs " << odist << endl;
				ans = max(ans, cdist - odist);
//				cout << i << " " << j << " " << ans << " " << cdist - odist
//						<< endl;
				break;
			}
			if (j == 0) {
				break;
			}
			sz++;
		}
	}
//  output
	fout << ans << endl;
	return 0;
}

```

# [radio.cpp](#2)
```cpp
/*
 ID: dongliu3
 TASK: radio
 LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

// structures/defines
#define Pair pair<int, int>
#define x first
#define y second

// global variables
int N, M;
Pair f, b;
string sF, sB;
int dp[1001][1001];
Pair pF[1001], pB[1001];
map<char, int> X, Y;

//functions
int sq(int i) {
	return i * i;
}
int getDist(int F, int B) {
//	cout <<"dist btwn: "<<F<<" and "<<B<<" is "<<sq(abs(pF[F].x - pB[B].x)) + sq(abs(pF[F].y - pB[B].y))<<endl;
	return sq(abs(pF[F].x - pB[B].x)) + sq(abs(pF[F].y - pB[B].y));
}
int main() {
// local variables

// fstream
	ifstream fin("radio.in");
	ofstream fout("radio.out");

// input
	fin >> N >> M;
	fin >> f.x >> f.y >> b.x >> b.y;
	fin >> sF >> sB;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			dp[i][j] = 1000000000;
		}
	}

	X['N'] = 0, Y['N'] = 1;
	X['S'] = 0, Y['S'] = -1;
	X['E'] = 1, Y['E'] = 0;
	X['W'] = -1, Y['W'] = 0;
	pF[0] = f, pB[0] = b;
	for (int i = 1; i <= N; i++) {
		pF[i].x = X[sF[i - 1]] + pF[i - 1].x;
		pF[i].y = Y[sF[i - 1]] + pF[i - 1].y;
	}
	for (int i = 1; i <= M; i++) {
		pB[i].x = X[sB[i - 1]] + pB[i - 1].x;
		pB[i].y = Y[sB[i - 1]] + pB[i - 1].y;
//		cout << pB[i].x << " " << pB[i].y << endl;
	}
// main
	dp[0][0] = 0;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
//			cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
			if (i + 1 <= N) {
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + getDist(i + 1, j));
			}
			if (j + 1 <= M) {
				dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + getDist(i, j + 1));
			}
			if (i + 1 <= N && j + 1 <= M) {
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1],
						dp[i][j] + getDist(i + 1, j + 1));
			}
		}
	}
// output
	fout << dp[N][M] << endl;
	return 0;
}

```

