/**
 * Longest Increasing Subsequence
 * https://dmoj.ca/problem/lis
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define N	(1<<20)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	static int n, x, p;
	vector<int> a;

	cin >> n;
	while(n--) {
		cin >> x;
		p = lower_bound(a.begin(), a.end(), x) - a.begin();
		if(p == a.size()) a.push_back(x);
		else a[p] = x;
	}
	cout << a.size() << '\n';

}