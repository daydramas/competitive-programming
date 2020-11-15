<div align="center"> [alliance.cpp](#0) | [bobsled.cpp](#1) | [cbarn.cpp](#2) | [ccski.cpp](#3) | [ceating.cpp](#4) | [chocmilk.cpp](#5) | [crazy.cpp](#6) | [crowded.cpp](#7) | [cruise.cpp](#8) | [datastructures.cpp](#9) | [distant.cpp](#10) | [dream.cpp](#11) | [expense.cpp](#12) | [fencedin.cpp](#13) | [flow.cpp](#14) | [fpot.cpp](#15) | [frameup.cpp](#16) | [gpsduel.cpp](#17) | [grove.cpp](#18) | [jobhunt.cpp](#19) | [lilypad.cpp](#20) | [photo.cpp](#21) | [piepie.cpp](#22) | [planting.cpp](#23) | [poker.cpp](#24) | [pwrfail.cpp](#25) | [rblock.cpp](#26) | [rplow2.cpp](#27) | [shopping.cpp](#28) | [skyline.cpp](#29) | [sparty.cpp](#30) | [split.cpp](#31) | [squares.cpp](#32) | [superbull.cpp](#33) | [traffic.cpp](#34) | [ttravel.cpp](#35) | [wall.cpp](#36) | [water.cpp](#37) </div>

# [alliance.cpp](#0)
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
#define Pair pair<int, int>
// global variables
int N, M;
vector<int> edge[100010];
bool visited[100010];
// functions
Pair dfs(int x) {
  if(visited[x]) return make_pair(0, 0);
  visited[x] = true;

  Pair rVal(1, edge[x].size());
  for(int i=0; i<edge[x].size(); i++) {
    Pair nVal = dfs(edge[x][i]);
    rVal.first += nVal.first;
    rVal.second += nVal.second;
  }
  return rVal;
}
int main() {
	// local variables

	// input
	cin >> N >> M;
	for(int i=1; i<=M; i++){
		int x, y; cin >> x >> y;
		visited[i] = false;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	// main
	long long ans = 1;
	for(int i=1; i<=N; i++) {
		if(visited[i] || edge[i].size()==0) continue;

		Pair p = dfs(i);
		p.second /= 2;
		if (p.first == p.second) {
			ans *= 2;
		} else if (p.first == p.second+1) {
			ans *= p.first;
		}
		ans %= 1000000007;
	}
	// output
	cout << ans << endl;
	return 0;
}

```

# [bobsled.cpp](#1)
```cpp
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
#define loc first
#define maxS second

// global variables
int L, N;
vector<Pair> maxSpeed;
int slowDown[100004];
int speedUp[100004];
// functions
 int max2(int s1, int s2, int dist) {
  return max(s1,s2)+int((dist-abs(s1-s2))/2);
}
int main() {
	// local variables

	// input
	cin >> L >> N;
	for(int i=1; i<=N; i++) {
		int a,b; cin >> a >> b;
		maxSpeed.push_back(Pair(a,b));
	}
	N++; N++;
	maxSpeed.push_back(Pair(0,1));
	maxSpeed.push_back(Pair(L,1000000000));
	sort(maxSpeed.begin(), maxSpeed.end());

	// main
	slowDown[N-1] = maxSpeed[N-1].maxS;
	for (int i=N-2; i>=0; i--) {
		slowDown[i] = min(slowDown[i+1]+(maxSpeed[i+1].loc-maxSpeed[i].loc),maxSpeed[i].maxS);
	}
	int ans = 1;
	speedUp[0] = maxSpeed[0].maxS;
	for (int i=1; i<N; i++) {
	  speedUp[i] = min(speedUp[i-1] + (maxSpeed[i].loc-maxSpeed[i-1].loc),slowDown[i]);
	}
	for(int i=1; i<N; i++) {
		ans = max(ans,max2(speedUp[i-1],speedUp[i],maxSpeed[i].loc-maxSpeed[i-1].loc));
	}
	// output
	cout << ans << endl;
	return 0;
}

```

# [cbarn.cpp](#2)
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

```

# [ccski.cpp](#3)
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
#define Pair pair<int, int>
#define mp make_pair
#define a first
#define b second

// global variables
int N, M;
int wx=1, wy=1;
int elevation[501][501];
bool wayPoint[501][501];
bool visited[501][501];
int X[] = {1, 0, -1, 0};
int Y[] = {0, 1, 0, -1};
// functions
void bfs(int D) {
	queue<Pair> q;
	q.push(mp(wx, wy));
	visited[wx][wy] = true;
	while(!q.empty()) {
		Pair p=q.front();
		for(int i=0; i<4; i++) {
			int x=p.a+X[i];
			int y=p.b+Y[i];
			if(x>=1 and x<=N and y>=1 and y<=M and !visited[x][y] and abs(elevation[p.a][p.b]-elevation[x][y])<=D) {
				visited[x][y]=true;
				q.push(mp(x, y));
			}
		}
		q.pop();
	}
}
bool if_reachable(int D) {
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			visited[i][j]=false;
		}
	}
	bfs(D);
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			if(wayPoint[i][j] && !visited[i][j]) return false;
		}
	}
	return true;
}
int main() {
	// local variables

	// input
	cin >> N >> M;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			cin >> elevation[i][j];
		}
	}
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			int read; cin >> read;
			if(read == 1){
				wayPoint[i][j] = true;
				wx=i; wy=j;
			}
			else wayPoint[i][j] = false;
		}
	}

	// main
	int small = 0, big = 1000000000;
	while(small < big) {
		int mid = (small+big)/2;
		if(if_reachable(mid)) {
			big = mid;
//			cout <<"reachable "<<mid<<endl;
		} else{
//			cout <<"unreachable "<<mid<<endl;
			small=mid+1;
		}
	}
	// output
	cout << small <<endl;
	return 0;
}

```

# [ceating.cpp](#4)
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
int N, D, H[50004];

// functions
bool work(long long h) {
	long long ch = 0; int hi = 1;
	for(int i=1; i<=D; i++) {
		while(true) {
			if(ch <= h) {
				if(hi == N+1) return false;
				ch += H[hi++];

			}
			if(ch > h) break;
		}
		ch /= 2;
	}
	return true;
}
int main() {
	// local variables

	// input
	cin >> N >> D;
	for(int i=1; i<=N; i++) cin >> H[i];
	// main
	long long min=0, max=10000000000000;
	while(min<max) {
		long long mid=(min+max)/2;
		if(!work(mid)) {
			max=mid;
		} else {
//			cout << "not"<<endl;
			min=mid+1;
		}
	}
	// output
	cout << min << endl;
	map<int, int > cnt;
	long long h = min;
	long long ch = 0; int hi = 1;
	int d=-1;
	for(int i=1; i<=D; i++) {
		while(true) {
			if(ch < h) {
//				cout <<i<<endl;
				if(hi == N+1) break;
				cout << i << endl;
				ch += H[hi++];
			}
			if(ch >= h) break;
		}
		ch /= 2;
//		cout << ch<< " " << hi << endl;
	}
	for(int i=hi; i<=N; i++) {
		cout << D << endl;
	}
	return 0;
}

```

# [chocmilk.cpp](#5)
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
int N;
int comeIn[100001], comeOut[100001], nextValue[100001];

// functions

int main() {

    cin >> N;
    for(int i=1; i<=N; i++) comeOut[i]=comeIn[i]=0;
    for (int i=1; i<N; i++) {
        int a, b; cin >> a >> b;
        nextValue[a] = b;
        comeOut[a]++;
        comeIn[b]++;
    }

    int start = -1;
    for (int i=1, current=-1; i<=N; i++) {
		if (current == i)
			if (start < 0 || comeIn[i] > 1)
				start=i;

		if (comeOut[i] == 1) {
			current = max(current, nextValue[i]);
		} else break;
    }

    for (int i=start; i<=N; i=nextValue[i]) {
		cout << i << endl;
		if (comeOut[i]==0 or comeOut[i]>1) break;
    }
    return 0;
}

