/**
 * CF Equalize the Array
 * Created on 2021-02-16
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
using namespace std;

#define N (1 << 18) // 2e5

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		map<int,int> freq;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			freq[x]++;
		}
		map<int,int> freq2;
		for(pair<int,int> x : freq) {
			freq2[x.second]++;
		}
		int ans = n;
		for(pair<int,int> x : freq2) {
			ans = min(ans, n - x.first * x.second);
		}
		cout << ans << '\n';
	}
}