```cpp

/*
 ID: dongliu3
 TASK: ratios
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines

// global variables
int G[3];
int M[3][3];

// functions
int ok(int t[3]) {
	for (int i=0; i<3; i++)
		if (G[i] && t[i]%G[i]) return -1;
	int ta = -1;
	for (int i=0; i<3; i++)
		if (G[i] != 0) ta = (t[i]/G[i]);
	for (int i=0; i<3; i++)
		if (ta*G[i] != t[i]) ta = -1;
	return ta;
}
int main() {
	// local variables

	// fstream
	ifstream fin("ratios.in");
	ofstream fout("ratios.out");

	// input
	for (int i=0; i<3; i++) fin >> G[i];
	for (int i=0; i<3; i++)
	for (int j=0; j<3; j++)
		fin >> M[i][j];

	// main
	int T[3];
	for (T[0]=0; T[0]<100; T[0]++)
	for (T[1]=0; T[1]<100; T[1]++)
	for (T[2]=0; T[2]<100; T[2]++) {
		if (T[0] == 0 && T[1] == 0 && T[2] == 0) continue;
		int S[] = {0, 0, 0};
		for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			S[i] += T[j]*M[j][i];
		int ta = ok(S);
		if (ta != -1) {
			fout << T[0]<<" "<<T[1]<<" "<<T[2]<<" "<<ta<<endl;
			return 0;
		}
	}
	// output
	fout <<"NONE"<<endl;
	return 0;
}
```