```

# [crazy.cpp](#6)
```cpp
//#include <algorithm>
//#include <bitset>
//#include <complex>
//#include <deque>
//#include <exception>
//#include <fstream>
//#include <functional>
//#include <iomanip>
//#include <ios>
//#include <iosfwd>
//#include <iostream>
//#include <istream>
//#include <iterator>
//#include <limits>
//#include <list>
//#include <locale>
//#include <map>
//#include <memory>
//#include <new>
//#include <numeric>
//#include <ostream>
//#include <queue>
//#include <set>
//#include <sstream>
//#include <stack>
//#include <stdexcept>
//#include <streambuf>
//#include <string>
//#include <typeinfo>
//#include <utility>
//#include <valarray>
//#include <vector>
//using namespace std;
//
//// structures / defines
//
////Data Structures
//
//struct point { int x, y; char c; };
//struct line { struct point p1, p2; };
//struct point polygon[1004];
//
////Testing whether line segments intersect
//
//int ccw(struct point p0, struct point p1, struct point p2)
//{
//	int dx1, dx2, dy1, dy2;
//	dx1 = p1.x - p0.x; dy1 = p1.y - p0.y;
//	dx2 = p2.x - p0.x; dy2 = p2.y - p0.y;
//	if(dx1*dy2 > dy1*dx2) return +1;
//	if(dx1*dy2 < dy1*dx2) return -1;
//	if((dx1*dx2 < 0) || (dy1*dy2 < 0)) return -1;
//	if((dx1*dx1+dy1*dy1) < (dx2*dx2+dy2*dy2)) return +1;
//	return 0;
//}
//
//int intersect(struct line l1, struct line l2)
//{
//	return ((ccw(l1.p1, l1.p2, l2.p1)
//	        *ccw(l1.p1, l1.p2, l2.p2)) <= 0)
//	    && ((ccw(l2.p1, l2.p2, l1.p1)
//	        *ccw(l2.p1, l2.p2, l1.p2)) <= 0);
//}
//
////Testing whether a point is in a polygon
//
//int inside(struct point t, point p[1004], int N)
//{
//	int i, count = 0, j = 0;
//	struct line lt,lp;
//	p[0] = p[N]; p[N+1] = p[1];
//	lt.p1 = t; lt.p2 = t; lt.p2.x = 1000000000;
//	for(i=1; i<=N; i++) {
//		lp.p1 = p[i]; lp.p2 = p[i];
//		if(!intersect(lp,lt)) {
//			lp.p2 = p[j]; j = i;
//			if (intersect(lp,lt)) count++;
//		}
//	}
//	return count & 1;
//}
//
//struct node {
//	bool visited; int parent;
//};
//
//// global variables
//
//int N, C;
//struct line fence[1004];
//struct point cow[1004];
//struct node nodes[1004];
//struct point cycle[1004][1004]; int cycles[1004];
//int ans = 0;
//
//// functions
//void findCycle(int fenceIn, int parent, point finder) {
//	nodes[fenceIn].visited = true;
//	for(int i=1; i<=N; i++) {
//		if(!nodes[i].visited) {
//			if (finder.x == fence[i].p1.x && finder.y == fence[i].p1.y) {
//				nodes[i].parent = parent;
//				cycle[parent][++cycles[parent]] = fence[i].p2;
//				findCycle(i, parent, fence[i].p2);
//				break;
//			} else if (finder.x == fence[i].p2.x && finder.y == fence[i].p2.y) {
//				nodes[i].parent = parent;
//				cycle[parent][++cycles[parent]] = fence[i].p1;
//				findCycle(i, parent, fence[i].p1);
//				break;
//			}
//
//		}
//	}
//}
//void solve(int i) {
//	for(int i1=0; i1<=N+1; i1++) cycle[i][i1].x = -1, cycle[i][i1].y = -1;
//	cycles[i] = 0; cycle[i][++cycles[i]] = fence[i].p2;
//	findCycle(i, i, fence[i].p2);
//
////	cout << "cycle: ";
////	for(int i1=1; i1<=N; i1++) {
////		if(cycle[i][i1].x == -1) break;
////		cout <<"("<< cycle[i][i1].x << ", " << cycle[i][i1].y<<") ";
////	}
////	cout << endl;
//}
//int main() {
//	// local variables
//
//	// input
//	cin >> N >> C;
//	for(int i=1; i<=N; i++) {
//		cin >> fence[i].p1.x >> fence[i].p1.y;
//		cin >> fence[i].p2.x >> fence[i].p2.y;
//		nodes[i].visited = false, nodes[i].parent = i;
//	}
//	for(int i=1; i<=C; i++) {
//		cin >> cow[i].x >> cow[i].y;
//	}
//
//	// main
//	int numOfCycles = 0;
//	for(int i=1; i<=N; i++) {
//		if(!nodes[i].visited) {
//			numOfCycles++;
////			cout << "New cycle begins solving here!"<<endl;
//			solve(i);
//		}
//	}
//	for(int i=1; i<=numOfCycles; i++) {
//		int tempAns = 0;
//		for(int i1=1; i1<=C; i1++) {
//			bool inTheFence = (inside(cow[i1], cycle[i], cycles[i])%2) == 1;
//			if(inTheFence) {
//				bool add = true;
//				for(int j=1; j<=numOfCycles; j++) {
//					if(j==i) continue;
//					bool inTheFence2 = (inside(cow[i1], cycle[j], cycles[j])%2) == 1;
//					if (inTheFence2) {
//						bool inTheFence3 = (inside(cycle[i][1], cycle[j], cycles[j])%2) == 1;
//						if(!inTheFence3) add = false; break;
//					}
//				}
//				if (add) tempAns++;
//			}
//		}
//		ans = max(ans, tempAns);
//	}
//	// output
//	cout << ans << endl;
//	return 0;
//}
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
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

#define N_MAX 1004
#define C_MAX 1004

bool numOfRayHits(long long cx, long long cy, long long f1x, long long f1y, long long f2x, long long f2y) {
    if ((f1y > cy) ^ (f2y > cy)) {
        return (f1y - f2y < 0) ^ (f2x * (f1y - cy) + f1x * (cy - f2y) > cx * (f1y - f2y));
    } else {
        return false;
    }
}

map<pair<int,int>, vector<int> > pointMap;
pair<pair<int,int>, pair<int,int> > fences[N_MAX];
int cycle[N_MAX];

char parities[C_MAX][N_MAX];

char* parityptrs[C_MAX];
inline bool comparee(char* a, char* b) {
    return strcmp(a, b) < 0;
}

int main() {

    int N, C;
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        pair<int,int> p1, p2;
        cin >> p1.first >> p1.second >> p2.first >> p2.second;
        pointMap[p1].push_back(i);
        pointMap[p2].push_back(i);
        fences[i] = pair<pair<int,int>, pair<int,int> >(p1, p2);
        cycle[i] = -1;
        memset(parities[i], 0, C);
    }
    for (int i = 0; i < C; i++) {
        parityptrs[i] = parities[i];
    }

    int nCycles = 0;
    for (int i = 0; i < N; i++) {
        if (cycle[i] == -1) {
            int j = i;
            pair<int,int> last = fences[i].first;
            do {
                cycle[j] = nCycles;
                last = fences[j].first == last ? fences[j].second : fences[j].first;
                vector<int> const& v = pointMap[last];
                j = (v[0] == j ? v[1] : v[0]);
            } while (j != i);
            nCycles++;
        }
    }

    for (int i = 0; i < C; i++) {
        int cowx, cowy;
        cin >> cowx >> cowy;
        for (int j = 0; j < N; j++) {
            parities[i][cycle[j]] ^= (char)numOfRayHits(cowx, cowy, fences[j].first.first, fences[j].first.second, fences[j].second.first, fences[j].second.second);
        }
        for (int j = 0; j < nCycles; j++) {
            parities[i][j] = parities[i][j] ? '1' : '0';
        }
        parities[i][nCycles] = '\0';
    }

    sort(parityptrs, parityptrs + C, comparee);

    int maxans = 0;
    int curcount = 0;
    for (int i = 0; i < C; i++) {
        if (i == 0 || strcmp(parityptrs[i], parityptrs[i-1]) != 0) {
            curcount = 1;
        } else {
            curcount++;
        }
        maxans = max(maxans, curcount);
    }
    cout << maxans << endl;
}

```

# [crowded.cpp](#7)
```cpp
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
struct s2b {
  bool operator() (Pair i, Pair j) { return (i.first<j.first);}
} s2b;
struct comp {
  bool operator() (const Pair& lhs, const Pair& rhs) const
  {return lhs.first<rhs.first;}
};
// global variables
int N, D;
vector<Pair> cow;

// functions

int main() {
	// local variables

	// input
	cin >> N >> D;
	for(int i=1; i<=N; i++) {
		int x,h; cin >> x >> h;
		cow.push_back(Pair(x,h));
	}
	sort(cow.begin(), cow.end(), s2b);

	// main

	  int result = 0;
	  multiset<int> X, Y;
	  int j = 0, k = 0;
	  for(int i = 0; i < N; i++) {
	    while(k < N && cow[k].first <= cow[i].first + D) {
	      Y.insert(cow[k++].second);
	    }
	    while(cow[j].first + D < cow[i].first) {
	      X.erase(X.find(cow[j++].second));
	    }
	    X.insert(cow[i].second);

	    if (*X.rbegin() >= 2 * cow[i].second && *Y.rbegin() >= 2 * cow[i].second) {
	      result++;
	    }

	    Y.erase(Y.find(cow[i].second));
	  }

	  cout << result << endl;
	// output
	return 0;
}



/*
 * 3 6
 * 5 3
 * 6 2
 * 9 7
 * 10 3
 * 11 2
 */

```

# [cruise.cpp](#8)
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
int N, M, K;
int L[2001], R[2001];
string sequence;
int ans = 0;
// functions
int main() {
	// local variables

	// input
	cin >> N >> M >> K;
	for(int i=1; i<=N; i++) {
		cin >> L[i] >> R[i];
	}
	sequence = "";
	for(int i=0; i<M; i++) {
		string str; cin >> str;
		sequence += str;
	}

    map<int, int> seen;
    vector<int> moves;
    int in = 0, move = 1;
    while (seen.count(move) == 0) {
        seen[move] = in++;
        moves.push_back(move);
        for(int i=0; i<M; i++){
        	if(sequence[i] == 'L') move = L[move];
        	else move = R[move];
        }
        if(moves.size() > K) break;
    }
    if(moves.size() > K) cout << moves[K] << endl;
    else {
    	int C = in-seen[move];
		int nIn = (K-seen[move]+C)%C;
		cout << moves[seen[move]+nIn] << endl;
    }
	// output
	return 0;
}

```

