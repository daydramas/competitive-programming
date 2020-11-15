# split
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