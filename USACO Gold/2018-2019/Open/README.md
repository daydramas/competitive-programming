<div align="center"> <a href="#balancecpp">balance.cpp</a> | <a href="#snakescpp">snakes.cpp</a> | <a href="#walkcpp">walk.cpp</a> </div>

# [balance.cpp](#0)
```cpp
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include <iterator>
#include <stack>
#include <utility>
using namespace std;

// structures/defines

// global variables
long long N;
int I[200004];
int ones = 0;
long long ans = 0;
//functions
long long inversions(int l, int r) {
	long long cnt = 0;
	int one = 0;
	for (int i = l; i <= r; i++) {
		if (I[i] == 1)
			one++;
		else
			cnt += one;
	}
	return cnt;
}
long long solve(int move, long long diff, int sign) {
	long long tans = 10000000000;
	long long tans2 = 0;
	int i = N, j = 1;
	for (; i >= 1; i--) {
//		if(diff*sign <= 0) break;
//		cout << i << " " << diff << " "<<sign << endl;
		long long add = 0, addd = 0;
		if (I[i] == move) {
//			cout << i << endl;
			while (j <= N && I[j + N] != 1 - move)
				j++;
			if (j > N)
				break;
//			cout << j << endl;

			add = (N - i + j);
//			cout<<i<<" "<<j<<" -> " << add << endl;
//			cout<<(sign*(ones-N-N+i+j-1))<<endl;
//			cout<<"nd: " << sign * (-1*(N-i)+(j-1)+(ones-N)) << endl;
//			cout << N << " " << i << " " << j  << endl;
//			cout << i<<" " << j<< " : "<<(ones-N-N+i+j-1) << endl;
//			cout << diff << endl;
//			cout << sign << " " << (ones-N-N+i+j-1) << endl;
//			cout <<"comp0: "<< (diff+sign*(ones-N-N+i+j-1))*sign <<endl;
//			if((diff+sign*(ones-N-N+i+j-1))*sign < 0) {
//				long long tans2;
//				tans2 =
//			}
			addd += sign * (ones - N - N + i + j - 1);
//			cout << diff << endl;
			j++;
		}
//		if((diff+addd)*sign < 0) break;

		tans = min(tans,
				min(tans2 + abs(diff), tans2 + add + abs(diff + addd)));
		tans2 += add;
		diff += addd;
		if (j > N)
			break;
//		cout <<"ans: "<<tans<<endl;
	}
//	return tans+abs(diff);
	return tans;
}
int main() {
	// local variables

	// fstream
	ifstream fin("balance.in");
	ofstream fout("balance.out");

	// input
	fin >> N;
	for (int i = 1; i <= 2 * N; i++) {
		fin >> I[i];
		ones += I[i];
	}
	// main
	long long i1 = inversions(1, N);
	long long i2 = inversions(N + 1, 2 * N);
//	cout << i1 << endl;
//	return 0;
//	if(i1 > i2) { // m>k
//		nd =solve(1, i1-i2, 1);
//	} else if(i1 < i2) { //m<k;
//		nd= solve(0, i1-i2, -1);
//	}
	// output
	ans = min(solve(1, i1 - i2, 1), solve(0, i1 - i2, -1));
	fout << ans << endl;
	return 0;
}
//#include <iostream>
//#include <algorithm>
//using namespace std;
//#define MAXN 100000
//
//int N;
//int A[2*MAXN];
//long long best;
//int ones;
//
//long long llabs(long long x)
//{
//	if(x<0) return -x;
//	return x;
//}
//
//long long countInversions(int a,int b)
//{
//	long long t = 0;
//	int n1 = 0;
//	for(int i=a;i<=b;i++)
//	{
//		if(A[i]==1) n1++;
//		else t += n1;
//	}
//	return t;
//}
//
//int tp, sgn;
//
//void solve()
//{
//	long long inv0 = countInversions(0,N-1);
//	long long inv1 = countInversions(N,2*N-1);
//	long long dif = inv0 - inv1;
//	best = min(best, llabs(dif));
//	cout <<"bd: "<< llabs(dif)<<endl;
//	int n1 = 0;
//	int j = N;
//	int displaced = 0;
//	long long cost = 0;
//	for(int i=N-1;i>=0;i--) if(A[i]==tp)
//	{
//		dif -= sgn*(N-1-i), cost += N-1-i;
//		dif += sgn*(ones - N), cost++;
//		dif += sgn*n1, cost += n1;
//		dif += sgn*displaced, cost += displaced;
//		n1++;
//		if(n1 + displaced > N) return;
//		while(n1 + displaced > j-N)
//		{
//			if(A[j]==1-tp) j++;
//			else if(j==2*N-1) return;
//			else
//			{
//				dif += sgn*(N + n1 + displaced - j), cost += N + n1 + displaced - j;
//				displaced++;
//				j++;
//			}
//		}
//		cout << best << " " << cost << " + "<<dif<<endl;
//		best = min(best, cost+llabs(dif));
//	}
//}
//
//int main()
//{
//	cin >> N;
//	for(int i=0;i<2*N;i++)
//	{
//		cin >> A[i];
//		ones += A[i];
//	}
//	best = MAXN*((long long)MAXN);
//	tp = 1, sgn = 1;
//	solve();
//	tp = 0, sgn = -1;
//	solve();
//	cout << best << '\n';
//}

```