# [datastructures.cpp](#9)
```cpp
/*

 //Sorting

 struct s2b {
 bool operator() (int i,int j) { return (i<j);}
 } s2b;
 struct b2s {
 bool operator() (int i,int j) { return (i>j);}
 } b2s;

 */

/*

 //Bellman Ford Algorithm

 int* bellmanford(Edge* e, int N, int M, int src)
 {
 int* dist = new int[N];
 for(int i=0; i<N; i++) dist[i] = INFINITY;
 dist[src] = 0;
 for(int i=0; i<N-1; i++)
 for(int j=0; j<M; j++)
 if (dist[e[j].to] > dist[e[j].from] + e[j].weight)
 dist[e[j].to] = dist[e[j].from] + e[j].weight;
 return dist;
 }

 */

/*

 //Sedgewick Geometric Methods:


 //Data Structures

 struct point { int x, y; char c; };
 struct line { struct point p1, p2; };
 struct point polygon[Nmax];

 //Testing whether line segments intersect

 int ccw(struct point p0, struct point p1, struct p2)
 {
 int dx1, dx2, dy1, dy2;
 dx1 = p1.x - p0.x; dy1 = p1.y - p0.y;
 dx2 = p2.x - p0.x; dy2 = p2.y - p0.y;
 if(dx1*dy2 > dy1*dx2) return +1;
 if(dx1*dy2 < dy1*dx2) return -1;
 if((dx1*dx2 < 0) || (dy1*dy2 < 0)) return -1;
 if((dx1*dx1+dy1*dy1) < (dx2*dx2+dy2*dy2)) return +1;
 return 0;
 }

 int intersect(struct line l1, struct line l2)
 {
 return ((ccw(l1.p1, l1.p2, l2.p1)
 *ccw(l1.p1, l1.p2, l2.p2)) <= 0)
 && ((ccw(l2.p1, l2.p2, l1.p1)
 *ccw(l2.p1, l2.p2, l1.p2)) <= 0);
 }

 //Testing whether a point is in a polygon

 int inside(struct point t, struct polygon p, N)
 {
 int i, count = 0, j = 0;
 struct line lt,lp;
 p[0] = p[N]; p[N+1] = p[1];
 lt.p1 = t; lt.p2 = t; lt.p2.x = 1000000000;
 for(int i=1; i<=N; i++) {
 lp.p1 = p[i]; pl.p2 = p[i];
 if(!intersect(lp,lt)) {
 lp.p2 = p[j]; j = i;
 if (intersect(lp,lt)) count++;
 }
 }
 return count & 1;
 }


 //l is minx, miny
 //r is maxx, maxy
 int overlappingArea(Pair l1, Pair r1, Pair l2, Pair r2) {
 int area1 = abs(l1.x - r1.x) * abs(l1.y - r1.y);
 int area2 = abs(l2.x - r2.x) * abs(l2.y - r2.y);
 int areaI = (min(r1.x, r2.x) - max(l1.x, l2.x)) *
 (min(r1.y, r2.y) - max(l1.y, l2.y));

 return (areaI);
 //    return (area1+area2-areaI);
 }


 //l is minx, maxy
 //r is maxx, miny
 bool doOverlap(Pair l1, Pair r1, Pair l2, Pair r2) {
 swap(l1.y,r1.y); swap(l2.y,r2.y);
 if (l1.x > r2.x || l2.x > r1.x) return false;
 if (l1.y < r2.y || l2.y < r1.y) return false;
 return true;
 }


 how to find interior angles of an irregular polygon with N points
 // barn is point
 for (int i = 0; i < N; i++) {
 int last = (i - 1 + N) % N;
 int next = (i + 1) % N;
 double x1 = barn[i].x - barn[last].x;
 double y1 = barn[i].y - barn[last].y;
 double x2 = barn[next].x - barn[i].x;
 double y2 = barn[next].y - barn[i].y;
 double theta1 = atan2(y1, x1) * 180 / 3.1415926358979323;
 double theta2 = atan2(y2, x2) * 180 / 3.1415926358979323;
 angle[i] = (180 + theta1 - theta2 + 360);
 while (angle[i] > 360)
 angle[i] -= 360;
 //		cout << "angle[" << i << "] = " << angle[i] << endl;
 }
 */

```

# [distant.cpp](#10)
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
	int i, j, dist;
	node(int i, int j, int dist) : i(i), j(j), dist(dist) {}
};
struct comp{
    bool operator()(const node& a, const node& b) {
    	return a.dist>b.dist;
    }
};
// global variables
int N, A, B;
bool pasture[44][44], visited[44][44];
int X[] = {1, 0, -1, 0};
int Y[] = {0, 1, 0, -1};
long long ans = 0;
// functions
int distance(int i, int j, int x, int y) {
	if(pasture[i][j] == pasture[x][y]) return A;
	return B;
}
void shortestPath(int si, int sj) {
	priority_queue<node, vector<node>, comp> Q;
	Q.push(node(si, sj, 0));
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) visited[i][j]=false;
	while(!Q.empty()) {
		int i=Q.top().i, j=Q.top().j, dist=Q.top().dist;
		Q.pop();
		if(visited[i][j]) continue;
		ans = max(ans, (long long) dist);
		visited[i][j]=true;
		for(int k=0; k<4; k++) {
			int x=i+X[k], y=j+Y[k];
			if(x>=1 and x<=N and y>=1 and y<=N) {
				if(!visited[x][y]) {
					int ndist = dist+distance(i, j, x, y);
					Q.push(node(x,y,ndist));
				}
			}
		}
	}
}
int main() {
	// local variables

	// input
	cin >> N >> A >> B;
	for(int i=1; i<=N; i++) {
		string read; cin >> read;
		for(int j=1; j<=N; j++) {
			if(read[j-1] == '(') pasture[i][j] = true;
			if(read[j-1] == ')') pasture[i][j] = false;
		}
	}
	// main
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			shortestPath(i,j);
		}
	}
	cout <<ans << endl;
	// output

	return 0;
}

```

# [dream.cpp](#11)
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
	int i; int j; int moves; int direction; bool orange;
	node(int i, int j, int moves, int direction, bool orange) : i(i), j(j), moves(moves), direction(direction), orange(orange) {}
};
struct nNode {
	int i; int j; int direction; bool orange;
	nNode(int i, int j, int direction, bool orange) : i(i), j(j), direction(direction), orange(orange) {}
};
// global variables
int N, M;
int maze[1004][1004];
int dist[1004][1004];
//map<nNode, bool> visited;
bool visited[1004][1004][4][2];
int ans = -1;
int X[] = {1,0,-1,0};
int Y[] = {0,1,0,-1};
// functions
bool valid(int i, int j) {
	return (i>=1 && i<=N && j>=1 && j<=M);
}
void bfs() {
	queue<node> Q; Q.push(node(1,1,0,3,false));
	dist[1][1]=0;
	while(!Q.empty()) {
		int i=Q.front().i, j=Q.front().j, moves=Q.front().moves, direction=Q.front().direction;
		bool orange=Q.front().orange; Q.pop();
		if(visited[i][j][direction][(int)orange]) continue;
		visited[i][j][direction][(int)orange] = true;
//		cout << i << " " << j << " : " << moves << endl;
		if(i==N && j==M) {
			ans = moves;
			return;
		}
		if(maze[i][j] == 4) {
			int x=i+X[direction],y=j+Y[direction];
			if(!valid(x,y) || maze[x][y]==0 || (maze[x][y]==3 && !orange)) {

				for(int k=0; k<4; k++) {
					if(direction == k) continue;
					int x1=i+X[k], y1=j+Y[k];
					if(valid(x1, y1) && maze[x1][y1]!=0){
						if(maze[x1][y1]==3 && !orange) continue;
						bool nOrange = orange;
						if(maze[x1][y1]==2) nOrange=true;
						if(maze[x1][y1]==4) nOrange=false;
						if(visited[x1][y1][k][(int)nOrange]) continue;
						dist[x1][y1]=moves+1;
						Q.push(node(x1,y1,moves+1,k,nOrange));
					}
				}
			} else if (maze[x][y]!=0){
				Q.push(node(x,y,moves+1, direction,false));
				dist[x][y]=moves+1;
			}
		} else {
			for(int k=0; k<4; k++) {
				int x1=i+X[k], y1=j+Y[k];
				if(valid(x1, y1) && maze[x1][y1]!=0){
					if(maze[x1][y1]==3 && !orange) continue;
					bool nOrange = orange;
					if(maze[x1][y1]==2) nOrange=true;
					if(maze[x1][y1]==4) nOrange=false;
					if(visited[x1][y1][k][(int)nOrange]) continue;
					dist[x1][y1]=moves+1;
					Q.push(node(x1,y1,moves+1,k,nOrange));
				}
			}
		}
	}
}
int main() {
	// local variables
	ifstream fin("dream.in");
	ofstream fout("dream.out");
	// input
	fin >> N >> M;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			fin >> maze[i][j];
			dist[i][j] = -1;
			for(int k=0; k<4; k++) {
				visited[i][j][k][0]=visited[i][j][k][1]=false;
			}
		}
	}
	// main
	bfs();
	// output
	fout << ans << endl;
	return 0;
}

```

# [expense.cpp](#12)
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
int spend[100004];

// functions

int main() {
	// local variables

	// input
	cin >> N >> M;
	for(int i=1; i<=N; i++) {
		cin >> spend[i];
	}
	// main
	int min=0, max=1000000000;
	while(min<max) {
		int mid = (min+max)/2;

		int sum = 0;
		int group = 1;
		for(int i=1; i<=N; i++) {
			if(spend[i]>mid) {
				group = M+1;
				break;
			}
			if(sum+spend[i] > mid) {
				group++, sum = 0;
			}
			sum += spend[i];
		}
		if(group <= M) {
			max = mid;
		} else {
			min = mid+1;
		}
	}

	// output
	cout << min << endl;
	return 0;
}

