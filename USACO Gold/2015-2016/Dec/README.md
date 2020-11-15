<div align="center"> <a href="#0">cardgame.cpp</a> | <a href="#1">dream.cpp</a> | <a href="#2">feast.cpp</a> </div>

# [cardgame.cpp](#0)
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
// declare any global variables
int N, E[50001], B[50001], M[50001*2];
int ans = 0;
// declare any functions
int main() {

	// fstream
	ifstream fin ("cardgame.in");
	ofstream fout("cardgame.out");
	// input
	fin >> N;
	for(int i=0; i<N; i++){
		fin >> E[i];
		M[E[i]] = 1;
	}
	for (int i=1,j=0; i<=2*N; i++) if (!M[i]) B[j++]=i;
	sort(B,B+N); sort(E,E+N/2); sort(E+N/2,E+N);

	// main

	for (int i=(N+1)/2; i<N; i++) if (B[i]>E[ans]) ans++;
	for (int i=N/2,j=0; i<N; i++) if (E[i]>B[j]) ans++,j++;

	fout << ans << endl;

	// output

	//close
	fout.close();
	return 0;
}

```

# [dream.cpp](#1)
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

# [feast.cpp](#2)
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

// declare any global variables
int T, A, B;
bool dp[2][5000001];

// declare any functions
void add(){
	for(int j=0; j<2; j++){
		for(int i=0; i<=T; i++){
			if(i+A <= T){
				dp[j][i+A] = dp[j][i+A]||dp[j][i];
			}
			if(i+B <= T){
				dp[j][i+B] = dp[j][i+B]||dp[j][i];
			}
		}
	}
}
void divide(){
	for(int i=1; i<=T; i++){
		dp[1][i/2] = dp[1][i/2] || dp[0][i];
	}
}
void both(){
	for(int j=0; j<2; j++){
		for(int i=0; i<=T; i++){
			if(i+A <= T){
				dp[j][i+A] = dp[j][i+A]||dp[j][i];
			}
			if(i+B <= T){
				dp[j][i+B] = dp[j][i+B]||dp[j][i];
			}
			if(j==0){
				dp[1][i/2] = dp[1][i/2] || dp[j][i];
			}
		}
	}
}
int main() {

	// fstream
	ifstream fin ("feast.in");
	ofstream fout ("feast.out");

	// input
	fin >> T >> A >> B;
	// main
	for(int i=0; i<2; i++){
		for(int j=0; j<=T; j++) dp[i][j] = false;
	}
	dp[0][0] = true;
//	add();
//	divide();
//	add();
	// output
	both();
	int ans = T;
	while(!dp[1][ans]) ans--;
	fout << ans << endl;
	//close
	fout.close();
	return 0;
}

```

