# poetry
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