# split
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
#define Pair pair<long long, long long>
#define x first
#define y second
struct s2bx {
  bool operator() (Pair i,Pair j) { return (i.x<j.x); }
} s2bx;
struct s2by {
  bool operator() (Pair i,Pair j) { return (i.y<j.y); }
} s2by;

// global variables
int N;
vector<Pair> cow;
Pair mininum, maxinum;
multiset<long long> small, big;
multiset<long long> up, down, left1, right1;
// functions

int main() {
	// local variables

	// input
	cin >> N;
	mininum.x = mininum.y = 1000000001;
	maxinum.x = maxinum.y = 0;
	for(int i=0; i<N; i++) {
		long long a,b; cin >> a >> b;
		mininum.x = min(mininum.x, a);
		mininum.y = min(mininum.y, b);
		maxinum.x = max(maxinum.x, a);
		maxinum.y = max(maxinum.y, b);
		cow.push_back(Pair(a,b));
	}
	long long oneEnclosure = (maxinum.x-mininum.x)*(maxinum.y-mininum.y);
	long long twoEnclosure = oneEnclosure;

	// main
	sort(cow.begin(), cow.end(), s2bx);
	for(int i=0; i<N; i++) {

		right1.insert(cow[i].x);
		up.insert(cow[i].y);
	}
	for(int i=0; i<N-1; i++) {
		right1.erase(right1.find(cow[i].x));
		up.erase(up.find(cow[i].y));
		left1.insert(cow[i].x);
		down.insert(cow[i].y);
		twoEnclosure = min(twoEnclosure,(long long)(*up.rbegin()-*up.begin())*(long long)(*right1.rbegin()-*right1.begin())
				+(*down.rbegin()-*down.begin())*(long long)(*left1.rbegin()-*left1.begin()));
	}
	left1.clear(); right1.clear(); down.clear(); up.clear();

	sort(cow.begin(), cow.end(), s2by);
	for(int i=0; i<N; i++) {
		right1.insert(cow[i].x);
		up.insert(cow[i].y);
	}
	for(int i=0; i<N-1; i++) {
		right1.erase(right1.find(cow[i].x));
		up.erase(up.find(cow[i].y));
		left1.insert(cow[i].x);
		down.insert(cow[i].y);
		twoEnclosure = min(twoEnclosure,(long long)(*up.rbegin()-*up.begin())*(long long)(*right1.rbegin()-*right1.begin())
						+(*down.rbegin()-*down.begin())*(long long)(*left1.rbegin()-*left1.begin()));
	}
	// output
	cout << (oneEnclosure-twoEnclosure) << endl;
	return 0;
}

```