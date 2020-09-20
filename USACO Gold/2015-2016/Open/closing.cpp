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