```

# [fencedin.cpp](#13)
```cpp
//#include <algorithm>
//#include <bitset>
//#include <complex>
//#include <deque>
//#include <exception>
//#include <fstream>
//#include <functional>
//#include <iomanip>
//#include <ios>
//#include <iosfwd>
//#include <iostream>
//#include <istream>
//#include <iterator>
//#include <limits>
//#include <list>
//#include <locale>
//#include <map>
//#include <memory>
//#include <new>
//#include <numeric>
//#include <ostream>
//#include <queue>
//#include <set>
//#include <sstream>
//#include <stack>
//#include <stdexcept>
//#include <streambuf>
//#include <string>
//#include <typeinfo>
//#include <utility>
//#include <valarray>
//#include <vector>
//using namespace std;
//// structures / defines
//struct edge {
//	int i, j, x, y; int weight;
//	edge(int i, int j, int x, int y, int weight) : i(i), j(j), x(x), y(y), weight(weight) {}
//};
//struct comp {
//  bool operator() (edge i,edge j) { return (i.weight<j.weight);}
//} comp;
//// global variables
//int A, B, N, M;
//vector<int> VA, HA;
//int pa[2010*2010];
//vector<edge> edges;
//// functions
//int get_ID(int i, int j) {return (i*(M+1))+j; }
//int calculateY(int i) {
//	if (i == 0) return VA[i];
//	return abs(VA[i]-VA[i-1]);
//}
//int calculateX(int i) {
//	if (i == 0) return HA[i];
//	return abs(HA[i]-HA[i-1]);
//}
//int find_parent(int x) {
//	if (x != pa[x]) pa[x] = find_parent(pa[x]);
//	return pa[x];
//}
//int main() {
//	// local variables
//
//	// input
//	cin >> A >> B >> N >> M;
//	for(int i=1; i<=N; i++) {int x; cin >> x; VA.push_back(x); }
//	VA.push_back(A);
//	for(int i=1; i<=M; i++) {int x; cin >> x; HA.push_back(x); }
//	HA.push_back(B);
//	sort(VA.begin(), VA.end()); sort(HA.begin(), HA.end());
//	for(int i=0; i<=N; i++) for(int j=0; j<=M; j++) pa[get_ID(i,j)] = get_ID(i, j);
//	// main
////	for(int i=0; i<=N; i++) {
////		VA[i] = VA[i+1]-VA[i];
////	}
//	for(int i=0; i<=N; i++) {
//		for(int j=0; j<=M; j++) {
//			int x = i+1;
//			int y = j;
//			if(x >= 0 and x <= N and y >= 0 and y <= M) {
//				int weight = calculateX(j);
//				edges.push_back(edge(i,j,x,y,weight));
//			}
//			x--; y++;
//			if(x >= 0 and x <= N and y >= 0 and y <= M) {
//				int weight = calculateY(i);
//				edges.push_back(edge(i,j,x,y,weight));
//			}
//		}
//	}
//	sort(edges.begin(), edges.end(), comp);
//	long long ans = 0;
//	long long cnt = 0;
//	for(int k=0; k<edges.size(); k++) {
//		int i=edges[k].i, j=edges[k].j, x=edges[k].x, y=edges[k].y, w=edges[k].weight;
//		int X = find_parent(get_ID(i, j));
//		int Y = find_parent(get_ID(x, y));
//		if (X != Y) {
//			pa[X] = pa[Y] = pa[get_ID(i, j)] = pa[get_ID(x, y)] = X;
//			ans += w;
//			cnt++;
//		}
//		if(cnt == (N+1)*(M+1)) break;
//	}
//	// output
//	cout << ans << endl;
//	return 0;
//}
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
struct edge {
	int i, j, x, y; int weight;
	edge(int i, int j, int x, int y, int weight) : i(i), j(j), x(x), y(y), weight(weight) {}
};
struct comp {
  bool operator() (edge i,edge j) { return (i.weight<j.weight);}
} comp;
// global variables
int A, B, N, M;
vector<int> VA, HA;
int pa[2010*2010];
vector<edge> edges;
// functions
int ID(int i, int j) {return (i*(M+1))+j; }
int calculateY(int i) {
	if (i == 0) return VA[i];
	return abs(VA[i]-VA[i-1]);
}
int calculateX(int i) {
	if (i == 0) return HA[i];
	return abs(HA[i]-HA[i-1]);
}
int find_parent(int x) {
	if (x != pa[x]) pa[x] = find_parent(pa[x]);
	return pa[x];
}
int merge(int x, int y) {
	int X = find_parent(y);
	int Y = find_parent(x);
	if(X == Y) return false;
	if (X != Y) {
		pa[X] = pa[Y] = pa[y] = pa[x] = X;
	}
	return true;

}
int main() {
	// local variables

	// input
	cin >> A >> B >> N >> M;
	VA.push_back(0); HA.push_back(0);
	for(int i=1; i<=N; i++) {int x; cin >> x; VA.push_back(x); }
	for(int i=1; i<=M; i++) {int x; cin >> x; HA.push_back(x); }
	sort(VA.begin(), VA.end()); sort(HA.begin(), HA.end());
	for(int i=0; i<=N; i++) for(int j=0; j<=M; j++) pa[ID(i,j)] = ID(i, j);
	// main
	for(int i=0; i<N; i++) {
		VA[i] = VA[i+1]-VA[i];
	}
	VA[N] = B-VA[N];
	for(int i=0; i<M; i++) {
		HA[i] = HA[i+1]-HA[i];
	}
	HA[M] = A-HA[M];
	sort(VA.begin(), VA.end()); sort(HA.begin(), HA.end());

	long long ans = 0;
	for(int vi=0, hi=0; vi<=N || hi<=M;) {
		if (hi==M+1 || (vi<=N and VA[vi]<HA[hi])) {
			for(int i=0; i+1<=M; i++) {
				if(merge(ID(vi, i), ID(vi, i+1))) {
					ans += VA[vi];
//					cout << VA[vi] << " <-" << endl;
				}
			}
			vi++;
		} else {
			for(int i=0; i+1<=N; i++) {
				if(merge(ID(i, hi), ID(i+1, hi))) {
					ans += HA[hi];
//					cout << HA[hi] << " <-" << endl;
				}
			}
			hi++;
		}
	}
	// output
	cout << ans << endl;
	return 0;
}

```

# [flow.cpp](#14)
```cpp
//============================================================================
// Name        : cpp_change.cpp
// Author      : Dong Liu
// Website     :
//============================================================================

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

// declare any structures

// declare any global variables

// declare any functions
int convert_to_int(char ch){
	if(islower(ch)) return (ch-'a'+1);
	else return (ch-'A'+27);
}
int main() {
	// declare any local variables
	int N;
	int edge[60][60];
//	int path[60];
	vector<int> path[60];
	// initialize
	for(int i=1; i<=52; i++){
		for(int j=1; j<=52; j++) edge[i][j] = 0;
	}
	cin >> N;
	for(int i=1; i<=N; i++){
		char read_a,read_b; int read_cap;
		cin >> read_a >> read_b >> read_cap;
		int int_a = convert_to_int(read_a);
		int int_b = convert_to_int(read_b);
		edge[int_a][int_b] += read_cap;
		path[int_b].push_back(int_a);
	}
//  main
//	deletion:
	for(int k=1; k<=51; k++){
		for(int i=1; i<=51; i++){
			int counter = 0;
			for(int j=1; j<=52; j++){
				if(edge[i][j]!=0) counter++;
			}
			if(counter==0 && path[i].size()>=0){
				for(int x=0; x<path[i].size(); x++){
					edge[path[i][x]][i]=0;
				}
			}
		}
	}
//  merge
	for(int x=1; x<=52; x++){
		for(int i=1; i<=52; i++){
			int back_counter = 0;
			int p;
			for(int j=1; j<=52; j++){
				if(edge[i][j]!=0){
					p = j;
					back_counter++;
				}
			}
			if(back_counter == 1){
				int front_counter = 0;
				int c;
				for(int j=1; j<=52; j++){
					if(edge[j][i]!=0){
						c = j;
						front_counter++;
					}
				}
				if (front_counter == 1){
					edge[c][p] += min(edge[c][i],edge[i][p]);
					edge[c][i]=edge[i][p]=0;
				}
			}
		}
	}
	// output
	cout<<edge[27][52]<<endl;
	return 0;
}

```

# [fpot.cpp](#15)
```cpp
#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
#include <set>
using namespace std;

struct raindrop {
  int x; int time;
  raindrop(int x, int time) : x(x), time(time) {}
};
struct s2b {
  bool operator() (raindrop i, raindrop j) { return (i.x<j.x);}
} s2b;

int N, D;
vector<raindrop> rdrop;
multiset<int> twoPoint;

long long ans = 1000000000;
int main() {

  cin >> N >> D;
  for(int i=1; i<=N; i++) {
    int x, y; cin >> x >> y;
    rdrop.push_back(raindrop(x, y));
  }
  sort(rdrop.begin(), rdrop.end(), s2b);

  int i=0, j=0;
  twoPoint.insert(rdrop[0].time);
  while(true) {
    if(*twoPoint.rbegin()-*twoPoint.begin() >= D) {
      ans = min(ans, (long long) rdrop[j].x-rdrop[i].x);
      twoPoint.erase(twoPoint.find(rdrop[i++].time));
    } else {
      if (j==N-1) break;
      twoPoint.insert(rdrop[++j].time);
    }
  }
  if(ans != 1000000000) cout << ans << endl;
  else cout << "-1" << endl;
}

```

# [frameup.cpp](#16)
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

# [gpsduel.cpp](#17)
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
struct edge {
	int dest, dist;
	edge(int dest, int dist) : dest(dest), dist(dist) {}
};
#define Pair pair<int, int>
// global variables
int N, M;
vector<edge> adj1[10004], adj2[10004], adj3[10004];
int dist1[10004], dist2[10004], dist3[10004];
// functions
void spath1() {
	dist1[N] = 0;
	priority_queue<Pair, vector<Pair>, greater<Pair> > Q;
	Q.push(Pair(0, N));
	while(!Q.empty()) {
		int i=Q.top().second, d=Q.top().first; Q.pop();
		if(d>dist1[i]) continue;
		for(int j=0; j<adj1[i].size(); j++) {
			if(d+adj1[i][j].dist < dist1[adj1[i][j].dest]) {
				dist1[adj1[i][j].dest] = d+adj1[i][j].dist;
				Q.push(Pair(d+adj1[i][j].dist, adj1[i][j].dest));
			}
		}
	}
}
void spath2() {
	dist2[N] = 0;
	priority_queue<Pair, vector<Pair>, greater<Pair> > Q;
	Q.push(Pair(0, N));
	while(!Q.empty()) {
		int i=Q.top().second, d=Q.top().first; Q.pop();
		if(d>dist2[i]) continue;
		for(int j=0; j<adj2[i].size(); j++) {
			if(d+adj2[i][j].dist < dist2[adj2[i][j].dest]) {
				dist2[adj2[i][j].dest] = d+adj2[i][j].dist;
				Q.push(Pair(d+adj2[i][j].dist, adj2[i][j].dest));
			}
		}
	}
}
void spath3() {
	dist3[1] = 0;
	priority_queue<Pair, vector<Pair>, greater<Pair> > Q;
	Q.push(Pair(0, 1));
	while(!Q.empty()) {
		int i=Q.top().second, d=Q.top().first; Q.pop();
		if(d>dist3[i]) continue;
//		cout << i <<" "<< d << endl;
		for(int j=0; j<adj3[i].size(); j++) {
//			cout << "hi" << endl;
			if(d+adj3[i][j].dist < dist3[adj3[i][j].dest]) {
				dist3[adj3[i][j].dest] = d+adj3[i][j].dist;
				Q.push(Pair(d+adj3[i][j].dist, adj3[i][j].dest));
			}
		}
	}
}
int main() {
	// local variables

	// input
	cin >> N >> M;
	for(int i=1; i<=M; i++) {
		int a,b,p,q; cin >> a >> b >> p >> q;
		adj1[b].push_back(edge(a, p));
		adj2[b].push_back(edge(a, q));
	}
	for(int i=1; i<=N; i++) {
		dist1[i]=dist2[i]=dist3[i]=1000000000;
	}
	// main
	spath1(); spath2();
	for(int i=1; i<=N; i++) {
		for(int j=0; j<adj1[i].size(); j++) {
			int cnt=0, go=adj1[i][j].dest;
			if(dist1[go]-dist1[i] != adj1[i][j].dist) cnt++;
			if(dist2[go]-dist2[i] != adj2[i][j].dist) cnt++;
			adj3[go].push_back(edge(i, cnt));
		}
	}
	// output
	spath3(); cout << dist3[N] << endl;
	return 0;
}

```

