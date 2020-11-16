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
#define Pair pair<int, int>
// global variables
int N, M, T;
int c[10004];
int dist[10004], parent[10004], visited[10004];
vector<Pair> edge[10004];
int temp_ans[10004];
// functions
void shortestPath() {
	dist[1] = 0;
	priority_queue<Pair, vector<Pair>, greater<Pair> > Q;
	Q.push(Pair(0, 1));
	while(!Q.empty()) {
		int i=Q.top().second, d=Q.top().first;
		Q.pop();

		visited[i] = true;
//		cout << i << " " << d << endl;
		for(int j=0; j<edge[i].size(); j++) {
			int go=edge[i][j].first, nd=edge[i][j].second+d;
			if(!visited[go]) {
				if(nd<dist[go] || (nd==dist[go] && parent[go]>i)) {
					dist[go] = nd;
					parent[go]=i;
					Q.push(Pair(nd, go));
				}
			}
		}
	}
}
int main() {
	// local variables

	// input
	ifstream fin("shortcut.in");
	ofstream fout("shortcut.out");
	// main
	fin >> N >> M >> T;
	for(int i=1; i<=N; i++) {
		dist[i] = 1000000000, parent[i] = -1, visited[i] = false;
		fin >> c[i];
	}
	for(int i=1; i<=M; i++) {
		int a, b, d; fin >> a >> b >> d;
		edge[a].push_back(Pair(b, d));
		edge[b].push_back(Pair(a, d));
	}
	shortestPath();
	for(int i=1; i<=N; i++) {
//		cout << dist[i]<<endl;
		int j=i;
		while(j!=-1) {
			temp_ans[j] += c[i];
			j = parent[j];
		}
	}
	long long ans = 0;
	for(int i=1; i<=N; i++) {
		ans = max(ans, (long long) temp_ans[i]*(dist[i]-T));
	}
	fout << ans << endl;
	// output

	return 0;
}
