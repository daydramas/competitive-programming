/*
 ID: dongliu3
 TASK: change
 LANG: C++
 */

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

// structures/defines

// global variables
int N;
vector<int> pile[100005];
//vector<vector<int> > pile;
//functions
int main() {
	// local variables

	// fstream
	ifstream fin("dishes.in");
	ofstream fout("dishes.out");

	// input
	fin >> N;
	int lRemove = 0;
	int ans = N;
	int piles = 0;
	for (int i = 1; i <= N; i++) {
		int d;
		fin >> d;
		if (d < lRemove) {
			ans = i - 1;
			break;
		}
		int j = 0;
		for (; j < piles; j++) {
			if (d < pile[j].front()) {
				while (!pile[j].empty() && (d > pile[j].back())) {
					lRemove = max(lRemove, pile[j].back());
					pile[j].pop_back();
				}
				break;
			}
		}
		if (j == piles) {
			pile[piles].push_back(d);
			piles++;
		} else {
			pile[j].push_back(d);
		}

	}
	// output
	fout << ans << endl;
	return 0;
}
