# jobhunt
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
// global variables
int D, P, C, F, S;
vector<edge> edges[224];
int dist[224];

// functions

int main() {
	// local variables

	// input
	cin >> D >> P >> C >> F >> S;
	for(int i=1; i<=P; i++) {
		int a, b; cin >> a >> b;
		edges[a].push_back(edge(b, -D));
	}
	for(int i=1; i<=C; i++) {
		dist[i] = 1000000000;
	}
	for(int i=1; i<=F; i++) {
		int a, b, d; cin >> a >> b >> d;
		edges[a].push_back(edge(b, d-D));
	}
	// main
    dist[S] = 0;
    bool NotnegativeCycle = true;
    for	(int i=1; i<=C; i++) {
    	NotnegativeCycle = true;
        for (int u=1; u<=C; u++) {
            for (int j=0; j<edges[u].size(); j++) {
                int v = edges[u][j].dest;
                int c = edges[u][j].dist;
                if(dist[u]+c < dist[v]) {
                	NotnegativeCycle = false;
                    dist[v] = dist[u]+c;
                }
            }
        }
    }
	// output
    if(!NotnegativeCycle) cout<<"-1"<<endl;
    else {
    	int ans = 1000000000;
    	for(int i=1; i<=C; i++) {
    		ans = min(ans, dist[i]);
    	}
    	cout << D-ans << endl;
    }

	return 0;
}

```