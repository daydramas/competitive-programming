# sparty
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

// global variables
int N, M, X;
int edge[1004][1004];
bool visited[1004];
int dist[1004], dist2[1004];
int ans = 0;
// functions
void shortestPath() {
	for(int i=1; i<=N; i++) {
		visited[i]=false;
		dist[i]=-1;
	}
	dist[X] = 0;
	while(true) {
		int k=-1;
		for(int i=1; i<=N; i++) {
			if(dist[i]!=-1 && !visited[i] && (k==-1 || dist[k]>dist[i])) {
				k=i;
			}
		}
		if(k==-1) break;
		visited[k]=true;
		for(int i=1; i<=N; i++) {
			if(edge[k][i] == 0) continue;
			int ndist = dist[k]+edge[k][i];
			if((dist[i]==-1 || dist[i]>ndist)) {
				dist[i] = ndist;
			}
		}
	}
}
void shortestPath2() {
	for(int i=1; i<=N; i++) {
		visited[i]=false;
		dist2[i]=-1;
	}
	dist2[X] = 0;
	while(true) {
		int k=-1;
		for(int i=1; i<=N; i++) {
			if(dist2[i]!=-1 && !visited[i] && (k==-1 || dist2[k]>dist2[i])) {
				k=i;
			}
		}
		if(k==-1) break;
		visited[k]=true;

		for(int i=1; i<=N; i++) {
			if(edge[i][k]==0) continue;
			int ndist = dist2[k] +edge[i][k];
			if((dist2[i]==-1 || dist2[i]>ndist)) {
				dist2[i]=ndist;
			}
		}
	}
}
int main() {
	// local variables

	// input
	cin >> N >> M >> X;
	for(int i=1; i<=M; i++) {
		int a, b, d; cin >> a >> b >> d;
		edge[a][b] = d;
	}
	// main
	shortestPath();
	shortestPath2();
	// output
	for(int i=1; i<=N; i++) ans = max(ans, dist[i]+dist2[i]);
	cout << ans << endl;
	return 0;
}

```