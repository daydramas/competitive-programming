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