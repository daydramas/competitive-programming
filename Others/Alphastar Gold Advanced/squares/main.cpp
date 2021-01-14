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
#define x first
#define y second
struct rec {
	Pair x1, y1; int in;
	rec(Pair x1, Pair y1, int in) : x1(x1), y1(y1), in(in) {}
};
struct s2b {
  bool operator() (rec i,rec j) { return (i.x1.x<j.x1.x);}
} s2b;
// global variables
int N, K;
vector<rec> rectangle;

// functions
int overlappingArea(Pair l1, Pair r1, Pair l2, Pair r2) {
    int area1 = abs(l1.x - r1.x) * abs(l1.y - r1.y);
    int area2 = abs(l2.x - r2.x) * abs(l2.y - r2.y);
    int areaI = (min(r1.x, r2.x) - max(l1.x, l2.x)) *
                (min(r1.y, r2.y) - max(l1.y, l2.y));

    return (areaI);
}
bool doOverlap(Pair l1, Pair r1, Pair l2, Pair r2) {
	swap(l1.y,r1.y); swap(l2.y,r2.y);
    if (l1.x > r2.x || l2.x > r1.x) return false;
    if (l1.y < r2.y || l2.y < r1.y) return false;
    return true;
}
int main() {
	// local variables

	// input
	cin >> N >> K;
	K = K / 2;
	for(int i=0; i<N; i++) {
		int x,y; cin >> x >> y;
		rectangle.push_back(rec(Pair(x-K, y-K), Pair(x+K, y+K), i+1));
	}
	sort(rectangle.begin(), rectangle.end(), s2b);

	// main
	int ans = 0;

	for(int i=0; i<N; i++) {
		for(int j=i+1; j<N; j++) {
			if(rectangle[i].y1.x <= rectangle[j].x1.x) break;

			if(doOverlap(rectangle[i].x1, rectangle[i].y1, rectangle[j].x1, rectangle[j].y1)){
				int temp = overlappingArea(rectangle[i].x1, rectangle[i].y1, rectangle[j].x1, rectangle[j].y1);
				if (ans != 0 && temp != 0) {
					cout << "-1" << endl;
					return 0;
				}
				if(temp!=0)ans = temp;
			}
		}
	}
	// output
	cout << ans << endl;
	return 0;
}
