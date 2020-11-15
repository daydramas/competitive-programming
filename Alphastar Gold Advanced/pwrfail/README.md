# pwrfail
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
#include <math.h>
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
#define Pair pair<int, int>
#define x first
#define y second
// global variables
int N; int W; double M;
Pair l[1004];
double edge[1004][1004];
bool visited[1004];
double dist[1004];
// functions
double sq(double a) {return a*a;}
int main() {
	// local variables

	// input
	cin >> N >> W >> M;
	for(int i=1; i<=N; i++) {
		cin >> l[i].x >> l[i].y;
		visited[i] = false; dist[i] = -1.0;
	}
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			double dist = sqrt(sq(abs(l[i].x-l[j].x))+sq(abs(l[i].y-l[j].y)));
			if (dist<M) {
				edge[i][j] = dist;
			} else edge[i][j] = -1;
		}
	}
	for(int i=1; i<=W; i++) {
		int x,y; cin >> x >> y;
		edge[x][y]=edge[y][x]= 0;
	}
	// main
	dist[1] = 0.0;
	while(true) {
		int k = -1;
		for(int i=1; i<=N; i++) {
			if(dist[i]!=-1 && !visited[i] && (k==-1 || dist[k]>dist[i])) {
				k=i;
			}
		}
		if(k == -1) break;
		visited[k] = true;
		for(int i=1; i<=N; i++) {
			if(edge[i][k] == -1) continue;
			double ndist = dist[k]+edge[k][i];
			if(dist[i]==-1 || dist[i]>ndist) {
				dist[i] = ndist;
			}
		}
	}
	// output
	if(dist[N] == -1) cout <<"-1"<<endl;
	else {double final = dist[N];
	int f = dist[N]*1000;
	cout << f << endl;}
	return 0;
}

```