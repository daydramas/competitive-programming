/**
 * P - Dollars
*/

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

#define N	6005

const int money[] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
const int msize = 11;
typedef long long ll;
ll dp[N];

void load() {
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i=0; i<msize; i++) {
		for(int j=money[i]; j<N; j++) {
			dp[j] += dp[j - money[i]];
		}
	}
}

int main() {

	int n; 
	double d;

	load();
	while(1) {
		cin >> d;
		if(d == 0) break;
		n = int(d * 20); // div 0.05
		cout << setw(6) << fixed << setprecision(2) << d << setw(17) << dp[n] << '\n';
		// printf("%6.2lf%17lld\n", d, dp[n]);
	}
}