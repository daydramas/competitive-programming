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
  bool operator() (Pair i, Pair j) { return (i.first<j.first);}
} s2b;
struct comp {
  bool operator() (const Pair& lhs, const Pair& rhs) const
  {return lhs.first<rhs.first;}
};
// global variables
int N, D;
vector<Pair> cow;

// functions

int main() {
	// local variables

	// input
	cin >> N >> D;
	for(int i=1; i<=N; i++) {
		int x,h; cin >> x >> h;
		cow.push_back(Pair(x,h));
	}
	sort(cow.begin(), cow.end(), s2b);

	// main

	  int result = 0;
	  multiset<int> X, Y;
	  int j = 0, k = 0;
	  for(int i = 0; i < N; i++) {
	    while(k < N && cow[k].first <= cow[i].first + D) {
	      Y.insert(cow[k++].second);
	    }
	    while(cow[j].first + D < cow[i].first) {
	      X.erase(X.find(cow[j++].second));
	    }
	    X.insert(cow[i].second);

	    if (*X.rbegin() >= 2 * cow[i].second && *Y.rbegin() >= 2 * cow[i].second) {
	      result++;
	    }

	    Y.erase(Y.find(cow[i].second));
	  }

	  cout << result << endl;
	// output
	return 0;
}



/*
 * 3 6
 * 5 3
 * 6 2
 * 9 7
 * 10 3
 * 11 2
 */
