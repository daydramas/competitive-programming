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
#define X first
#define Y second
// global variables
int N; int W;
Pair change[50004];
// functions

int main() {
	// local variables

	// input
	cin >> N >> W;
	for(int i=1; i<=N; i++) {
		cin >> change[i].X >> change[i].Y;
	}
	stack<int> S;
	S.push(0); int in=1;
	int ans = 0;
	while(in<=N && !S.empty()) {
		if(change[in].Y > S.top()) {
			S.push(change[in].Y);
			ans++; in++;
		} else if (change[in].Y < S.top()) {
			while(true) {
				S.pop();
				if(S.empty()) break;
				if(S.top() <= change[in].Y) break;
			}
			if(S.empty()) break;
			if(S.top() < change[in].Y) {
				S.push(change[in].Y);	ans++;
			}
			in++;
//			}

		} else S.pop();
	}
	// main
	cout << ans << endl;
	// output

	return 0;
}
