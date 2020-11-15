# water
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
struct node {
	int i, weight;
	node(int i, int weight) : i(i), weight(weight) {}
};
struct comp{
    bool operator()(const node& a, const node& b) {
    	return a.weight>b.weight;
    }
};
// global variables
int N;
int W[304];
bool visited[304];
int P[304][304];
// functions

int main() {
	// local variables

	// input
	cin >> N;
	for(int i=1; i<=N; i++) cin >> W[i];
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			cin >> P[i][j];
		}
	}
	// main
	priority_queue<node, vector<node>, comp> Q;
	for(int i=1; i<=N; i++) {
		Q.push(node(i, W[i]));
		visited[i] = false;
	}
	long long ans = 0;
	while(!Q.empty()) {
		int i = Q.top().i;
		int weight = Q.top().weight;
		Q.pop();
		if(!visited[i]) {
			ans += weight; visited[i] = true;
			for(int j=1; j<=N; j++){
				if(!visited[j]) {
					Q.push(node(j, P[i][j]));
				}
			}
		}
	}
	// output
	cout << ans << endl;
	return 0;
}

```