# [grove.cpp](#18)
```cpp
//#include <algorithm>
//#include <bitset>
//#include <complex>
//#include <deque>
//#include <exception>
//#include <fstream>
//#include <functional>
//#include <iomanip>
//#include <ios>
//#include <iosfwd>
//#include <iostream>
//#include <istream>
//#include <iterator>
//#include <limits>
//#include <list>
//#include <locale>
//#include <map>
//#include <memory>
//#include <new>
//#include <numeric>
//#include <ostream>
//#include <queue>
//#include <set>
//#include <sstream>
//#include <stack>
//#include <stdexcept>
//#include <streambuf>
//#include <string>
//#include <typeinfo>
//#include <utility>
//#include <valarray>
//#include <vector>
//using namespace std;
//
//// structures / defines
//#define Pair pair<int, int>
//#define x first
//#define y second
//struct node {
//	int i, j, dist, dir; bool up, down, left, right, up1, down1, left1, right1;
//	node(int i, int j, int dist, int dir, bool u, bool d, bool l, bool r,bool u1, bool d1, bool l1, bool r1) : i(i), j(j), dist(dist), dir(dir), up(u), down(d), left(l), right(r), up1(u1), down1(d1), left1(l1), right1(r1) {}
//};
//// global variables
//int N, M;
//int grid[54][54], dist[54][54][2][2][2][2][2][2][2][2];
//Pair start, line;
//int minx, maxx, miny, maxy;
//int X[] = {1, 0, -1, 0, 1, -1, 1, -1};
//int Y[] = {0, 1, 0, -1, 1, -1, -1, 1};
//// functions
//
//int main() {
//	// local variables
//
//	// input
//	cin >> N >> M;
//	minx = miny = 1000000000;
//	maxx = maxy = 0;
//	for(int i=1; i<=N; i++) {
//		string grove; cin >> grove; grove = ' ' + grove;
//		for(int j=1; j<=M; j++) {
//			for(int k=0; k<2; k++)
//				for(int l=0; l<2; l++)
//					for(int n=0; n<2; n++)
//						for(int m=0; m<2; m++)
//							for(int k1=0; k1<2; k1++)
//								for(int l1=0; l1<2; l1++)
//									for(int n1=0; n1<2; n1++)
//										for(int m1=0; m1<2; m1++) dist[i][j][k][l][n][m][k1][l1][n1][m1] = 1000000000;
//			if(grove[j] == 'X') grid[i][j] = 0;
//			else if(grove[j] == '.') grid[i][j] = 1;
//			else if(grove[j] == '*') grid[i][j] = 1;
//			if(grove[j]=='*') start = Pair(i, j);
//			else if(grove[j]=='X') line = Pair(i, j);
//			if(grove[j] == 'X') {
////				cout << "hi" << endl;
//				minx = min(minx, i); miny=min(miny, j);
//				maxx = max(maxx, i); maxy=max(maxy, j);
//			}
//		}
//	}
//	// main
////	cout << minx << " "<<maxx<<" : " << miny << " " << maxy << endl;
////	for(int i=1; i<=N; i++) if(grid[i][line.y]==1) grid[i][line.y]=2;
////	for(int i=1; i<=M; i++) if(grid[line.x][i]==1) grid[line.x][i]=2;
//	queue<node> Q; Q.push(node(start.x, start.y, 0, 1, false, false, false, false, false, false, false, false)); dist[start.x][start.y][0][0][0][0][0][0][0][0]=0;
//	int ans = -1;
//	while(!Q.empty()) {
//		int i=Q.front().i, j=Q.front().j,dir=Q.front().dir, d=Q.front().dist;
//		bool up=Q.front().up, down=Q.front().down, left=Q.front().left, right=Q.front().right;
//		bool up1=Q.front().up1, down1=Q.front().down1, left1=Q.front().left1, right1=Q.front().right1;
//		Q.pop();
//		if(start.x==i && start.y==j && d!=0 && up && down && left && right && up1 && down1 && left1 && right1) {
//			ans=d; break;
//		}
//		if(d > dist[i][j][up][down][left][right][up1][down1][left1][right1]) continue;
////		if(start.x==i && start.y==j)
//			cout << i << " " << j << " : " << d<< " : "<<dist[i][j][up][down][left][right][up1][down1][left1][right1]<<" " << up<<down<<left<<right<<up1<<down1<<left1<<right1  << endl;
////		cout << i << " " << j << " : " << d << endl;
//		for(int k=0; k<8; k++) {
//			int x=i+X[k], y=j+Y[k], nd=d+1;
//			if(x>=1 && x<=N && y>=1 && y<=M && grid[x][y]!=0) {
//				bool u=up, d=down, l=left, r=right;
//				bool u1=up1, d1=down1, l1=left1, r1=right1;
//				if(x<=minx && y<=miny) u=true;
//				if(x>=minx && x<=maxx && y<=miny) d=true;
//				if(x>=maxx && y<=miny) l=true;
//				if(x<=minx && y>=maxy) r=true;
//				if(x>=minx && x<=maxx && y>=maxy) u1=true;
//				if(x>=maxx && y>=maxy) d1=true;
//				if(x<=minx && y>=miny && y<=maxx) l1=true;
//				if(x>=maxx && y>=miny && y<=maxx) r1=true;
//				cout << dist[x][y][u][d][l][r][u1][d1][l1][r1]<<" ; "<<nd<<endl;
//				if(nd<dist[x][y][u][d][l][r][u1][d1][l1][r1]) {
//					dist[x][y][u][d][l][r][u1][d1][l1][r1]=nd;
//					cout << x << ", " << y << endl;
//					Q.push(node(x,y,nd, k, u,d,l,r,u1,d1,l1,r1));
//				}
//			}
//		}
//	}
//	// output
//	cout << ans << endl;
//	return 0;
//}
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
int grid[54][54];
int dist[54][54][2];
int sx=-1, sy=-1, gx=-1, gy=-1;
int X[] = {1, 0, -1, 0, 1, -1, 1, -1};
int Y[] = {0, 1, 0, -1, 1, -1, -1, 1};
// functions
struct node {
	int i, j, d;
	node(int i, int j, int d) : i(i), j(j), d(d) {}
};
int main() {
	// local variables

	// input
	cin >> N >> M;
	for(int i=1; i<=N; i++) {
		string str; cin >> str; str = ' ' + str;
		for(int j=1; j<=M; j++) {
			dist[i][j][0]=dist[i][j][1]=1000000000;
			if(str[j]=='X') {
				grid[i][j]=2;
//				if(gx==-1)
					gx=i, gy=j;
			}
			if(str[j]=='.' || str[j]=='*') {
				grid[i][j]=1;
				if(str[j]=='*') sx=i, sy=j;
			}
		}
	}
	dist[sx][sy][0]=0;
	queue<node>q;
    q.push(node(sx, sy, 0));
    while (!q.empty()) {
        node f = q.front();
        int p = dist[f.i][f.j][f.d];
        q.pop();
        for (int k=0; k<8; k++) {
            node go = node(f.i+X[k], f.j+Y[k], f.d);
            if (go.i<1 || go.i>N || go.j<1 || go.j>M){
            	continue;
            }
            if (grid[go.i][go.j] == 2) continue;
            if (f.i==gx-1 && go.i==gx && go.j<gy){
//            	cout << "2) "<<go.i<<" " << go.j<<endl;
            	continue;
            }
            if (f.i==gx && go.i==gx - 1 && go.j<gy) {
            	go.d++;
//            	cout << " hi  ...."<<endl;
                if (go.d > 1) continue;
            }
            if (p+1 < dist[go.i][go.j][go.d]) {
                dist[go.i][go.j][go.d] = p + 1;
                q.push(go);
            }
        }
    }
    cout << dist[sx][sy][1] << endl;
	// main

	// output

	return 0;
}

```

# [jobhunt.cpp](#19)
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
struct edge {
	int dest, dist;
	edge(int dest, int dist) : dest(dest), dist(dist) {}
};
// global variables
int D, P, C, F, S;
vector<edge> edges[224];
int dist[224];

// functions

int main() {
	// local variables

	// input
	cin >> D >> P >> C >> F >> S;
	for(int i=1; i<=P; i++) {
		int a, b; cin >> a >> b;
		edges[a].push_back(edge(b, -D));
	}
	for(int i=1; i<=C; i++) {
		dist[i] = 1000000000;
	}
	for(int i=1; i<=F; i++) {
		int a, b, d; cin >> a >> b >> d;
		edges[a].push_back(edge(b, d-D));
	}
	// main
    dist[S] = 0;
    bool NotnegativeCycle = true;
    for	(int i=1; i<=C; i++) {
    	NotnegativeCycle = true;
        for (int u=1; u<=C; u++) {
            for (int j=0; j<edges[u].size(); j++) {
                int v = edges[u][j].dest;
                int c = edges[u][j].dist;
                if(dist[u]+c < dist[v]) {
                	NotnegativeCycle = false;
                    dist[v] = dist[u]+c;
                }
            }
        }
    }
	// output
    if(!NotnegativeCycle) cout<<"-1"<<endl;
    else {
    	int ans = 1000000000;
    	for(int i=1; i<=C; i++) {
    		ans = min(ans, dist[i]);
    	}
    	cout << D-ans << endl;
    }

	return 0;
}

