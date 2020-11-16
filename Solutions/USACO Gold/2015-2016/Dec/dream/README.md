# dream
```cpp
/*
============================================================================
 Name        : cpp_template.cpp
 Author      : Dong Liu
 Website     : dongliu.template.com
============================================================================
*/
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

// declare any structures
#define int_max 2147483640
struct point{
	int x, y; int px, py; int move; bool orange;
	point(int x, int y, int px, int py, int move, bool orange) : x(x), y(y), px(px), py(py), move(move), orange(orange) {}
};
// declare any global variables
int N, M, grid[1010][1010];
// declare any functions
int main() {

	// fstream
	ifstream fin ("dream.in");
	ofstream fout ("dream.out");

	// input
	fin >> N >> M;
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) fin >> grid[i][j];

	// main
	int ans = -1;
	queue<point> solver;

	solver.push(point(1, 1, -1, -1, 0, false));
	while(!solver.empty()){
		int i=solver.front().x;
		int j=solver.front().y;
		int pi=solver.front().px;
		int pj=solver.front().py;
		int move=solver.front().move;
		bool orange=solver.front().orange;
		solver.pop();

	}
	// output

	//close
	fout.close();
	return 0;
}

```