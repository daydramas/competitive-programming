/*
 ID: dongliu3
 TASK: frac1
 LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

// structures / define
#define pii pair<int, int>
#define x first
#define y second

// global variables
int N;
vector<pii> cnt;
// functions
int gcd(int a, int b){
    if(b==0)
        return a;
    else
        return gcd(b, a % b);

}
bool myway(pii a, pii b) {
	return 1.0*a.x/a.y < 1.0*b.x/b.y;
}
int main() {
	// input

	// fstream
	ifstream fin("frac1.in");
	ofstream fout("frac1.out");

	// input
	fin >> N;

	// main
	cnt.push_back(pii(0, 1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (1.0 * i / j <= 1) {
				int GCD = gcd(i, j);
				pii temp = pii(i / GCD, j / GCD);
				cnt.push_back(temp);
			}
		}
	}
	sort(cnt.begin(), cnt.end(), myway);
	for (int i=0; i<cnt.size(); i++) {
		if(i!=0 && (1.0*cnt[i].x/cnt[i].y == 1.0*cnt[i-1].x/cnt[i-1].y)) continue;
		fout<<cnt[i].x<<"/"<<cnt[i].y<<endl;
	}
	// output
}