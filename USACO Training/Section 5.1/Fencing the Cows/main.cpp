  
/*
 ID: dongliu3
 TASK: fc
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
#define pii pair<double, double>
#define x first
#define y second
#define INF 1000000000

// global variables
int N;
pii point[10005]; double angle[10005];

// functions
bool comp1 (pii a, pii b) {
	if (a.y != b.y) return a.y < b.y;
	return a.x < b.x;
}
bool comp2 (int a, int b) {
	return angle[a] < angle[b];
}
double getAngle(pii i, pii j) {
	if (i.y == j.y) return -INF;
	return -1/((j.y-i.y)/(j.x-i.x));
}
int orientation(pii p, pii q, pii r){
    double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}
double sq(double a) { return a*a; };
double getDist(pii a, pii b) {
	return sqrt( sq(a.x-b.x) + sq(a.y-b.y) );
}
vector<pii> convexhull() {
	sort(point, point+N, comp1);
	int order[N];
	pii point2[N];
	order[0] = 0;
	for (int i=1; i<N; i++) {
		angle[i] = getAngle(point[0], point[i]);
		order[i] = i;
	}
	sort(order+1, order+N, comp2);
	for (int i=0; i<N; i++) {
		point2[i] = point[order[i]];
	}
	for (int i=0; i<N; i++) {
		point[i] = point2[i];
	}
	vector<pii> S;
	S.push_back(point[0]);
	S.push_back(point[1]);
	for (int i=2; i<N; i++) {
		while (S.size() >= 2 && orientation(S[S.size()-2], S.back(), point[i]) == 1) {
			S.pop_back();
		}
		S.push_back(point[i]);
	}
	return S;
}
int main() {
	// local variables

	// fstream
	ifstream fin("fc.in");
	ofstream fout("fc.out");

	// input
	fin >> N;
	for (int i=0; i<N; i++) fin >> point[i].x >> point[i].y;

	// main
	vector<pii> hull = convexhull();

	// output
	double ans = 0.0;
	for (int i=0; i<hull.size(); i++) {
		int j = (i+1)%hull.size();
		ans += getDist(hull[i], hull[j]);
	}
	fout << fixed << setprecision(2) << ans << endl;
	return 0;
}