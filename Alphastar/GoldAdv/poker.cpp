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

// global variables
int N;
int card[100004];
// functions

int main() {
	// local variables

	// input
	cin >> N;
	card[0] = 0, card[N+1] = 0;
	for(int i=1; i<=N; i++) cin >> card[i];
	long long ans = 0;
	for(int i=0; i<=N; i++) {
		ans += abs((long long) card[i+1]-card[i]);
	}
	// main
	cout << ans/2 << endl;
	// output

	return 0;
}
