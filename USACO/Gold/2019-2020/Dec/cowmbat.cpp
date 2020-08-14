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
int N, M, K;
string S;
int d[27][27];
int c[100001][27], ps[100001][27];
int dp[100001][27], dm[100001];
//functions

int main() {
	// local variables

	// fstream
	ifstream fin("cowmbat.in");
	ofstream fout("cowmbat.out");

	// input
	fin >> N >> M >> K;
	fin >> S;
	for(int i=1; i<=M; i++) {
		for(int j=1; j<=M; j++) {
			fin >> d[i][j];
		}
	}
	// main
	for(int k=1; k<=M; k++) {
		for(int i=1; i<=M; i++) {
			for(int j=1; j<=M; j++) {
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
			}
		}
	}
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			c[i][j] = d[S[i-1]-'a'+1][j];
			ps[i][j] = ps[i-1][j]+c[i][j];
		}
	}
	for(int i=0; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			dp[i][j] = 1061109567;
		}
	}
	for(int i=1; i<=N; i++) {
		dm[i] = 1000000000;
		for(int j=1; j<=M; j++) {
			dp[i][j] = min(dp[i][j], dp[i-1][j]+c[i][j]);
			if(i>=K) {
				dp[i][j] = min(dp[i][j], ps[i][j]-ps[i-K][j]+dm[i-K]);
			}
			dm[i] = min(dm[i], dp[i][j]);
		}
	}
	// output
	fout << dm[N] << endl;
	return 0;
}