```

# [lilypad.cpp](#20)
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
#define Pair pair<long long, long long>
#define x1 first
#define y1 second
// global variables
long long N, M;
long long pond[40][40];
long long adj[40][40][40][40];
Pair Start, End;
long long dist[40][40], ways[40][40];
long long X[8] = {-2,-1,+1,+2,+2,+1,-1,-2};
long long Y[8] = {-1,-2,-2,-1,+1,+2,+2,+1};
// functions

int main() {
	// local variables

	// input
	cin >> N >> M;
	for(long long i=1; i<=N; i++) {
		for(long long j=1; j<=M; j++) {
			cin >> pond[i][j];
			dist[i][j] = -1;
			ways[i][j] = 0;
			if (pond[i][j] == 3) {
				Start = Pair(i, j);
				pond[i][j] = 0;
			} else if (pond[i][j] == 4) {
				End = Pair(i, j);
				pond[i][j] = 0;
			}
		}
	}
	// main
	for(long long i=1; i<=N; i++) {
		for(long long j=1; j<=M; j++) {
			if(pond[i][j] == 0) {
				queue<Pair> Q;
				Q.push(Pair(i,j));
			    adj[i][j][i][j] = 1;
			    while(!Q.empty()) {
			    	long long x=Q.front().x1;
			    	long long y=Q.front().y1;
			    	Q.pop();
			    	for (long long k=0; k<8; k++) {
			    		long long nx = x+X[k];
			    		long long ny = y+Y[k];
						if (nx >= 1 && nx <= N && ny>=1 && ny<=M && pond[nx][ny]==1 && adj[i][j][nx][ny] == 0) {
							Q.push(Pair(nx, ny));
							adj[i][j][nx][ny] = 1;
						}
			    	}
			    }
			    for(long long x=1; x<=N; x++) {
			    	for(long long y=1; y<=M; y++) {
			    		if(adj[i][j][x][y] == 1) {
							for(long long k=0; k<8; k++) {
								long long nx = x+X[k];
								long long ny = y+Y[k];
								if(nx >= 1 && nx <= N && ny>=1 && ny<=M && pond[nx][ny]==0 && adj[i][j][nx][ny] == 0) {
									adj[i][j][nx][ny] = 2;
								}
							}
			    		}
			    	}
			    }
			}
		}
	}
	dist[Start.x1][Start.y1] = 0;
	ways[Start.x1][Start.y1] = 1;
	queue<Pair> Q;
	Q.push(Pair(Start.x1,Start.y1));
	while (!Q.empty()) {
		long long x=Q.front().x1;
		long long y=Q.front().y1;
		Q.pop();

//		cout << x << " " << y << " d: " << dist[x][y] << endl;
		for(long long i=1; i<=N; i++) {
			for(long long j=1; j<=M; j++) {
				if(adj[x][y][i][j] == 2) {
					if(dist[i][j] == -1) {
						dist[i][j] = dist[x][y]+1;
						ways[i][j] = ways[x][y];
						Q.push(Pair(i, j));
					} else if(dist[i][j] == dist[x][y]+1) {
						ways[i][j] += ways[x][y];
					}
				}
			}
		}
	}
	if (dist[End.x1][End.y1]==-1) cout << "-1" << endl;
	else cout << dist[End.x1][End.y1]-1<<endl<<ways[End.x1][End.y1]<<endl;
	return 0;
}

```

# [photo.cpp](#21)
```cpp
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#define MAX_N 20001

int N;
map<int, int> possible[5];
int line[MAX_N];

bool compare(int a, int b) {
  int r_value = 0;
  for(int i=0; i<5; i++) {
    if(possible[i][a] < possible[i][b]) r_value++;
  }
  return r_value > 2;
}
int main() {

  cin >> N;
  for(int i=0; i<5; i++) {
    for(int j=0; j<N; j++) {
      int read; cin >> read;
      possible[i][read]=j;
      line[j]=read;
    }
  }

  sort(line, line+N, compare);

  for(int i=0; i<N; i++) {
    cout << line[i] << endl;
  }

}

```

# [piepie.cpp](#22)
```cpp
//#include <algorithm>
//#include <bitset>
//#include <complex>
//#include <deque>
//#include <exception>
//#include <fstream>
//#include <functional>
//#include <iomanip>
//#include <ios>
//#include <iosfwd>
//#include <iostream>
//#include <istream>
//#include <iterator>
//#include <limits>
//#include <list>
//#include <locale>
//#include <map>
//#include <memory>
//#include <new>
//#include <numeric>
//#include <ostream>
//#include <queue>
//#include <set>
//#include <sstream>
//#include <stack>
//#include <stdexcept>
//#include <streambuf>
//#include <string>
//#include <typeinfo>
//#include <utility>
//#include <valarray>
//#include <vector>
//using namespace std;
//// structures / defines
//struct node {
//	int i, j; long long weight;
//	node(int i, int j, long long weight) : i(i), j(j), weight(weight) {}
//};
//struct abc {
//	int i, j; long long dist;
//	abc(int i, int j, long long dist) : i(i), j(j), dist(dist) {}
//};
//struct comp {
//	bool operator() (abc a, abc b) const {
//		return a.dist<b.dist;
//	}
//};
//// global variables
//#define Pair pair<int, int>
//int A, B, N, M;
//vector<long long> VA, HA;
//map<int, vector<node> > edge[2010];
//map<int, bool> visited[2010];
//map<int, int> dist[2010];
//// functions
//long long calculateY(int i) {
//	if (i == 0) return VA[i];
//	return abs(VA[i]-VA[i-1]);
//}
//long long calculateX(int i) {
//	if (i == 0) return HA[i];
//	return abs(HA[i]-HA[i-1]);
//}
//int main() {
//	// local variables
//
//	// input
//	cin >> A >> B >> N >> M;
//	for(int i=1; i<=N; i++) { int x; cin >> x; VA.push_back(x); }
//	VA.push_back(A);
//	for(int i=1; i<=M; i++) { int x; cin >> x; HA.push_back(x); }
//	HA.push_back(B);
//	sort(VA.begin(), VA.end()); sort(HA.begin(), HA.end());
//	// main
//	// create graph
//	for(int i=0; i<=N; i++) {
//		for(int j=0; j<=M; j++) {
//			visited[i][j] = false;
//			int x = i+1;
//			int y = j;
//			if(x >= 0 and x <= N and y >= 0 and y <= M) {
//				int weight = calculateX(j);
//				edge[i][j].push_back(node(x, y, weight));
//				edge[x][y].push_back(node(i, j, weight));
//			}
//			x--; y++;
//			if(x >= 0 and x <= N and y >= 0 and y <= M) {
//				int weight = calculateY(i);
//				edge[i][j].push_back(node(x, y, weight));
//				edge[x][y].push_back(node(i, j, weight));
//			}
//		}
//	}
//	// mst
//	int msted = 0;
//	long long ans = 0;
//	multiset<abc, comp> Q;
//	Q.insert(abc(0, 0, 0));
//	while(!Q.empty()) {
//		abc f = *Q.begin();
//		Q.erase(Q.begin());
////		cout << f.dist <<" < - "<< f.i << " " << f.j << endl;
//		if(visited[f.i][f.j]) continue;
//		ans += f.dist;
//		visited[f.i][f.j] = true; msted++;
//		if(msted == (N+1)*(M+1)) {
////			cout << msted << endl;
//			break;
//		}
//
//		for(int i=0; i<edge[f.i][f.j].size(); i++) {
//			int x=edge[f.i][f.j][i].i;
//			int y=edge[f.i][f.j][i].j;
//			if(!visited[x][y]){
//				Q.insert(abc(x,y,edge[f.i][f.j][i].weight));
//			}
//		}
//	}
//	// output
//	cout << ans << endl;
//	return 0;
//}
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
	int i, j; long long weight;
	node(int i, int j, long long weight) : i(i), j(j), weight(weight) {}
};
struct abc {
	int i, j; long long dist;
	abc(int i, int j, long long dist) : i(i), j(j), dist(dist) {}
};
struct comp {
	bool operator() (abc const&a, abc const&b){
		return a.dist>b.dist;
	}
};
struct s2b2 {
  bool operator() (int i,int j) { return (i<j);}
} s2b;
// global variables
#define Pair pair<int, int>
long long A, B; int N, M;
vector<int> VA, HA;
bool visited[2010*2010];
// functions
long long calculateY(int i) {
	if (i == 0) return VA[i];
	return abs(VA[i]-VA[i-1]);
}
long long calculateX(int i) {
	if (i == 0) return HA[i];
	return abs(HA[i]-HA[i-1]);
}
bool valid(int i, int j) {
	return (i>=0 and i<=N and j>=0 and j<=M);
}
int v(int i, int j) {
	return (i*(N+1))+j;
}
int main() {
	// local variables

	// input
	cin >> A >> B >> N >> M;
	for(int i=1; i<=N; i++) { int x; cin >> x; VA.push_back(x); }
	VA.push_back(A);
	for(int i=1; i<=M; i++) { int x; cin >> x; HA.push_back(x); }
	HA.push_back(B);
	for(int i=0; i<=N; i++) {
		for(int j=0; j<=M; j++) {
			visited[v(i, j)] = false;
		}
	}
	sort(VA.begin(), VA.end(), s2b);
	sort(HA.begin(), HA.end(), s2b);
	// main
	int msted = 0;
	long long ans = 0;
	priority_queue<abc, vector<abc>, comp> Q;
	Q.push(abc(0, 0, 0));
	while(!Q.empty()) {
		abc f = Q.top();
		Q.pop();
		if(visited[v(f.i,f.j)]) continue;
		ans += (long long) f.dist;
		visited[v(f.i,f.j)] = true; msted++;
		if(msted == (N+1)*(M+1)) {
			break;
		}
		int x, y;

		x=f.i+1, y=f.j;
		if (valid(x,y) and !visited[v(x,y)]) {
			int weight = calculateX(y);
			Q.push(abc(x,y,weight));
		}

		x=f.i, y=f.j+1;
		if (valid(x,y) and !visited[v(x,y)]) {
			int weight = calculateY(x);
			Q.push(abc(x,y,weight));
		}

		x=f.i-1, y=f.j;
		if (valid(x,y) and !visited[v(x,y)]) {
			int weight = calculateX(y);
			Q.push(abc(x,y,weight));
		}

		x=f.i, y=f.j-1;
		if (valid(x,y) and !visited[v(x,y)]) {
			int weight = calculateY(x);
			Q.push(abc(x,y,weight));
		}
	}
	// output
	cout << ans << endl;
	return 0;
}

```

