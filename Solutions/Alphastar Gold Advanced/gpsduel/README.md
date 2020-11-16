# gpsduel
```cpp
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

// structures / defines
struct edge {
	int dest, dist;
	edge(int dest, int dist) : dest(dest), dist(dist) {}
};
#define Pair pair<int, int>
// global variables
int N, M;
vector<edge> adj1[10004], adj2[10004], adj3[10004];
int dist1[10004], dist2[10004], dist3[10004];
// functions
void spath1() {
	dist1[N] = 0;
	priority_queue<Pair, vector<Pair>, greater<Pair> > Q;
	Q.push(Pair(0, N));
	while(!Q.empty()) {
		int i=Q.top().second, d=Q.top().first; Q.pop();
		if(d>dist1[i]) continue;
		for(int j=0; j<adj1[i].size(); j++) {
			if(d+adj1[i][j].dist < dist1[adj1[i][j].dest]) {
				dist1[adj1[i][j].dest] = d+adj1[i][j].dist;
				Q.push(Pair(d+adj1[i][j].dist, adj1[i][j].dest));
			}
		}
	}
}
void spath2() {
	dist2[N] = 0;
	priority_queue<Pair, vector<Pair>, greater<Pair> > Q;
	Q.push(Pair(0, N));
	while(!Q.empty()) {
		int i=Q.top().second, d=Q.top().first; Q.pop();
		if(d>dist2[i]) continue;
		for(int j=0; j<adj2[i].size(); j++) {
			if(d+adj2[i][j].dist < dist2[adj2[i][j].dest]) {
				dist2[adj2[i][j].dest] = d+adj2[i][j].dist;
				Q.push(Pair(d+adj2[i][j].dist, adj2[i][j].dest));
			}
		}
	}
}
void spath3() {
	dist3[1] = 0;
	priority_queue<Pair, vector<Pair>, greater<Pair> > Q;
	Q.push(Pair(0, 1));
	while(!Q.empty()) {
		int i=Q.top().second, d=Q.top().first; Q.pop();
		if(d>dist3[i]) continue;
//		cout << i <<" "<< d << endl;
		for(int j=0; j<adj3[i].size(); j++) {
//			cout << "hi" << endl;
			if(d+adj3[i][j].dist < dist3[adj3[i][j].dest]) {
				dist3[adj3[i][j].dest] = d+adj3[i][j].dist;
				Q.push(Pair(d+adj3[i][j].dist, adj3[i][j].dest));
			}
		}
	}
}
int main() {
	// local variables

	// input
	cin >> N >> M;
	for(int i=1; i<=M; i++) {
		int a,b,p,q; cin >> a >> b >> p >> q;
		adj1[b].push_back(edge(a, p));
		adj2[b].push_back(edge(a, q));
	}
	for(int i=1; i<=N; i++) {
		dist1[i]=dist2[i]=dist3[i]=1000000000;
	}
	// main
	spath1(); spath2();
	for(int i=1; i<=N; i++) {
		for(int j=0; j<adj1[i].size(); j++) {
			int cnt=0, go=adj1[i][j].dest;
			if(dist1[go]-dist1[i] != adj1[i][j].dist) cnt++;
			if(dist2[go]-dist2[i] != adj2[i][j].dist) cnt++;
			adj3[go].push_back(edge(i, cnt));
		}
	}
	// output
	spath3(); cout << dist3[N] << endl;
	return 0;
}

```