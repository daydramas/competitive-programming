```cpp
  
/*
 ID: dongliu3
 TASK: crypt1
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
int N;
set<int> digit;

// functions
bool exsits(int num) {
	while(num > 0) {
		int a = num % 10;
		num /= 10;
		if (digit.find(a) == digit.end()) {
			return false;
		}
	}
	return true;
}
int main() {
	// local variables

	// fstream
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");

	// input
	fin >> N;
	for (int i=1; i<=N; i++) {
		int j; fin >> j;
		digit.insert(j);
	}
	// main
	int ans = 0;
	for (int i : digit) for (int j : digit) for (int k : digit) for (int l : digit) for (int m : digit) {
		int a = ((i*100)+(j*10)+(k*1))*(m*1);
		int b = ((i*100)+(j*10)+(k*1))*(l);
		int c = a + b*10;
		if (a < 1000 && b < 1000 && c < 10000 && exsits(a) && exsits(b) && exsits(c)) {
			ans++;
		}
	}
	fout << ans << endl;
	// output

	return 0;
}
```