# [snakes.cpp](#1)
```cpp
//============================================================================
// Name        : cpp_change.cpp
// Author      : Dong Liu
// Website     :
//============================================================================

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

// declare any structures

// declare any global variables

// declare any functions

int main() {
	// declare any local variables
	int N, K, groups[401], DP[401][400];
	int total_snakes = 0;
	int maxn_snakes_in_group = 0;
	// fstream
	ifstream fin ("snakes.in");
	ofstream fout ("snakes.out");

	// input
	fin >> N >> K;
	for(int i=1; i<=N; i++){
		fin >> groups[i];
		total_snakes += groups[i];

		maxn_snakes_in_group = max(maxn_snakes_in_group, groups[i]);
		DP[i][0] = maxn_snakes_in_group*i;

		for(int j=1; j<=K; j++){
			DP[i][j] = 1000000000;
			int snakes = groups[i];

			for(int b=i-1; b>=0; b--){
				DP[i][j] = min(DP[i][j], DP[b][j-1]+(snakes*(i-b)));
				snakes = max(snakes, groups[b]);
			}
		}
	}

	// output
	fout<< DP[N][K]-total_snakes <<endl;
	fout.close();
	return 0;
}

```

# [walk.cpp](#2)
```cpp
/*
============================================================================
 Name        : cpp_template.cpp
 Author      : Dong Liu
 Website     : dongliu.template.com
============================================================================
*/
#include <algorithm>
#include <bitset>
#include <complex>
#include <cstring>
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

// declare any structures
#define ll long long
// declare any global variables
int N, K;
bool visited[7510];
long long best[7510];
// declare any functions
ll min0(ll a, ll b){
	if(a<b) return a;
	return b;
}
ll max0(ll a, ll b){
	if(a>b) return a;
	return b;
}
void mst(){
	for(int i=1; i<=N; i++){
		best[i] = 1000000000000;
		visited[i] = false;
	}
	for(int i=1; i<=N; i++){
		int k = -1;
		for(int j=1; j<=N; j++){
			if(!visited[j] && (k==-1 or best[j]<best[k])) k=j;
		}
		visited[k] = true;
		for(int j=1; j<=N; j++){
			if(!visited[j]){
				long long temp = (2019201913*min0(k, j)+2019201949*max0(k, j))%2019201997;
				best[j] = min0(best[j], temp);
			}
		}
	}
}
int main() {

	// fstream
	ifstream fin ("walk.in");
	ofstream fout ("walk.out");

	// input

	fin >> N >> K;
	// main
	mst();

	sort(best, best+N+1);
//	for(int i=1; i<=N; i++){
//		cout <<"best["<<i<<"] = "<<best[i]<<endl;
//	}
	// output
	fout << best[N-K+1];
	//close
	fout.close();
	return 0;
}

```

