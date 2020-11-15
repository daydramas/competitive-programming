# rblock
```cpp
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
// structures / defines

// global variables
int N, M;
int edge[105][105];
int dist[105]; bool visited[105];
map<int, int> parent;
// functions
int shortestPath(bool P) {
	memset(dist, -1, sizeof(int)*(N+1));
	memset(visited, false, sizeof(bool)*(N+1));
	dist[1] = 0;

	while(true) {
		int k = -1;
		for(int i=1; i<=N; i++) {
			if(dist[i]!=-1 && !visited[i] && (k==-1 || dist[i]<dist[k])){
				k = i;
			}
		}
		if(k == -1) break;
		visited[k] = true;
		for(int i=1; i<=N; i++){
			if(edge[k][i] == 0) continue;
			int go = i;
			int ndist = dist[k] + edge[k][i];
			if(dist[go] == -1 || ndist < dist[go]){
				if(P) parent[go] = k;
				dist[go] = ndist;
			}
		}
	}
	return dist[N];
}
int main() {
	// local variables

	// input
	cin >> N >> M;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) edge[i][j] = 0;
	}
	for(int i=1; i<=M; i++) {
		int x, y, weight; cin >> x >> y >> weight;
		edge[x][y] = edge[y][x] = weight;
	}
	// main
	int preAns = shortestPath(true);
	int b = N;
	int c = 0;
	int ans = 0;
	while(true) {
		c = parent[b];
		if (c == 0) break;

		edge[b][c] *= 2;
		edge[c][b] *= 2;
		ans = max(ans, shortestPath(false)-preAns);
		edge[b][c] /= 2;
		edge[c][b] /= 2;

		b = c;
	}
	// output
	cout << ans << endl;
	return 0;
}

```