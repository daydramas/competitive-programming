# frameup
```cpp
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
int N, M;
int mtrx[33][33];
bool visited[33];
int L[33], R[33], U[33], D[33];
int graph[33][33];
int numOfBox = 0;
char ans[33];
int NumOfTo[33];

// functions
int convertToId(char ch) {
	if(ch == '.') return 0;
	return ch-'A'+1;
}
void miniBuildGraph(int c, int x) {
  if (c != x) {
    graph[x][c] = true;
  }
}
void buildGraph(int x) {
  for (int i = L[x]; i <= R[x]; ++i) {
	 miniBuildGraph(mtrx[U[x]][i], x);
	 miniBuildGraph(mtrx[D[x]][i], x);
  }
  for (int i = D[x]; i <= U[x]; ++i) {
	 miniBuildGraph(mtrx[i][L[x]], x);
	 miniBuildGraph(mtrx[i][R[x]], x);
  }
}
void dfsForAns(int numDid) {
  if (numDid == numOfBox) {
    for(int i=0; i<numDid; i++) {
    	cout << ans[i];
    }
    cout << endl;
    return;
  }
  for (int i=1; i<=31; i++) {
    if(visited[i] && NumOfTo[i] == 0) {
      visited[i] = false;
      ans[numDid] = 'A'+i-1;
      for(int j=1; j<=31; j++) {
        if (graph[i][j]) {
          NumOfTo[j]--;
        }
      }
      dfsForAns(numDid + 1);
      //reset
      visited[i] = true;
      for(int j=1; j<=31; j++) {
        if (graph[i][j]) {
        	NumOfTo[j]++;
        }
      }
    }
  }
}
int min0(int a, int b) {
	if(a == 0) return b;
	if(a > b) return b;
	return a;
}
int max0(int a, int b) {
	if(a == 0) return b;
	if(a < b) return b;
	return a;
}
int main() {
	// local variables

	// input
	cin >> N >> M;
	for(int i=1; i<=N; i++) {
		string read; cin >> read;
		for(int j=1; j<=M; j++) {
			if(isalpha(read[j-1])) {
				int id = convertToId(read[j-1]);
				mtrx[i][j] = id;
				visited[id] = true;
				L[id] = min0(L[id], j);
				R[id] = max0(R[id], j);
				U[id] = max0(U[id], i);
				D[id] = min0(D[id], i);
			}
		}
	}
	// main
	for(int i=1; i<=26; i++) {
		if(visited[i]) {
			buildGraph(i);
			numOfBox++;
		}
	}
	for (int i=1; i<=31; i++) {
	    for (int j=1; j<=31; j++) {
	      if (graph[i][j] && i!=j) {
	    	  NumOfTo[j]++;
	      }
	    }
	  }
	dfsForAns(0);
	// output

	return 0;
}

```