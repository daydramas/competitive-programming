# bobsled
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
#define Pair pair<int, int>
#define loc first
#define maxS second

// global variables
int L, N;
vector<Pair> maxSpeed;
int slowDown[100004];
int speedUp[100004];
// functions
 int max2(int s1, int s2, int dist) {
  return max(s1,s2)+int((dist-abs(s1-s2))/2);
}
int main() {
	// local variables

	// input
	cin >> L >> N;
	for(int i=1; i<=N; i++) {
		int a,b; cin >> a >> b;
		maxSpeed.push_back(Pair(a,b));
	}
	N++; N++;
	maxSpeed.push_back(Pair(0,1));
	maxSpeed.push_back(Pair(L,1000000000));
	sort(maxSpeed.begin(), maxSpeed.end());

	// main
	slowDown[N-1] = maxSpeed[N-1].maxS;
	for (int i=N-2; i>=0; i--) {
		slowDown[i] = min(slowDown[i+1]+(maxSpeed[i+1].loc-maxSpeed[i].loc),maxSpeed[i].maxS);
	}
	int ans = 1;
	speedUp[0] = maxSpeed[0].maxS;
	for (int i=1; i<N; i++) {
	  speedUp[i] = min(speedUp[i-1] + (maxSpeed[i].loc-maxSpeed[i-1].loc),slowDown[i]);
	}
	for(int i=1; i<N; i++) {
		ans = max(ans,max2(speedUp[i-1],speedUp[i],maxSpeed[i].loc-maxSpeed[i-1].loc));
	}
	// output
	cout << ans << endl;
	return 0;
}

```