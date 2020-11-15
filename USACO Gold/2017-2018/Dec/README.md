<div align="center"> [barnpainting.cpp](#0) | [hayfeast.cpp](#1) | [piepie.cpp](#2) </div>

# [barnpainting.cpp](#0)
```cpp
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include <iterator>
#include <stack>
#include <utility>
using namespace std;

// structures/defines

// global variables
long long N, K;
vector<long long> adj[100001];
long long color[100001];
long long dp[100001][5];
//functions
long long solve(long long src, long long srcC, long long pa, long long paC) {
//	cout << src<< " " << srcC << " " << pa << " " << paC << endl;
	if((srcC == paC)||(color[src]>=1 && color[src]!=srcC)) {
//		cout << "1" << endl;
		return 0;
	}
	if(dp[src][srcC] >=0) return dp[src][srcC];
	dp[src][srcC] = 1;
	for(long long dest : adj[src]) {
		if(dest == pa) continue;
		long long mul = 0;
		for(long long c=1; c<=3; c++) {
			mul += solve(dest, c, src, srcC);
			mul %= 1000000007;
		}
		dp[src][srcC] *= mul;
		dp[src][srcC] %= 1000000007;
	}
//	cout << dp[src][srcC] << " ";
	return dp[src][srcC];
}
int main() {
	// local variables

	// fstream
	ifstream fin("barnpainting.in");
	ofstream fout("barnpainting.out");

	// input
	fin >> N >> K;
	for(long long i=1; i<N; i++) {
		long long x,y; fin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(long long i=1; i<=N; i++) {
		dp[i][1] = dp[i][2] = dp[i][3] = -1;
		color[i] = -1;
//		cout << "color["<<i<<"] = "<<color[i] << endl;
	}
	for(long long i=1; i<=K; i++) {
		long long x,y; fin >> x >> y;
		color[x] = y;
	}
	long long s1 = solve(1, 1, -1, -1); //cout << endl;
	long long s2 = solve(1, 2, -1, -1); //cout << endl;
	long long s3 = solve(1, 3, -1, -1); //cout << endl;
	fout << (s1+s2+s3)%1000000007 << endl;
	return 0;
}

```

# [hayfeast.cpp](#1)
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
#define ll long long
// declare any global variables
ll N, M, F[100010], S[100010], i, j;
multiset<ll> solver;
// declare any functions
int main() {

	// fstream
	ifstream fin ("hayfeast.in");
	ofstream fout ("hayfeast.out");

	// input
	fin >> N >> M;
	for(i=1; i<=N; i++) fin >> F[i] >> S[i];
	// main
	i=1, j=1;
	ll flavor = 0;
	ll ans = 1000000000000;
	while(j <= N+1){
		if(flavor < M){
			solver.insert(S[j]);
			flavor += F[j];
			j++;
			continue;
		}
		ans = min(ans, *solver.rbegin());
		solver.erase(solver.find(S[i]));
		flavor -= F[i];
		i++;
	}
	// output
	fout << ans << endl;
	//close
	fout.close();
	return 0;
}

```

# [piepie.cpp](#2)
```cpp
/*
 ID: dongliu3
 TASK: piepie
 LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

// structures/defines
int N, D;
int B[200000], E[200000];
struct compA {
	bool operator()(int i, int j) const {
		return E[i] > E[j];
	}
};
struct compB {
	bool operator()(int i, int j) const {
		return B[i] > B[j];
	}
};
// global variables
multiset<int, compA> sA;
multiset<int, compB> sB;
int ans[200000];
//functions

int main() {
//  local variables

//  fstream
	ifstream fin("piepie.in");
	ofstream fout("piepie.out");

//  input
	fin >> N >> D;
	for (int i = 0; i < (2 * N); i++) {
		fin >> B[i] >> E[i];
	}
	queue<int> Q;
	for (int i = 0; i < N; i++) {
		if (E[i] == 0) {
			Q.push(i);
//			cout <<"pushing "<< i << endl;
			ans[i] = 1;
		} else {
			sA.insert(i);
			ans[i] = -1;
		}
		if (B[i + N] == 0) {
			Q.push(i + N);
//			cout <<"pushing "<< i+N << endl;
			ans[i + N] = 1;
		} else {
			sB.insert(i + N);
			ans[i + N] = -1;
		}
	}

//	main
//	for (multiset<int, compB>::iterator it = sB.begin(); it != sB.end(); it++) {
//		cout << *it << " b: " << B[*it] << endl;
//	}
	while (!Q.empty()) {
		int f = Q.front();
//		cout << f << " ans: " << ans[f] << endl;
		Q.pop();
		if (f < N) {
			while (true) {
				multiset<int, compB>::iterator it = sB.lower_bound(f);
//				cout << *it << " : " << B[*it] << " versus " << B[f] << endl;
				if (it == sB.end() || B[*it] + D < B[f]) {
//					cout <<"break;"<<endl;
					break;
				}
//				cout << *it << " : " << B[*it] << " versus " << B[f] << endl;
				Q.push(*it);
				ans[*it] = ans[f] + 1;
				sB.erase(it);
			}
		} else if (f < 2 * N) {
			while (true) {
				multiset<int, compA>::iterator it = sA.lower_bound(f);
//				cout << *it << " : " << E[*it] << " versus " << E[f] << endl;
				if (it == sA.end() || E[*it] + D < E[f]) {
//					cout <<"break;"<<endl;
					break;
				}
//				cout << *it << " : " << E[*it] << " versus " << E[f] << endl;
				Q.push(*it);
				ans[*it] = ans[f] + 1;
				sA.erase(it);
			}
		}
	}
//	output
	for (int i = 0; i < N; i++) {
		fout << ans[i] << endl;
	}
	return 0;
}

```

