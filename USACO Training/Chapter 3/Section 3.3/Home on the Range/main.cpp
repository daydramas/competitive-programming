/*
 ID: dongliu3
 TASK: range
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
int N;
bool F[251][251];
int dp[251][251];
int cnt[251];

// functions

int main() {
	// local variables

	// fstream
	ifstream fin("range.in");
	ofstream fout("range.out");

	// input
	fin >> N;
	for (int i=1; i<=N; i++) {
		string str; fin >> str;
		cnt[i] = 0;
		for (int j=1; j<=N; j++) F[i][j] = (str[j-1]=='1');
	}
	// main
	for (int s=1; s<=N; s++) {
		for (int i=1; i<=(N-s+1); i++) {
			for (int j=1; j<=(N-s+1); j++) {
				int curr;
				if (s==1) curr = F[i][j];
				else {
					curr = dp[i][j]+1;
					if (curr >= s-1){
						for (int x=i; x<i+s; x++)
							if (!F[x][j+s-1]) curr = dp[i][j];
						for (int y=j; y<j+s; y++)
							if (!F[i+s-1][y]) curr = dp[i][j];
					}
				}
				if (curr == s) cnt[s]++;
				dp[i][j] = curr;
			}
		}
	}
	// output

	for (int i=2; i<=N; i++) {
		if (cnt[i]) fout << i << " " << cnt[i] << endl;
	}
	return 0;
}