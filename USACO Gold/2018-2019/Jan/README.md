<div align="center"> <a href="#poetrycpp">poetry.cpp</a> | <a href="#shortcutcpp">shortcut.cpp</a> | <a href="#sleepycpp">sleepy.cpp</a> </div>

# [poetry.cpp](#0)
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
long long dp[5005], row[5005];
int syllable[5005], rhyme[5005];
long long MOD = 1000000007;
map<char, int> frequency;
long long ans = 1;
// functions
long long exponent(int b, int p){
   if(p == 0) return 1;
   if(p == 1) return (b + MOD) % MOD;
   long long ans = exponent(b,p/2);
   ans = (ans * ans + MOD) % MOD;
   if(p%2 == 1) ans = (ans*b + MOD) % MOD;
   return (ans + MOD) % MOD;
}
int main() {
	// local variables

	// input
	ifstream fin("poetry.in");
	ofstream fout("poetry.out");

	fin >> N >> M >> K;
	for(int i=1; i<=N; i++) {
		fin >> syllable[i] >> rhyme[i];
	}
	for(int i=1; i<=M; i++) {
		char ch; fin >> ch;
		if(frequency.find(ch) == frequency.end()) {
			frequency[ch] = 1;
		} else frequency[ch]++;
	}
	for(int i=1; i<=K; i++) dp[i]=0;
	// main
	dp[0] = 1;
	for(int i=0; i<=K; i++) {
		for(int j=1; j<=N; j++) {
			int nxt = i+syllable[j];
			if(nxt > K) continue;
			else if (nxt == K) {
//				cout <<"row["<<rhyme[j]<<"] = "<<row[rhyme[j]]<<" + "<<dp[i]<<endl;
				row[rhyme[j]] = (row[rhyme[j]]+dp[i]+MOD) % MOD;
//				cout <<"row["<<rhyme[j]<<"] = "<<row[rhyme[j]]<<endl;
			} else {
				dp[nxt] = (dp[i]+dp[nxt]+MOD) % MOD;
			}
		}
	}
//	cout << row[1] << ", " << row[2]<<endl;
	for(map<char, int>::iterator it=frequency.begin(); it!=frequency.end(); ++it) {
		int f = it->second;
		long long temp_ans = 0;
		for(int i=0; i<=N; i++) {
	        if(row[i] == 0) continue;
//	        cout << row[i] << " " << f << endl;
			temp_ans = (temp_ans + exponent(row[i],f)+MOD)%MOD;
		}
//		cout <<it->first << " : "<< temp_ans << endl;
		ans = (ans * temp_ans + MOD) % MOD;
	}
	// output
	fout << ans << endl;
	return 0;
}

```

# [shortcut.cpp](#1)
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

```

# [sleepy.cpp](#2)
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
int N;
int cow[100000];
int btree[100001];
//functions;
void initBtree(int i) {
//	int oi = i;
	i++;
	for(; i<=N; i+=i&(-i)) {
		btree[i] += 1;
	}
//	cout << oi+1 << ": ";
//	for(int i1=1; i1<=N; i1++) {
//		cout<<btree[i1]<<" ";
//	} cout << endl;
}
int getSum(int i) {
	i++; int cnt=0;
	for(; i>0; i-=i&(-i)) {
		cnt += btree[i];
	}
	return cnt;
}
int main() {
	// local variables

	// fstream
	ifstream fin("sleepy.in");
	ofstream fout("sleepy.out");

	// input
	fin >> N;
	for(int i=0; i<N; i++) {
		fin >> cow[i];
		cow[i]--;
	}

	// main
	int K = N-1;
	while(K>0 && cow[K-1]<cow[K]) {
		K--;
	}
	fout << K << endl;
	for(int i=K; i<N; i++) initBtree(cow[i]);
	for(int i=0; i<K; i++) {
		fout << (K-i-1)+getSum(cow[i]);
		if(i!=K-1) fout <<" ";
		initBtree(cow[i]);
	}
	// output
	fout << endl;
	return 0;
}

```

