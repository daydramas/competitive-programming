#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e5+5;
int n, a[N];
vector<int> x, y;

int main() {
	while(cin >> a[++n]); --n;
	for(int i=1; i<=n; ++i) {
		int p = upper_bound(begin(x), end(x), a[i], greater<int>()) - begin(x);
		if(p == x.size()) x.push_back(a[i]);
		else x[p] = a[i];
	}
	cout << x.size() << '\n';
	x.clear();
	for(int i=1; i<=n; ++i) {
		int p = lower_bound(begin(x), end(x), a[i]) - begin(x);
		if(p == x.size()) x.push_back(a[i]);
		else x[p] = a[i];
	}
	cout << x.size() << '\n';
}

namespace IO {
	template<class T> void read(T& x) { cin >> x; }
	template<class T, class... U> void read(T& x, U&... y) { read(x); read(y) };
	template<class T> void print(T& x) { cout << x; }
	template<class T, class... U> void print(T& x, U&... y) { print(x); print(y); } 

};