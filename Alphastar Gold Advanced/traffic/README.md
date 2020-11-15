# traffic
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
struct node {
	int i, time;
	node(int i, int time) :i(i), time(time) {}
};
struct comp{
    bool operator()(const node& a, const node& b) {
    	return a.time>b.time;
    }
};
// global variables
int S, D, N, M;
int initialLight[304], initialTime[304], duration[304][2];
int edge[304][304];
bool visited[304]; int dist[304];
// functions
int currLight(int i, int time) {
    int currentLight = initialLight[i];

    if (time-initialTime[i] >= 0) {
        time -= initialTime[i];
        currentLight = 1-currentLight;
    }
    while (time-duration[i][currentLight] >= 0) {
        time -= duration[i][currentLight];
        currentLight = 1-currentLight;
    }
    return currentLight;
}
int shortestPath() {
	dist[S] = 0;

	while(true) {
		int j=-1;
		for(int i=1; i<=N; i++) {
			if(dist[i]!=-1 && !visited[i] && (j==-1 || dist[j]>dist[i])) {
				j=i;
			}
		}
		if(j==-1) break;
		visited[j] = -1;
		for (int i=1; i<=N; i++) {
			if (edge[i][j] == 0) continue;
			for(int time=dist[j]; (time<dist[j]+350)&&(dist[i]==-1 || time+edge[i][j]<dist[i]); time++) {
				if(currLight(i, time) == currLight(j, time)) {
					dist[i] = time+edge[i][j];
					break;
				}
			}
		}
	}


	return dist[D];
}
int main() {
	// local variables

	// input
	cin >> S >> D >> N >> M;
	for(int i=1; i<=N; i++) {
		char light; cin >> light >> initialTime[i] >> duration[i][0] >> duration[i][1];
		initialLight[i]= !(light=='B');
		visited[i] = false; dist[i]=-1;
	}
	for(int i=1; i<=M; i++) {
		int a,b,d; cin >> a >> b >> d;
		edge[a][b]=edge[b][a]=d;
	}
	// main
	int ans = shortestPath();
	if(ans == -1) cout << "0" << endl;
	else cout << ans << endl;
	// output

	return 0;
}

```