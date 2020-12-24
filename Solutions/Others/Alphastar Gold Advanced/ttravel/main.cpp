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
char q; int k;
int parent[80001];
int ans[80001];
// functions

int main() {
	// local variables

	// input
	cin >> N; parent[0]=ans[0]=-1;
	for(int i=1; i<=N; i++) {
		cin >> q;
		switch(q) {
			case 'a':
				cin >> k;
				parent[i] = i-1;
				ans[i] = k;
				break;
			case 's':
				parent[i]=parent[parent[i-1]];
				ans[i]=ans[parent[i-1]];
				break;
			case 't':
				cin >> k;
				parent[i]=parent[k-1];
				ans[i] = ans[k-1];
				break;
		}
		cout << ans[i] << endl;
	}
	// main

	// output

	return 0;
}
