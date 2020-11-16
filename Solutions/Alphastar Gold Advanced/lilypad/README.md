# lilypad
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
#define Pair pair<long long, long long>
#define x1 first
#define y1 second
// global variables
long long N, M;
long long pond[40][40];
long long adj[40][40][40][40];
Pair Start, End;
long long dist[40][40], ways[40][40];
long long X[8] = {-2,-1,+1,+2,+2,+1,-1,-2};
long long Y[8] = {-1,-2,-2,-1,+1,+2,+2,+1};
// functions

int main() {
	// local variables

	// input
	cin >> N >> M;
	for(long long i=1; i<=N; i++) {
		for(long long j=1; j<=M; j++) {
			cin >> pond[i][j];
			dist[i][j] = -1;
			ways[i][j] = 0;
			if (pond[i][j] == 3) {
				Start = Pair(i, j);
				pond[i][j] = 0;
			} else if (pond[i][j] == 4) {
				End = Pair(i, j);
				pond[i][j] = 0;
			}
		}
	}
	// main
	for(long long i=1; i<=N; i++) {
		for(long long j=1; j<=M; j++) {
			if(pond[i][j] == 0) {
				queue<Pair> Q;
				Q.push(Pair(i,j));
			    adj[i][j][i][j] = 1;
			    while(!Q.empty()) {
			    	long long x=Q.front().x1;
			    	long long y=Q.front().y1;
			    	Q.pop();
			    	for (long long k=0; k<8; k++) {
			    		long long nx = x+X[k];
			    		long long ny = y+Y[k];
						if (nx >= 1 && nx <= N && ny>=1 && ny<=M && pond[nx][ny]==1 && adj[i][j][nx][ny] == 0) {
							Q.push(Pair(nx, ny));
							adj[i][j][nx][ny] = 1;
						}
			    	}
			    }
			    for(long long x=1; x<=N; x++) {
			    	for(long long y=1; y<=M; y++) {
			    		if(adj[i][j][x][y] == 1) {
							for(long long k=0; k<8; k++) {
								long long nx = x+X[k];
								long long ny = y+Y[k];
								if(nx >= 1 && nx <= N && ny>=1 && ny<=M && pond[nx][ny]==0 && adj[i][j][nx][ny] == 0) {
									adj[i][j][nx][ny] = 2;
								}
							}
			    		}
			    	}
			    }
			}
		}
	}
	dist[Start.x1][Start.y1] = 0;
	ways[Start.x1][Start.y1] = 1;
	queue<Pair> Q;
	Q.push(Pair(Start.x1,Start.y1));
	while (!Q.empty()) {
		long long x=Q.front().x1;
		long long y=Q.front().y1;
		Q.pop();

//		cout << x << " " << y << " d: " << dist[x][y] << endl;
		for(long long i=1; i<=N; i++) {
			for(long long j=1; j<=M; j++) {
				if(adj[x][y][i][j] == 2) {
					if(dist[i][j] == -1) {
						dist[i][j] = dist[x][y]+1;
						ways[i][j] = ways[x][y];
						Q.push(Pair(i, j));
					} else if(dist[i][j] == dist[x][y]+1) {
						ways[i][j] += ways[x][y];
					}
				}
			}
		}
	}
	if (dist[End.x1][End.y1]==-1) cout << "-1" << endl;
	else cout << dist[End.x1][End.y1]-1<<endl<<ways[End.x1][End.y1]<<endl;
	return 0;
}

```