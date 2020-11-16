# threesum
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