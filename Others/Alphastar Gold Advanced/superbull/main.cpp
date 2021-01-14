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
int team[2004], dist[2004];
bool visited[2004];
// functions
int cal(int i, int j) {
	return team[i]^team[j];
}
int main() {
	// local variables

	// input
	cin >> N;
	for(int i=1; i<=N; i++) {
		cin >> team[i];
		dist[i] = -1;
		visited[i] = false;
	}
	// main

	dist[1] = 0;
	long long ans = 0;
	for(int i=1; i<=N; i++) {
		int k=-1;
		for(int j=1; j<=N; j++) {
			if(!visited[j] && dist[j]!=-1 && (k==-1 || dist[k]<dist[j])) {
				k=j;
			}
		}
		if(k==-1) break;
		visited[k] = true;
		ans += dist[k];
		for(int j=1; j<=N; j++) {
			int ndist = cal(k, j);
			if(!visited[j] && dist[j]<ndist) {
				dist[j]=ndist;
			}
		}
	}
	cout << ans << endl;
	// output

	return 0;
}
