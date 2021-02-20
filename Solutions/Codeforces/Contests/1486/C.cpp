/**
 * CF Guessing the Greatest
 * Created on 2021-02-17
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define N (1 << 18) // 2e5

map<int, map<int, int>> cache;

int query(int x, int y) {
	if(cache[x][y]) return cache[x][y];
	cout << "? " << x << ' ' << y << '\n';
	cout.flush();
	int z; cin >> z;
	cache[x][y] = z;
	return z;
}
void answer(int x) {
	cout << "! " << x << '\n';
	cout.flush();
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n; cin >> n;
	int sec = query(1, n);
	int low, high;
	bool which = 0;
	if (sec != 1) {
		int secccc = query(1, sec);
		if(sec == secccc) {
			which = 1;
		}
	}
	if(which) {
		// cout << "CHOSE 1" << endl;
		low = 1, high = sec - 1;
		while(low < high) {
			if(high - low == 1) {
				int x = query(high, sec);
				if(x == sec) low = high;
				// else high = low; 
				break;
			}
			int mid = (low + high) / 2;
			int x = query(mid, sec);
			if(x == sec) low = mid;
			else high = mid - 1;
		}
		answer(low);
	}
	else {
		low = sec + 1, high = n;
		while(low < high) {
			int mid = (low + high) / 2;
			if(high - low == 1) {
				int x = query(sec, low);
				if(x == sec) high = low;
				// else low = high; 
				// 
				break;
			}
			int x = query(sec, mid);
			if(x == sec) high = mid;
			else low = mid + 1;
		}
		answer(high);
	}
}