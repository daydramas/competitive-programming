/*
 ID: dongliu3
 TASK: job
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
int N, M[2];
int T[2][30], A[2][30];
vector<int> C[2];
int ans[2] = {0, 0};

// functions
bool comp (int i, int j) { return i > j; }

int main() {
	// local variables

	// fstream
	ifstream fin("job.in");
	ofstream fout("job.out");

	// input
	fin >> N >> M[0] >> M[1];
	for (int i=0; i<2; i++) for (int j=0; j<M[i]; j++)
		fin >> T[i][j];
	for (int i=0; i<2; i++) for (int j=0; j<M[i]; j++)
		A[i][j] = T[i][j];

	// main
	C[0] = vector<int>(N, 0);
	for (int it=0; it<2; it++) {
		sort(C[it].begin(), C[it].end(), comp);
		for (int i : C[it]) {
			int in=-1;
			for (int j=0; j<M[it]; j++) if (in==-1 || (A[it][j]+i<A[it][in]+i)) {
				in = j;
			}
			int sum = A[it][in]+i;
			if (!it) C[it+1].push_back(sum);
			ans[it] = max(ans[it], sum);
			A[it][in] += T[it][in];
		}
	}
	// output
	fout << ans[0] << " " << ans[1] << endl;
	return 0;
}