# alliance
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
#define Pair pair<int, int>
// global variables
int N, M;
vector<int> edge[100010];
bool visited[100010];
// functions
Pair dfs(int x) {
  if(visited[x]) return make_pair(0, 0);
  visited[x] = true;

  Pair rVal(1, edge[x].size());
  for(int i=0; i<edge[x].size(); i++) {
    Pair nVal = dfs(edge[x][i]);
    rVal.first += nVal.first;
    rVal.second += nVal.second;
  }
  return rVal;
}
int main() {
	// local variables

	// input
	cin >> N >> M;
	for(int i=1; i<=M; i++){
		int x, y; cin >> x >> y;
		visited[i] = false;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	// main
	long long ans = 1;
	for(int i=1; i<=N; i++) {
		if(visited[i] || edge[i].size()==0) continue;

		Pair p = dfs(i);
		p.second /= 2;
		if (p.first == p.second) {
			ans *= 2;
		} else if (p.first == p.second+1) {
			ans *= p.first;
		}
		ans %= 1000000007;
	}
	// output
	cout << ans << endl;
	return 0;
}

```