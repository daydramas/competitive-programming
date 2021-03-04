/**
 * CF Shifting Stacks
 * Created on 2021-02-17
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N (1 << 18) // 2e5

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int a[n];
		for(int i=0;i<n;i++) cin >> a[i];
		long long sofar = 0, sum = 0;
		bool ok = 1;

		for(int i=0;i<n;i++) {
			sofar += a[i];
			sum += i;
			if(sofar < sum) ok = 0;
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}	
}