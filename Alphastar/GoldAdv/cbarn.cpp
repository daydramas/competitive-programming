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
int n;
int cows[100004];
int X = 0;
// functions

int main() {
	// local variables

	// main
	cin >> n;
	for(int i=0; i<n; i++) cin >> cows[i];
    for(int i=0; i<n; i++){
        X = max(X-1+cows[i], 0);
    }
    for(int i=0; i<n; i++) {
        if (X == 0) {
            rotate(cows, cows + i, cows + n);
            break;
        }
        X = max(X-1+cows[i], 0);
    }

    long long ans = 0;
    queue<int> q;
    for(int i=0; i<n; i++) {
        for(int j=0; j<cows[i]; j++) q.push(i);
        int f = q.front(); q.pop();
        ans += (i-f)*(i-f);
    }

    cout << ans << endl;
	// output

	return 0;
}