# [planting.cpp](#23)
```cpp
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
#define PPair pair<Pair, Pair>
struct interval {
	int Axis, pIn; bool on;
	interval(int Axis, int pIn, bool on): Axis(Axis), pIn(pIn), on(on) {}
};
struct s2b {
  bool operator() (interval i,interval j) { return (i.Axis<j.Axis);}
} s2b;
// global variables
int N;
PPair rectangle[1004];
vector<interval> I, I2;
bool mark[1004];
// functions

int main() {
	// local variables

	// input
	cin >> N;
	for(int i=1; i<=N; i++) {
		int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
//		x2++, y1++;
		rectangle[i] = PPair(Pair(x1, y2), Pair(x2, y1));
		I.push_back(interval(x1, i, true));
		I.push_back(interval(x2, i, false));
		mark[i] = false;
	}
	sort(I.begin(), I.end(), s2b);

	// main
	long long ans = 0;
	for(int i=0; i<I.size(); i++){
		if(i>0) {
			long long distX = I[i].Axis-I[i-1].Axis;
			I2.clear();
			for(int j=1; j<=N; j++) {
				if(mark[j]) {
					I2.push_back(interval(rectangle[j].first.second, j, true));
					I2.push_back(interval(rectangle[j].second.second, j, false));
				}
			}
			sort(I2.begin(), I2.end(), s2b);
			long long distY = 0; int onY = 0;
			for(int j=0; j<I2.size(); j++) {
				if(onY > 0) {
					distY += I2[j].Axis-I2[j-1].Axis;
				}
				if(I2[j].on) onY++;
				else if (!I2[j].on) onY--;
			}
			ans += distX*distY;
//			cout << distX <<  " " << distY << endl;
		}
		if(I[i].on) mark[I[i].pIn] = true;
		else if(!I[i].on) mark[I[i].pIn] = false;
	}

	// output
	cout << ans << endl;

	return 0;
}

```

# [poker.cpp](#24)
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
int N;
int card[100004];
// functions

int main() {
	// local variables

	// input
	cin >> N;
	card[0] = 0, card[N+1] = 0;
	for(int i=1; i<=N; i++) cin >> card[i];
	long long ans = 0;
	for(int i=0; i<=N; i++) {
		ans += abs((long long) card[i+1]-card[i]);
	}
	// main
	cout << ans/2 << endl;
	// output

	return 0;
}

```

# [pwrfail.cpp](#25)
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
#include <math.h>
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
// global variables
int N; int W; double M;
Pair l[1004];
double edge[1004][1004];
bool visited[1004];
double dist[1004];
// functions
double sq(double a) {return a*a;}
int main() {
	// local variables

	// input
	cin >> N >> W >> M;
	for(int i=1; i<=N; i++) {
		cin >> l[i].x >> l[i].y;
		visited[i] = false; dist[i] = -1.0;
	}
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			double dist = sqrt(sq(abs(l[i].x-l[j].x))+sq(abs(l[i].y-l[j].y)));
			if (dist<M) {
				edge[i][j] = dist;
			} else edge[i][j] = -1;
		}
	}
	for(int i=1; i<=W; i++) {
		int x,y; cin >> x >> y;
		edge[x][y]=edge[y][x]= 0;
	}
	// main
	dist[1] = 0.0;
	while(true) {
		int k = -1;
		for(int i=1; i<=N; i++) {
			if(dist[i]!=-1 && !visited[i] && (k==-1 || dist[k]>dist[i])) {
				k=i;
			}
		}
		if(k == -1) break;
		visited[k] = true;
		for(int i=1; i<=N; i++) {
			if(edge[i][k] == -1) continue;
			double ndist = dist[k]+edge[k][i];
			if(dist[i]==-1 || dist[i]>ndist) {
				dist[i] = ndist;
			}
		}
	}
	// output
	if(dist[N] == -1) cout <<"-1"<<endl;
	else {double final = dist[N];
	int f = dist[N]*1000;
	cout << f << endl;}
	return 0;
}

```

# [rblock.cpp](#26)
```cpp
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

// global variables
int N, M;
int edge[105][105];
int dist[105]; bool visited[105];
map<int, int> parent;
// functions
int shortestPath(bool P) {
	memset(dist, -1, sizeof(int)*(N+1));
	memset(visited, false, sizeof(bool)*(N+1));
	dist[1] = 0;

	while(true) {
		int k = -1;
		for(int i=1; i<=N; i++) {
			if(dist[i]!=-1 && !visited[i] && (k==-1 || dist[i]<dist[k])){
				k = i;
			}
		}
		if(k == -1) break;
		visited[k] = true;
		for(int i=1; i<=N; i++){
			if(edge[k][i] == 0) continue;
			int go = i;
			int ndist = dist[k] + edge[k][i];
			if(dist[go] == -1 || ndist < dist[go]){
				if(P) parent[go] = k;
				dist[go] = ndist;
			}
		}
	}
	return dist[N];
}
int main() {
	// local variables

	// input
	cin >> N >> M;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) edge[i][j] = 0;
	}
	for(int i=1; i<=M; i++) {
		int x, y, weight; cin >> x >> y >> weight;
		edge[x][y] = edge[y][x] = weight;
	}
	// main
	int preAns = shortestPath(true);
	int b = N;
	int c = 0;
	int ans = 0;
	while(true) {
		c = parent[b];
		if (c == 0) break;

		edge[b][c] *= 2;
		edge[c][b] *= 2;
		ans = max(ans, shortestPath(false)-preAns);
		edge[b][c] /= 2;
		edge[c][b] /= 2;

		b = c;
	}
	// output
	cout << ans << endl;
	return 0;
}

```

# [rplow2.cpp](#27)
```cpp
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
#define PPair pair<Pair, Pair>
#define x first
#define y second
struct interval {
	int xAxis; int pIn; bool open;
	interval(int xAxis, int pIn, bool open) : xAxis(xAxis), pIn(pIn), open(open) {}
};
struct s2b {
  bool operator() (interval i,interval j) { return (i.xAxis<j.xAxis);}
} s2b;
// global variables
int X, Y, I;
PPair Plow[1004];
bool visited[1004];
vector <interval> inter;
// functions

int main() {
	// local variables

	// input
	cin >> X >> Y >> I;
	for(int i=1; i<=I; i++) {
		cin >> Plow[i].x.x >> Plow[i].x.y >> Plow[i].y.x >> Plow[i].y.y;
		inter.push_back(interval(Plow[i].x.x, i, true));
		inter.push_back(interval(Plow[i].y.x+1, i, false));
		visited[i] = false;
	}
	sort(inter.begin(), inter.end(), s2b);
	// main
	int ans = 0;
	for(int i=0; i<(I*2); i++) {
		if(i!=0) {
			int dist = inter[i].xAxis-inter[i-1].xAxis;
//			if(i !=(I*2)-1 && i != 1) dist++;
			vector<interval> inter2;
			for(int j=1; j<=I; j++) {
				if(visited[j]) {
					inter2.push_back(interval(Plow[j].x.y, j, true));
					inter2.push_back(interval(Plow[j].y.y+1, j, false));
				}
			}
			sort(inter2.begin(), inter2.end(), s2b);
			int on = 0;
			int add = 0;
//			cout << "inter2size: "<<inter2.size()<<endl;
			for(int j=0; j<(inter2.size()); j++) {
//				cout << inter2[j].xAxis<<endl;
				if(j!=0 && on>0){
					add += inter2[j].xAxis-inter2[j-1].xAxis;
//					cout << "adding: "<<inter2[j].xAxis-inter2[j-1].xAxis<<endl;
				}
				if(inter2[j].open) {
					on++;
				} else on--;
			}
//			add++;
			ans += dist*add;
//			cout << dist << ". "<<add<<endl;
		}
		if(inter[i].open) visited[inter[i].pIn]=true;
		if(!inter[i].open) visited[inter[i].pIn]=false;

	}
	cout << ans << endl;
	// output

	return 0;
}

```

# [shopping.cpp](#28)
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
#define Pair pair<int, int>
#define productCode first
#define items second
struct offer {
	int numberProducts, reducedPrice;
	vector<Pair> products;
};
struct product {
	int code, purchased, price;
};
// global variables
int S, B;
offer offers[100];
// functions
product products[6];
int index1[1000];
int dp[6][6][6][6][6];
int main() {
	// local variables
	for(int a=0; a<=5; a++) {
		for(int b=0; b<=5; b++) {
			for(int c=0; c<=5; c++) {
				for(int d=0; d<=5; d++) {
					for(int e=0; e<=5; e++) {
						dp[a][b][c][d][e] = 1000000000;
					}
				}
			}
		}
	}
	// input
	cin >> S;
	for(int i=1; i<=S; i++) {
		cin >> offers[i].numberProducts;

		for(int j=1; j<=offers[i].numberProducts; j++) {
			int Code, Item; cin >> Code >> Item;
			offers[i].products.push_back(Pair(Code, Item));
		}
		cin >> offers[i].reducedPrice;
	}
	cin >> B;
	for(int i=1; i<=B; i++) {
		cin >> products[i].code >> products[i].purchased >> products[i].price;
		index1[products[i].code] = i;
	}
	for(int i=B+1; i<=5; i++) {
		products[i].code = -1, products[i].purchased = 0, products[i].price = 1000000000;
	}
	// main
	dp[0][0][0][0][0] = 0;
	for(int i=1; i<=S; i++) {
		int pa, pb, pc, pd, pe; pa=pb=pc=pd=pe=0;
		for(int j=0; j<offers[i].numberProducts; j++) {
			int in = index1[offers[i].products[j].productCode];
			if (in == 1) pa += offers[i].products[j].items;
			if (in == 2) pb += offers[i].products[j].items;
			if (in == 3) pc += offers[i].products[j].items;
			if (in == 4) pd += offers[i].products[j].items;
			if (in == 5) pe += offers[i].products[j].items;
		}
		for(int a=0; a<=5; a++) {
			for(int b=0; b<=5; b++) {
				for(int c=0; c<=5; c++) {
					for(int d=0; d<=5; d++) {
						for(int e=0; e<=5; e++) {
							int na=a+pa, nb=b+pb, nc=c+pc, nd=d+pd, ne=e+pe;
							if(na<=products[1].purchased && nb<=products[2].purchased && nc<=products[3].purchased && nd<=products[4].purchased && ne<=products[5].purchased) {
								dp[na][nb][nc][nd][ne] = min(dp[na][nb][nc][nd][ne], dp[a][b][c][d][e]+offers[i].reducedPrice);
							}
						}
					}
				}
			}
		}
	}
	for(int i=1; i<=B; i++) {
		int pa, pb, pc, pd, pe; pa=pb=pc=pd=pe=0;
		if (i == 1) pa += 1;
		if (i == 2) pb += 1;
		if (i == 3) pc += 1;
		if (i == 4) pd += 1;
		if (i == 5) pe += 1;
		for(int a=0; a<=5; a++) {
			for(int b=0; b<=5; b++) {
				for(int c=0; c<=5; c++) {
					for(int d=0; d<=5; d++) {
						for(int e=0; e<=5; e++) {
							int na=a+pa, nb=b+pb, nc=c+pc, nd=d+pd, ne=e+pe;
							if(na<=products[1].purchased && nb<=products[2].purchased && nc<=products[3].purchased && nd<=products[4].purchased && ne<=products[5].purchased) {
								dp[na][nb][nc][nd][ne] = min(dp[na][nb][nc][nd][ne], dp[a][b][c][d][e]+products[i].price);
							}
						}
					}
				}
			}
		}
	}
	// output
	cout << dp[products[1].purchased][products[2].purchased][products[3].purchased][products[4].purchased][products[5].purchased] << endl;
	return 0;
}

