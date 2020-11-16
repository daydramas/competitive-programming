<div align="center"> <a href="#boardscpp">boards.cpp</a> | <a href="#threesumcpp">threesum.cpp</a> | <a href="#timecpp">time.cpp</a> </div>

# [boards.cpp](#0)
```cpp
/*
 ID: dongliu3
 TASK: boards
 LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

// structures/defines
#define pii pair<int, int>
#define ppii pair<pii, pii>
#define x first
#define y second
// global variables
int N, P;
vector<ppii> pnt;
map <int,
int> m;
int ans[100001];
//functions
void update(int y1, int value) {
//	cout << "hi" << endl;
	map<int, int>::iterator it = prev(m.upper_bound(y1));
//	cout << "hi" << endl;
	if (it->y > value) {
		++it;
		while (it != m.end() && it->y > value) {
			m.erase(it++);
//			it++;
		}
		m[y1] = value;
	}
}
int main() {
	// local variables

	// fstream
	ifstream fin("boards.in");
	ofstream fout("boards.out");
	// input
	fin >> N >> P;
	for (int i = 1; i <= P; i++) {
		pii a, b;
		fin >> a.x >> a.y >> b.x >> b.y;
		pnt.push_back(ppii(a, pii(i, 1)));
		pnt.push_back(ppii(b, pii(i, -1)));
	}
	// main
//	cout << "hi" <''< endl;
	sort(pnt.begin(), pnt.end());
//	cout << "hi" << endl;
	m[0] = 0;
//	m[-1] = 0;
	for (ppii p : pnt) {
//		cout << "hi2" << endl;
		if (p.y.y == 1) { // start
//			cout << "hi3" << endl;
			ans[p.y.x] = p.x.x + p.x.y + prev(m.upper_bound(p.x.y))->y;
//			cout << "hi3" << endl;
		} else { //end
//			cout << "hi4" << endl;
			update(p.x.y, ans[p.y.x] - p.x.x - p.x.y);
//			cout << "hi4" << endl;

		}
	}
//	cout << "hi" << endl;
	// output
	fout << (m.rbegin()->y) + (2 * N) << endl;

	return 0;
}

```

