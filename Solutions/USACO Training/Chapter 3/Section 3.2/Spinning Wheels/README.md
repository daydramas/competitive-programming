# Spinning Wheels
```cpp
/*
 ID: dongliu3
 TASK: spin
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
struct wheel {
	int s, w;
	int a[5], e[5];
};
// global variables
wheel W[5];
int mark[360];
int ans = -1;

// functions

int main() {
	// local variables

	// fstream
	ifstream fin("spin.in");
	ofstream fout("spin.out");

	// input
	for (int i=0; i<5; i++) {
		fin >> W[i].s >> W[i].w;
		for (int j=0; j<W[i].w; j++) {
			fin >> W[i].a[j] >> W[i].e[j];
		}
	}

	// main
	for (int a=0, t=0; a<360; a++, t++) {
		fill(mark, mark+360, 0);
		for (int i=0; i<5; i++) {
			int ss = t*W[i].s;
			for (int j=0; j<W[i].w; j++) {
				for (int k=(ss+W[i].a[j]); k<=(ss+W[i].a[j]+W[i].e[j]); k++) {
					mark[k%360]++;
					if (mark[k%360] == 5 && ans == -1) {
						ans = t;
					}

				}
			}
		}
	}
	// output
	if (ans == -1) fout <<"none"<<endl;
	else fout << ans << endl;
	return 0;
}
```