```

# [skyline.cpp](#29)
```cpp
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
#define X first
#define Y second
// global variables
int N; int W;
Pair change[50004];
// functions

int main() {
	// local variables

	// input
	cin >> N >> W;
	for(int i=1; i<=N; i++) {
		cin >> change[i].X >> change[i].Y;
	}
	stack<int> S;
	S.push(0); int in=1;
	int ans = 0;
	while(in<=N && !S.empty()) {
		if(change[in].Y > S.top()) {
			S.push(change[in].Y);
			ans++; in++;
		} else if (change[in].Y < S.top()) {
			while(true) {
				S.pop();
				if(S.empty()) break;
				if(S.top() <= change[in].Y) break;
			}
			if(S.empty()) break;
			if(S.top() < change[in].Y) {
				S.push(change[in].Y);	ans++;
			}
			in++;
//			}

		} else S.pop();
	}
	// main
	cout << ans << endl;
	// output

	return 0;
}

```

# [sparty.cpp](#30)
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
int N, M, X;
int edge[1004][1004];
bool visited[1004];
int dist[1004], dist2[1004];
int ans = 0;
// functions
void shortestPath() {
	for(int i=1; i<=N; i++) {
		visited[i]=false;
		dist[i]=-1;
	}
	dist[X] = 0;
	while(true) {
		int k=-1;
		for(int i=1; i<=N; i++) {
			if(dist[i]!=-1 && !visited[i] && (k==-1 || dist[k]>dist[i])) {
				k=i;
			}
		}
		if(k==-1) break;
		visited[k]=true;
		for(int i=1; i<=N; i++) {
			if(edge[k][i] == 0) continue;
			int ndist = dist[k]+edge[k][i];
			if((dist[i]==-1 || dist[i]>ndist)) {
				dist[i] = ndist;
			}
		}
	}
}
void shortestPath2() {
	for(int i=1; i<=N; i++) {
		visited[i]=false;
		dist2[i]=-1;
	}
	dist2[X] = 0;
	while(true) {
		int k=-1;
		for(int i=1; i<=N; i++) {
			if(dist2[i]!=-1 && !visited[i] && (k==-1 || dist2[k]>dist2[i])) {
				k=i;
			}
		}
		if(k==-1) break;
		visited[k]=true;

		for(int i=1; i<=N; i++) {
			if(edge[i][k]==0) continue;
			int ndist = dist2[k] +edge[i][k];
			if((dist2[i]==-1 || dist2[i]>ndist)) {
				dist2[i]=ndist;
			}
		}
	}
}
int main() {
	// local variables

	// input
	cin >> N >> M >> X;
	for(int i=1; i<=M; i++) {
		int a, b, d; cin >> a >> b >> d;
		edge[a][b] = d;
	}
	// main
	shortestPath();
	shortestPath2();
	// output
	for(int i=1; i<=N; i++) ans = max(ans, dist[i]+dist2[i]);
	cout << ans << endl;
	return 0;
}

```

# [split.cpp](#31)
```cpp
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
#define Pair pair<long long, long long>
#define x first
#define y second
struct s2bx {
  bool operator() (Pair i,Pair j) { return (i.x<j.x); }
} s2bx;
struct s2by {
  bool operator() (Pair i,Pair j) { return (i.y<j.y); }
} s2by;

// global variables
int N;
vector<Pair> cow;
Pair mininum, maxinum;
multiset<long long> small, big;
multiset<long long> up, down, left1, right1;
// functions

int main() {
	// local variables

	// input
	cin >> N;
	mininum.x = mininum.y = 1000000001;
	maxinum.x = maxinum.y = 0;
	for(int i=0; i<N; i++) {
		long long a,b; cin >> a >> b;
		mininum.x = min(mininum.x, a);
		mininum.y = min(mininum.y, b);
		maxinum.x = max(maxinum.x, a);
		maxinum.y = max(maxinum.y, b);
		cow.push_back(Pair(a,b));
	}
	long long oneEnclosure = (maxinum.x-mininum.x)*(maxinum.y-mininum.y);
	long long twoEnclosure = oneEnclosure;

	// main
	sort(cow.begin(), cow.end(), s2bx);
	for(int i=0; i<N; i++) {

		right1.insert(cow[i].x);
		up.insert(cow[i].y);
	}
	for(int i=0; i<N-1; i++) {
		right1.erase(right1.find(cow[i].x));
		up.erase(up.find(cow[i].y));
		left1.insert(cow[i].x);
		down.insert(cow[i].y);
		twoEnclosure = min(twoEnclosure,(long long)(*up.rbegin()-*up.begin())*(long long)(*right1.rbegin()-*right1.begin())
				+(*down.rbegin()-*down.begin())*(long long)(*left1.rbegin()-*left1.begin()));
	}
	left1.clear(); right1.clear(); down.clear(); up.clear();

	sort(cow.begin(), cow.end(), s2by);
	for(int i=0; i<N; i++) {
		right1.insert(cow[i].x);
		up.insert(cow[i].y);
	}
	for(int i=0; i<N-1; i++) {
		right1.erase(right1.find(cow[i].x));
		up.erase(up.find(cow[i].y));
		left1.insert(cow[i].x);
		down.insert(cow[i].y);
		twoEnclosure = min(twoEnclosure,(long long)(*up.rbegin()-*up.begin())*(long long)(*right1.rbegin()-*right1.begin())
						+(*down.rbegin()-*down.begin())*(long long)(*left1.rbegin()-*left1.begin()));
	}
	// output
	cout << (oneEnclosure-twoEnclosure) << endl;
	return 0;
}

```

# [squares.cpp](#32)
```cpp
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

```

# [superbull.cpp](#33)
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

```

# [traffic.cpp](#34)
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

# [ttravel.cpp](#35)
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

```

# [wall.cpp](#36)
```cpp
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
struct s2b {
  bool operator() (Pair i,Pair j) { return (i.second<j.second);}
} s2b;
// global variables
int H, F;
vector<Pair> hoofHold;
queue<Pair> Q;
bool visited[10004];
// functions
int sq(int a) { return a*a; }
int main() {
	// local variables

	// input
	cin >> H >> F;
	for(int i=0; i<F; i++) {
		int x, y; cin >> x >> y;
		hoofHold.push_back(Pair(x, y));
		visited[i] = false;
	}
	sort(hoofHold.begin(), hoofHold.end(), s2b);
	for(int i=0; i<F; i++) {
		if(hoofHold[i].second <= 1000) { Q.push(Pair(i, 1)); visited[i] = true; }
		else break;
	}
	// main
	int ans = 0;
	while(!Q.empty()) {
		int hold=Q.front().first, moves=Q.front().second;
		Q.pop();

		if(hoofHold[hold].second >= H-1000) { ans = moves; break; }

		int minI = hold;
		while((minI != 0) && (abs(hoofHold[minI-1].second-hoofHold[hold].second) <= 1000)) {
			minI--;
		}

		int maxI = hold;
		while((maxI != F-1) && (abs(hoofHold[maxI+1].second-hoofHold[hold].second) <= 1000)) {
			maxI++;
		}

		for(int i=minI; i<=maxI; i++) {
			if(sq(abs(hoofHold[i].first-hoofHold[hold].first))+
				sq(abs(hoofHold[i].second-hoofHold[hold].second))
					<= 1000000) {
				if(!visited[i]) {
					visited[i] = true;
					Q.push(Pair(i, moves+1));
				}
			}
		}
	}
	cout << ans << endl;
	// output

	return 0;
}

```

# [water.cpp](#37)
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
	int i, weight;
	node(int i, int weight) : i(i), weight(weight) {}
};
struct comp{
    bool operator()(const node& a, const node& b) {
    	return a.weight>b.weight;
    }
};
// global variables
int N;
int W[304];
bool visited[304];
int P[304][304];
// functions

int main() {
	// local variables

	// input
	cin >> N;
	for(int i=1; i<=N; i++) cin >> W[i];
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			cin >> P[i][j];
		}
	}
	// main
	priority_queue<node, vector<node>, comp> Q;
	for(int i=1; i<=N; i++) {
		Q.push(node(i, W[i]));
		visited[i] = false;
	}
	long long ans = 0;
	while(!Q.empty()) {
		int i = Q.top().i;
		int weight = Q.top().weight;
		Q.pop();
		if(!visited[i]) {
			ans += weight; visited[i] = true;
			for(int j=1; j<=N; j++){
				if(!visited[j]) {
					Q.push(node(j, P[i][j]));
				}
			}
		}
	}
	// output
	cout << ans << endl;
	return 0;
}

```