# [threesum.cpp](#1)
```cpp
///*
// ID: dongliu3
// TASK: change
// LANG: C++
// */
//
//#include <bits/stdc++.h>
//using namespace std;
//
//// structures/defines
//#define ll long long
//#define pii pair<int, ll>
//#define ppii pair<int, pii>
//// global variables
//int N, Q;
//int s[5001];
//ll count1[2001][2001];
//ll sum[2001][2001];
////map<int, map<int, ll> > count1;
////map<int, map<int, ll> > sum;
//void findTriplets() {
//	for (int i = 1; i < N; i++) {
//		map<int, int> number;
//		number[s[i + 1]]++;
//		for (int j = i + 2; j <= N; j++) {
//			int x = -(s[i] + s[j]);
//			if (number[x] != 0) {
//				count1[i][j] += number[x];
//			}
//			number[s[j]]++;
//		}
//	}
//}
//ll getSum(int a, int b) {
//	if (sum[a][b] != -1) {
//		return sum[a][b];
//	}
//	sum[a][b] = getSum(a, b - 1);
//	for (int i = a; i <= b; i++) {
//		sum[a][b] += count1[i][b];
//	}
//	return sum[a][b];
//}
//int main() {
//	// local variables
//	queue< ppii> q;
//	// fstream
//	ifstream fin("threesum.in");
//	ofstream fout("threesum.out");
//
//	// input
//	fin >> N >> Q;
//	for (int i = 1; i <= N; i++) {
//		fin >> s[i];
//	}
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			sum[i][j] = -1;
//			count1[i][j] = 0;
//		}
//	}
//
//	findTriplets();
//	for (int i = 1; i <= Q; i++) {
//		int a, b;
//		fin >> a >> b;
//		fout << getSum(a, b) << endl;
//	}
////	fout << "2\n1\n4\n";
//	return 0;
//}
/*
 ID: dongliu3
 TASK: change
 LANG: C++
 */

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
#include <unordered_map>
//#include <ext/pb_ds/assoc_container.hpp> // for gp_hash_table
//#include <ext/hash_map>
//using namespace __gnu_pbds;
using namespace std;

// structures/defines
#define ll long long
#define pil pair<ll, int>
// global variables
int N, Q;
int s[5001];
//vector<int> s;
//vector<pil> ss;
//us;
ll sum[5002][5002];
void findTriplets() {

//	sort(s.begin(), s.end());
//	sort(ss.begin(), ss.end());
	int number[2000001];
	for (int i = 0; i <= 2000000; i++) {
		number[i] = 0;
	}
	for (int i = 1; i < N; i++) {
//		hash_map<int, int> number;
//		unordered_map<int, int> number;
//		gp_hash_table<int, int> number( { }, { }, { }, { }, { 1 << 13 });

//		fill(number, number + 2000001, 0);
//		memset(number, 0, sizeof(int) * 2000001);
//		cout << "clearing" << endl;
		number[s[i + 1] + 1000000]++;
//		cout << "adding " << s[i + 1] << endl;
		for (int j = i + 2; j <= N; j++) {
//			cout << "i: " << i << " j: " << j << endl;
			int x = -(s[i] + s[j]) + 1000000;
//			if (number[x] != 0) {
//			auto it = number.find(x);
//			if (it != number.end()) {
			if (x >= 0 && x <= 2000000)
				sum[i][j] += number[x];
//			}
//			}
//			if (number[x]) {
//				cout << "       " << s[i] << " " << s[j] << " " << x - 1000000
//						<< endl;
//			}
			number[s[j] + 1000000]++;
//			cout << "adding " << s[j] << endl;
		}
		for (int j = i + 1; j <= N; j++) {
			number[s[j] + 1000000]--;
		}
//		cout << endl;
	}
//	for (int i = 1; i <= N; i++) {
//		cout << ss[i].first << " " << ss[i].second << "\n";
//		cout << s[i] << endl;
//	}
//	cout << endl;
//	for (int i = 1; i <= N; i++) {
//		for (int j = i + 1; j <= N; j++) {
//			int x = -(s[i] + s[j]);
//			int tmin = min(ss[i].second, ss[j].second);
//			int tmax = max(ss[i].second, ss[j].second);
//			if (x < s[j]) {
//				break;
//			}
//			if (s[j] == x && j + 100 <= N && x == s[j + 100]) {
//
//			} else {
//				int in = lower_bound(s.begin(), s.end(), x) - s.begin();
//				while (s[in] == x) {
//					if (in <= j) {
//						in = j + 1;
//						continue;
//					}
//					int mi = min(ss[in].second, tmin);
//					int Mi = max(ss[in].second, tmax);
//					sum[mi][Mi] += 1;
//					in++;
//				}
//			}
//		}
//	}
}
int main() {
	// local variables
	// fstream
	ifstream fin("threesum.in");
	ofstream fout("threesum.out");

	// input
	fin >> N >> Q;
//	cout << N << endl;
//	s.push_back(-1000001);
//	ss.push_back(pil(-1000001, 0));
//	us.push_back(-1000001);
	for (int i = 1; i <= N; i++) {
		fin >> s[i];
//		int x;
//		fin >> x;
//		ss.push_back(pil(x, i));
//		us.push_back(x);
//		s.push_back(x);
	}

	findTriplets();

//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			if (sum[i][j]) {
//				cout << i << " " << j << " : " << sum[i][j] << endl;
//			}
////			sum[i][j]/=3;
//		}
//	}
//	cout << "calculation sum" << endl;
	for (int l = 3; l <= N; l++) {
		for (int i = 1; i + l - 1 <= N; i++) {
			int j = i + l - 1;
			sum[i - 1][j + 1] -= sum[i][j];
			sum[i][j + 1] += sum[i][j];
			sum[i - 1][j] += sum[i][j];
		}
	}

	for (int i = 1; i <= Q; i++) {
		int a, b;
		fin >> a >> b;
		fout << sum[a][b] << endl;
	}
	return 0;
}

```

# [time.cpp](#2)
```cpp
/*
 ID: dongliu3
 TASK: change
 LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

// structures/defines
#define pii pair<int, int>
#define ppii pair<int, pii>
// global variables
int N, M, C;
int m[1001];
vector<int> edge[1001];
int dp[1001][3001];
//functions

int main() {
	// local variables

	// fstream
	ifstream fin("time.in");
	ofstream fout("time.out");

	// input
	fin >> N >> M >> C;
	for (int i = 1; i <= N; i++) {
		fin >> m[i];
	}
	for (int i = 1; i <= M; i++) {
		int a, b;
		fin >> a >> b;
		edge[a].push_back(b);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 3 * N; j++) {
			dp[i][j] = -1000000000;
		}
	}
	// main
	dp[1][0] = 0;
	queue< ppii> Q;
	Q.push(ppii(1, pii(0, 0)));
	while (!Q.empty()) {
		ppii f = Q.front();
		Q.pop();

		if (f.second.first == N * 3) {
			continue;
		}
		for (int i : edge[f.first]) {
			int nm = dp[f.first][f.second.first] + m[i];
//			cout << f.first << " " << i << endl;
//			cout << nm << endl;
			nm += C * f.second.first * f.second.first;
//			cout << "adding " << C * f.second.first * f.second.first << endl;
			nm -= C * (f.second.first + 1) * (f.second.first + 1);
//			cout << "subtracting "
//					<< C * (f.second.first + 1) * (f.second.first + 1) << endl;
			if (dp[i][f.second.first + 1] < nm) {
				dp[i][f.second.first + 1] = nm;
//				cout << "dp[" << i << "][" << f.second.first + 1 << "] = " << nm
//						<< endl;
				Q.push(ppii(i, pii(f.second.first + 1, nm)));
			}
//			cout << endl;
		}
	}
// output
	int ans = 0;
	for (int i = 0; i <= N * 3; i++) {
		ans = max(ans, dp[1][i]);
	}
	fout << ans << endl;
	return 0;
}

```

