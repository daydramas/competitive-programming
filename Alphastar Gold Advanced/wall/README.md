# wall
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
struct s2b {
  bool operator() (Pair i,Pair j) { return (i.second<j.second);}
} s2b;
// global variables
int H, F;
vector<Pair> hoofHold;
queue<Pair> Q;
bool visited[10004];
// functions
int sq(int a) { return a*a; }
int main() {
	// local variables

	// input
	cin >> H >> F;
	for(int i=0; i<F; i++) {
		int x, y; cin >> x >> y;
		hoofHold.push_back(Pair(x, y));
		visited[i] = false;
	}
	sort(hoofHold.begin(), hoofHold.end(), s2b);
	for(int i=0; i<F; i++) {
		if(hoofHold[i].second <= 1000) { Q.push(Pair(i, 1)); visited[i] = true; }
		else break;
	}
	// main
	int ans = 0;
	while(!Q.empty()) {
		int hold=Q.front().first, moves=Q.front().second;
		Q.pop();

		if(hoofHold[hold].second >= H-1000) { ans = moves; break; }

		int minI = hold;
		while((minI != 0) && (abs(hoofHold[minI-1].second-hoofHold[hold].second) <= 1000)) {
			minI--;
		}

		int maxI = hold;
		while((maxI != F-1) && (abs(hoofHold[maxI+1].second-hoofHold[hold].second) <= 1000)) {
			maxI++;
		}

		for(int i=minI; i<=maxI; i++) {
			if(sq(abs(hoofHold[i].first-hoofHold[hold].first))+
				sq(abs(hoofHold[i].second-hoofHold[hold].second))
					<= 1000000) {
				if(!visited[i]) {
					visited[i] = true;
					Q.push(Pair(i, moves+1));
				}
			}
		}
	}
	cout << ans << endl;
	// output

	return 0;
}

```