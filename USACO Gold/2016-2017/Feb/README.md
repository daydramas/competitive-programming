<div align="center"> <a href="#0">circlecross.cpp</a> | <a href="#1">nocross.cpp</a> | <a href="#2">visitfj.cpp</a> </div>

# [circlecross.cpp](#0)
```cpp
/*
  _____     ______              ______                _______
 |     \   |      |  |\     |  |             |           |     |      |
 |	    \  |      |  | \    |  |             |           |     |      |
 |      |  |      |  |  \   |  |   ___       |           |     |      |
 |      |  |      |  |   \  |  |      |      |           |     |      |
 |      /  |      |  |    \ |  |      |      |           |     |      |
 |_____/   |______|  |     \|  |______|      |______  ___|___  |______|

      ___   ___        ___             ___   ___   ___  ___
  __ | __  |   | |    |   \   / |   | |___  |___| |    |   | \
     |___| |___| |___ |___/   \ |___|  ___| |   | |___ |___| /

*/

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
#define Pair pair<int, int>

// global variables
int N;
int BIT[100001];
//functions
int getSum(int pos) {
	if(pos == 0) return 0;
	int ans = 0;
	for(int i=pos+1; i!=0; i -= i&(-i)) {
		ans += BIT[i];
	}
//	cout<<"ans:"<<ans<<endl;
	return ans;
}
void addNode(int pos, int ans) {
	for(int i=pos+1; i<=2*N; i += i&(-i)) {
		BIT[i] += ans;
	}
}
int main() {
	// local variables

	// fstream
	ifstream fin("circlecross.in");
	ofstream fout("circlecross.out");

	// input
	fin >> N;
	vector<Pair> cowID(N, Pair(-1, -1));
	memset(BIT, 0, sizeof(N+1));
	for(int i=0; i<2*N; i++) {

		int x; fin >> x; x--;

		if(cowID[x].first == -1) {
			cowID[x].first = i;
		} else {
			cowID[x].second = i;
		}

	}
	int ans = 0;
	sort(cowID.begin(), cowID.end());
	for(int i=0; i<N; i++) {
//		cout <<i<<" : " << cowID[i].first<<" " << cowID[i].second<<endl;
		ans += getSum(cowID[i].second)-getSum(cowID[i].first);
		addNode(cowID[i].second, 1);
	}
	// main
//	for(int i=1; i<=2*N; i++) {
//		cout <<"i: "<<i<<" = "<<BIT[i]<<endl;
//	}
	fout <<ans <<endl;
//	int cnt = 0;
//	for(int i=0; i<N; i++) {
//		for(int j=i+1; j<N; j++) {
//			if(cowID[j].first < cowID[i].second) {
//				if(cowID[j].second > cowID[i].second) {
//					cnt++;
//				}
//			} else break;
//		}
//	}
//	fout << cnt << endl;
	// output
	return 0;
}

```

# [nocross.cpp](#1)
```cpp
#include <bits/stdc++.h>

using namespace std;

// defines
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define f(i, a, b) for(ll i = a; i < b; i++)
#define rf(i, a, b) for(ll i = a; i >= b; i--)
#define w(a) while(a--)
#define arrin(a,n) f(i,0,n) { cin >> a[i]; }
#define arrin1(a,n) f(i,1,n+1) { cin >> a[i]; }
#define arrout(a,n) f(i,0,n) { cout << a[i]<<" "; }
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll gcd(ll a,ll b){ return (b==0) ? a : gcd(b,a%b); }
ll lcm(ll a,ll b){ return (a * b) / gcd(a,b); }

// structures
struct segTree {

	int n;
	vector<int> st;

	segTree(int n_) {
		n = n_;
		st.assign(4*n, 0);
		build(1, 1, n);
	}

	int left(int i) { return i*2; }
	int right(int i) { return i*2+1; }

	void build(int id, int L, int R) {
		if (L == R) {
			st[id] = 0;
			return;
		}
		build(left(id), L, (L+R)/2);
		build(right(id), (L+R)/2+1, R);
		st[id] = max(st[left(id)],st[right(id)]);
	}

	void update(int id, int L, int R, int P, int value) {
		if (P > R || P < L) return;
		if (P >= L && P <= R) st[id] = value;
		if (L == R) return;
		update(left(id), L, (R+L)/2, P, value);
		update(right(id), (R+L)/2+1, R, P, value);
		st[id] = max(st[left(id)], st[right(id)]);
	}

	void update(int P, int value) {
		update(1, 1, n, P, value);
	}

	int get(int id, int L, int R, int l, int r) {
		if (l > R || r < L) return 0;
		if (l <= L && R <= r) return st[id];
		return max(get(left(id), L, (R+L)/2, l, r),get(right(id), (R+L)/2+1, R, l, r));
	}

	int get(int L, int R) {
		return get(1, 1, n, L, R);
	}
};
// global variables
int n;
int A[100005],B[100005];
vector<int> c;
// functions
int main() {

	// local variables

	// input
	fastio;
	cin >> n;
	f(i,1,n+1) {
		cin >> A[i];
	}
	f(i,1,n+1) {
		int b;
		cin >> b; B[b] = i;
	}
	segTree t(n);

	// main
	int ans = 0;
	f(i,1,n+1) {
		c.clear();
		f(j,max(1,A[i]-4), min(n, A[i]+4)+1) {
			c.push_back(B[j]);
		}
		sort(c.begin(), c.end());
		reverse(c.begin(), c.end());
		for (int ci : c) {
			int q = t.get(1, ci);
			ans = max(ans, q+1);
			t.update(ci+1,q+1);
		}
	}

	// output
	cout <<ans << endl;
	return 0;
}

```

# [visitfj.cpp](#2)
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
#define BIG 1000000000
struct node {
	int x, y, time;
	node(int x, int y, int time) : x(x), y(y), time(time) {}
	bool operator<(node const& e) const {
		return time > e.time;
	}
};
// declare any global variables
int N, T, grass[110][110], dp[110][110], ans = BIG;
int X[] = {0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1, -1, 1, 0, 0};
int Y[] = {3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 1, 2, 0, 0, -1, 1};
int sizeof_transition = 16;
// declare any functions
int distToFj(int i, int j) {return (N-i)+(N-j); }
int main() {

	// fstream
	ifstream fin ("visitfj.in");
	ofstream fout ("visitfj.out");

	// input
	fin >> N >> T;
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) fin >> grass[i][j];
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) dp[i][j] = BIG;
	// main
	dp[1][1] = 0;
	priority_queue<node> q; q.push(node(1, 1, 0));
	while(!q.empty()){
		int x = q.top().x;
		int y = q.top().y;
		int time = q.top().time;
		q.pop();

//		cout << x << " " << y << " " << time << endl;

//		if(x==N and y==N) ans = min(ans, time);
		int d = distToFj(x, y);
		if(d < 3) ans = min(ans, time+(d*T));
		if(time > dp[x][y]) continue;

		for(int i=0; i<sizeof_transition; i++){
			int nx = x+X[i];
			int ny = y+Y[i];
			int nt = time+(3*T) + grass[nx][ny];
			if(nx >= 1 and nx <= N and ny >= 1 and ny <= N){
				if(nt < dp[nx][ny]){
					dp[nx][ny] = nt;
					q.push(node(nx, ny, nt));
				}
			}
		}
	}
	// output
	fout << ans << endl;
	//close
	fout.close();
	return 0;
}

```

