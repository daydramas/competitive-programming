/**
 * CF Sum of Cubes
 * Created on 2021-02-18
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define M 10000

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	long long n;
	vector<long long> cubes;
	for(long long i = 1; i <= M; i++)
		cubes.push_back(i * i * i);
	cin >> t;
	while(t--) {
		cin >> n;
		bool found = false;
		for (long long i = 1; i <= M; i++) {
			long long j = n - i * i * i;
			if(j < 0) break;
			if (*lower_bound(begin(cubes), end(cubes), j) == j) {
				found = true;
				break;
			}
		}
		cout << (found ? "YES" : "NO") << '\n';
	}
}