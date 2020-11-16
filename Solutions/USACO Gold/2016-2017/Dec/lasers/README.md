# lasers
```cpp
/*
 ID: dongliu3
 TASK: change
 LANG: C++
 */

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
#define MAX (int)1e5+5
#define pii pair<int, int>
struct post {
	int x, y, in;
};
struct sbx {
	bool operator()(post i, post j) {
		return (i.x < j.x);
	}
} sbx;
struct sby {
	bool operator()(post i, post j) {
		return (i.y < j.y);
	}
} sby;

int N;
post postx[MAX], posty[MAX];
bool visited[MAX];
int dist[MAX];
pii I[MAX];
//functions
int main() {
	// local variables

	// fstream
	ifstream fin("lasers.in");
	ofstream fout("lasers.out");
	// input
	fin >> N;
	fin >> postx[0].x >> postx[0].y >> postx[N + 1].x >> postx[N + 1].y;
	postx[0].in = 0, postx[N + 1].in = N + 1;
	posty[0] = postx[0], posty[N + 1] = postx[N + 1];
	visited[0] = visited[N + 1] = false;
	for (int i = 1; i <= N; i++) {
		fin >> postx[i].x >> postx[i].y;
		postx[i].in = i;
		posty[i] = postx[i];
		visited[i] = false;
	}
	// main
	sort(postx, postx + N + 2, sbx);
	sort(posty, posty + N + 2, sby);
	for (int i = 0; i < N + 2; i++) {
		I[postx[i].in].first = i;
		I[posty[i].in].second = i;
	}
	queue<pii> Q;
	Q.push(make_pair(0, 0));
	visited[0] = true;
	int ans = -1;
	while (!Q.empty()) {
		int s = Q.front().first;
		int d = Q.front().second;
		Q.pop();
		if (s == N + 1) {
			ans = dist[s] - 1;
			break;
		}
		int i, j;
		//x
		if (d == 0 || d == 1) {
			i = I[s].first, j = I[s].first;
			while (i >= 0 && postx[I[s].first].x == postx[i].x) {
				int i2 = postx[i].in;
				if (!visited[i2]) {
					Q.push(make_pair(i2, 2));
					dist[i2] = dist[s] + 1;
					visited[i2] = true;
				}
				i--;
			}
			while (j <= N + 1 && postx[I[s].first].x == postx[j].x) {
				int i2 = postx[j].in;
				if (!visited[i2]) {
					Q.push(make_pair(i2, 2));
					dist[i2] = dist[s] + 1;
					visited[i2] = true;
				}
				j++;
			}
		}
		//y
		if (d == 0 || d == 2) {
			i = I[s].second, j = I[s].second;
			while (i >= 0 && posty[I[s].second].y == posty[i].y) {
				int i2 = posty[i].in;
				if (!visited[i2]) {
					Q.push(make_pair(i2, 1));
					dist[i2] = dist[s] + 1;
					visited[i2] = true;
				}
				i--;
			}
			while (j <= N + 1 && posty[I[s].second].y == posty[j].y) {
				int i2 = posty[j].in;
				if (!visited[i2]) {
					Q.push(make_pair(i2, 1));
					dist[i2] = dist[s] + 1;
					visited[i2] = true;
				}
				j++;
			}
		}

	}
	// output
	fout << ans << endl;
	return 0;
}

```