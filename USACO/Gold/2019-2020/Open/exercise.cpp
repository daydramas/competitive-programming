///*
// ID: dongliu3
// TASK: exercise
// LANG: C++
// */
//
//#include <bits/stdc++.h>
//using namespace std;
//
//// structures/defines
//
//// global variables
//int N, M;
//int prime[3000], pin = 0;
//long long sum = 0;
////set<long long> used;
////functions
//bool isPrime(int n) {
//	if (n <= 1)
//		return false;
//	if (n <= 3)
//		return true;
//	if (n % 2 == 0 || n % 3 == 0)
//		return false;
//
//	for (int i = 5; i * i <= n; i = i + 6)
//		if (n % i == 0 || n % (i + 2) == 0)
//			return false;
//	return true;
//}
//void createPrime() {
//	for (int i = 2; i < N; i++) {
//		if (isPrime(i)) {
////			int num = 1;
////			for (int j = 1; j < i; j++) {
////				num = num * i;
////				prime[++pin] = num;
////			}
//			prime[++pin] = i;
//			prime[++pin] = i * 2;
//		}
//	}
//}
//void dfs(int i, int sum1, long long time1) {
//	if (sum1 > N)
//		return;
//	if (i == pin + 1) {
//		if (time1 > N) {
////			cout << "2adding " << time1 << endl;
//			sum = (sum + time1) % M;
////			cout << "sum: " << sum << endl;
//		}
//		return;
//	}
//	dfs(i + 1, sum1, time1);
//	dfs(i + 1, sum1 + prime[i], (time1 * prime[i]) % M);
//}
//int main() {
//// local variables
//
//// fstream
//	ifstream fin("exercise.in");
//	ofstream fout("exercise.out");
//
//// input
//	fin >> N >> M;
//
//// main
//	createPrime();
////	pin = N;
////	for (int i = 1; i <= N; i++)
////		prime[i] = i;
////	for (int i = 1; i <= pin; i++)
////		cout << prime[i] << endl;
//	for (int i = 1; i <= N; i++) {
//		sum = (sum + i) % M;
////		cout << "adding " << i << endl;
//	}
//	dfs(1, 0, 1);
//// output
//	fout << sum << endl;
//	return 0;
//}
/*
 ID: dongliu3
 TASK: exercise
 LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

// structures/defines
#define INF 1000000000

// global variables
int N, M;
int dp[5000005];
//functions

int main() {
	// local variables

	// fstream
	ifstream fin("exercise.in");
	ofstream fout("exercise.out");
	// input
	fin >> N >> M;

	// main
	long long sum = 0;
	for (int i = 0; i <= 1000000; i++)
		dp[i] = i;
	for (int i = 0; i < 1000000; i++) {
//		if (i < 10)
//			cout << dp[i] << ": dp[" << i << "]" << endl;
		if (dp[i] <= N && i) {
//			cout << "i: " << i << endl;
//			cout << i << endl;
			sum = (sum + i) % M;
		}
		for (int j = 1; j <= N; j++) {
			if (i * j <= 500000) {
				dp[i * j] = min(dp[i * j], dp[i] + j);
			}
		}
	}
// output
	fout << sum << endl;
	return 0;
}
