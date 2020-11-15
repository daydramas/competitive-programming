<div align="center"> [248.cpp](#0) | [closing.cpp](#1) | [split.cpp](#2) </div>

# [248.cpp](#0)
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
int N, number[250];
int DP[250][250];
// declare any functions
int main() {

	// fstream
	ifstream fin ("248.in");
	ofstream fout ("248.out");

	// input
	fin >> N;
	for(int i=1; i<=N; i++) fin >> number[i];
	for(int i=1; i<=N; i++) DP[i][i] = number[i];
	// main
	int ans = 0;
	for(int length=1; length<=N; length++){
		for(int i=1; (i+length-1)<=N; i++){
			int j = (i+length-1);
			for(int k=1; k<j; k++){
				if(DP[i][k]==DP[k+1][j] and DP[i][k]!=0){
					DP[i][j] = max(DP[i][j], DP[i][k]+1);
				}
			}
			ans = max(ans, DP[i][j]);
		}
	}
	// output
	fout << ans << endl;
	//close
	fout.close();
	return 0;
}

```

# [closing.cpp](#1)
```cpp
///*
// ID: dongliu3
// TASK: closing
// LANG: C++
// */
//
//#include <bits/stdc++.h>
//using namespace std;
//
//// structures/defines
//
//// global variables
//int N, M;
//vector<int> adj[200005], noroot;
//bool mark[200005], unmark[200005];
//bool ans[200005];
//int close[200005];
////int max0, total0;
////functions
//
//int main() {
//	// local variables
//
//	// fstream
//	ifstream fin("3.in");
//	ofstream fout("closing.out");
//
//	// input
//	fin >> N >> M;
//	for (int i = 1; i <= M; i++) {
//		int a, b;
//		fin >> a >> b;
//		if (a == b)
//			continue;
//		adj[a].push_back(b);
//		adj[b].push_back(a);
////		cout << a << " " << b << endl;
//	}
//	for (int i = 1; i <= N; i++) {
//		fin >> close[i];
//		mark[i] = false;
//	}
//	mark[close[N]] = true;
//	int unroot=0;
////	cout << "mark " << close[N] << endl;
//	for (int i = N; i >= 1; i--) {
//		int c = close[i];
//		if (mark[c]) {
//			for (int j : adj[c]) {
//				mark[j] = true;
////				cout << "mark " << j << endl;
//			}
////			vector<int> temp;
////			for(int j : noroot) {
////				temp.push_back(j);
////			}
////			for (int j : noroot) {
//////				cout << "noroot " << j << endl;
////				if (mark[j]) {
////					noroot.erase(find(noroot.begin(), noroot.end(), j));
////				}
////			}
//			while(!noroot.empty()) {
//				int b = noroot.back();
//				if(mark[b]) {
//					noroot.pop_back();
//					for (int j : adj[b]) {
//						mark[j] = true;
//					}
//				} else {
//					break;
//				}
//			}
//		} else {
//			noroot.push_back(c);
//			unroot++;
//		}
//		if (noroot.empty()) {
//			ans[i] = true;
//			cout<<"YES i: "<<close[i]<<endl;
//		} else {
//			ans[i] = false;
//			cout<<"NO i: "<<close[i]<<" "<<noroot.back()<<endl;
//		}
//	}
//	for(int i=1; i<=N; i++) {
//		if(ans[i]) {
//			fout <<"YES"<<endl;
//		} else fout <<"NO"<<endl;
//	}
////	max0 = 0, total0 = 0;
////	for (int i = 1; i <= N; i++) {
////		mark[i] = false;
////		if (adj[i].empty()) {
////			total0++;
////		}
////	}
//	// main
////	for (int i = 1; i <= N; i++, max0++) {
//////		cout << total0 << " " << max0 << endl;
////		if (total0 <= max0 || i==N) {
////			fout << "YES" << endl;
////		} else {
////			fout << "NO" << endl;
////		}
////		int a;
////		fin >> a;
////		if (!mark[a]) {
//////		cout << "mark " << a << endl;
////			total0++;
////			mark[a] = true;
////		}
//////		vector<int> temp;
//////		for (int j : adj[a]) {
//////			temp.push_back(j);
//////		}
////		for (int j : adj[a]) {
////			adj[j].erase(find(adj[j].begin(), adj[j].end(), a));
//////			cout <<"erasing adj["<<j<<"]: "<<a<<endl;
////			if (adj[j].empty() && !mark[j]) {
////				total0++;
//////				cout << "mark " << j << endl;
////				mark[j] = true;
////			}
//////			adj[a].erase(find(adj[a].begin(), adj[a].end(), j));
////		}
//////		if(i == N-1) total0--;
////	}
//	// output
//
//	return 0;
//}
/*
 ID: dongliu3
 TASK: change
 LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

// structures/defines
#define pii pair<int, int>

// global variables
int N, M;
pii path[200000];
vector<int> adj[200000],
order;
int place[200000], pa[200000];
bool cnt[200000];
//functions
int unionFind(int x) {
	int curr = x;
	while (pa[curr] != curr) {
		curr = pa[curr];
	}
	while(pa[x] != x) {
		int temp = pa[x];
		pa[x] = curr;
		x = temp;
	}
	return curr;
}
void unionMerge(int x, int y) {
	int x1 = unionFind(x), y1 = unionFind(y);
	pa[y1] = pa[x1];
//	cout << "pa[" << y1 << "] = " << pa[x1] << endl;
}
int main() {
	// local variables

	// fstream
	ifstream fin("closing.in");
	ofstream fout("closing.out");

	// input
	fin >> N >> M;
	int x, y;
	for (int i = 0; i < M; i++) {
		fin >> path[i].first >> path[i].second;
		path[i].first--, path[i].second--;
	}
	for (int i = 0; i < N; i++) {
		fin >> x;
		x--;
		order.push_back(x);
		place[x] = i, pa[i] = i;
//		cout << "place[" << x << "] = " << i << endl;
	}
	// main
	for (int i = 0; i < M; i++) {
		x = path[i].first, y = path[i].second;
		if (place[x] > place[y]) {
			adj[y].push_back(x);
		} else {
			adj[x].push_back(y);
		}
	}
	int avalible = 0;
	for (int i = N - 1; i >= 0; i--, avalible++) {
		int c = order[i];
//		cout << "current: " << c << endl;
		for (int j : adj[c]) {
//			cout << c << " vs " << j << endl;
//			cout << unionFind(c) << " vs " << unionFind(j) << endl;
			if (unionFind(c) != unionFind(j)) {
				unionMerge(c, j);
				avalible--;
			}
		}
		if(avalible <= 0) {
			cnt[i] = true;
		} else {
			cnt[i] = false;
		}
//		cout << avalible << endl;
	}
	for(int i=0; i<N; i++) {
		if(cnt[i]) {
			fout << "YES"<<endl;
		} else {
			fout <<"NO"<<endl;
		}
	}
	// output

	return 0;
}

```

# [split.cpp](#2)
```cpp
/*
 ID: dongliu3
 TASK: split
 LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

// structures/defines
#define pii pair<long long, long long>
#define f first
#define s second
#define x first
#define y second
// global variables
int N;
pii cow[50000];
long long minx = 1000000001;
long long miny = 1000000001;
long long maxx = -1;
long long maxy = -1;
multiset<long long> lx;
multiset<long long> ly;
multiset<long long> rx;
multiset<long long> ry;

//functions
bool doOverlapX(pii l1, pii r1, pii l2, pii r2) {
	if (r1.x >= l2.x && r1.y >= l2.y)
		return true;
	return false;
}
bool doOverlapY(pii l1, pii r1, pii l2, pii r2) {

	if (r1.y >= l2.y && r1.x >= l2.x)
		return true;
	return false;
}
bool myComp(pii i, pii j) {
	return i.y < j.y;
}
int main() {
	// local variables

	// fstream
	ifstream fin("split.in");
	ofstream fout("split.out");

	// input
	fin >> N;
	for (int i = 0; i < N; i++) {
		fin >> cow[i].f >> cow[i].s;
		minx = min(minx, cow[i].f);
		miny = min(miny, cow[i].s);
		maxx = max(maxx, cow[i].f);
		maxy = max(maxy, cow[i].s);
	}
//	cout << minx << " " << maxx << " and  " << miny << " " << maxy << endl;
	long long oArea = (maxx - minx) * (maxy - miny);
	long long ans = -1;
	sort(cow, cow + N);

	// main
	for (int i = 0; i < N; i++) {
		rx.insert(cow[i].f);
		ry.insert(cow[i].s);
	}
//	lx.insert(cow[0].f);
//	lx.insert(cow[0].s);
	for (int i = 0; i <= N; i++) {
		long long lArea, rArea;
		pii l1, r1, l2, r2;
		if (lx.empty() && ly.empty()) {
			lArea = 0;
		} else {
			l1 = pii(*lx.begin(), *ly.begin());
			r1 = pii(*lx.rbegin(), *ly.rbegin());
			lArea = (*lx.rbegin() - *lx.begin()) * (*ly.rbegin() - *ly.begin());
		}
		if (rx.empty() && ry.empty()) {
			rArea = 0;
		} else {
			l2 = pii(*rx.begin(), *ry.begin());
			r2 = pii(*rx.rbegin(), *ry.rbegin());
			rArea = (*rx.rbegin() - *rx.begin()) * (*ry.rbegin() - *ry.begin());
		}
		if (!doOverlapX(l1, r1, l2, r2)) {
			ans = max(ans, oArea - (lArea + rArea));
//			cout << oArea << " vs: " << lArea << " and " << rArea << endl;
		}
		if(i == N) continue;
		rx.erase(rx.find(cow[i].f));
		ry.erase(ry.find(cow[i].s));
		lx.insert(cow[i].f);
		ly.insert(cow[i].s);
	}
	sort(cow, cow + N, myComp);
	rx.clear();
	ry.clear();
	lx.clear();
	ly.clear();
	for (int i = 0; i < N; i++) {
		rx.insert(cow[i].f);
		ry.insert(cow[i].s);
	}
//	lx.insert(cow[0].f);
//	lx.insert(cow[0].s);
	for (int i = 0; i <= N; i++) {
		long long lArea, rArea;
		pii l1, r1, l2, r2;
		if (lx.empty() && ly.empty()) {
			lArea = 0;
		} else {
			l1 = pii(*lx.begin(), *ly.begin());
			r1 = pii(*lx.rbegin(), *ly.rbegin());
			lArea = (*lx.rbegin() - *lx.begin()) * (*ly.rbegin() - *ly.begin());
		}
		if (rx.empty() && ry.empty()) {
			rArea = 0;
		} else {
			l2 = pii(*rx.begin(), *ry.begin());
			r2 = pii(*rx.rbegin(), *ry.rbegin());
			rArea = (*rx.rbegin() - *rx.begin()) * (*ry.rbegin() - *ry.begin());
		}
		if (!doOverlapY(l1, r1, l2, r2)) {
			ans = max(ans, oArea - (lArea + rArea));
//			cout << oArea << " vs: " << lArea << " and " << rArea << endl;
		}
		if(i == N) continue;
		rx.erase(rx.find(cow[i].f));
		ry.erase(ry.find(cow[i].s));
		lx.insert(cow[i].f);
		ly.insert(cow[i].s);
	}
	// output
	fout << ans << endl;

	return 0;
}

```

