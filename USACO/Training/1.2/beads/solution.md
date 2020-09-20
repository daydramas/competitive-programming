# Solution to Broken Necklace
```cpp
/*
 ID: dongliu3
 TASK: beads
 LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

// define/structures

// global variables
int N; string bead;
bool visited[760];
// functions

int main() {
	// local variables

	// fstream
	ifstream fin("beads.in");
	ofstream fout("beads.out");

	// input
	fin >> N >> bead;
	// main
	int ans = 0;
	for(int i=0; i<=N; i++) {
		memset(visited, false, sizeof(bool)*(N));
		int li, ri, lc, rc; li=i-1; ri=i; lc=rc=-1;

		if(li == -1) li = N-1;
		if(ri == N) ri = 0;
		while(!visited[li] && (lc==-1 || bead[li]=='w' || bead[li]==lc)) {
			visited[li] = true;
			if(bead[li]!='w') lc=bead[li];
			li--;
			if(li == -1) li = N-1;
		} li++; if(li==N) li = 0;
		while(!visited[ri] && (rc==-1 || bead[ri]=='w' || bead[ri]==rc)) {
			visited[ri] = true;
			if(bead[ri]!='w') rc=bead[ri];
			ri++;
			if(ri == N) ri = 0;
		} ri--; if(ri==-1) ri = N-1;
		int ta;
		if(ri>li) ta=ri-li+1;
		else ta=ri+N-li+1;
		ans = max(ans, ta);
//		cout << ri << " " << li<<" -> "<< ta << endl;
	}
	// output
	fout << ans << endl;
	return 0;
}
```