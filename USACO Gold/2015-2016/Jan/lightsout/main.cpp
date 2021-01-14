/*
 ID: dongliu3
 TASK: lightsout
 LANG: C++
 */

#include <bits/stdc++.h>
using namespace std;

// structures/defines
#define ll long long
#define pii pair<ll, ll>
#define x first
#define y second
#define PI 3.1415926535
#define HM 10000000007
#define HA 1000000007
#define HB 1001
// global variables
int N;
pii barn[200], nbarn[200], d[200];
ll slope[200], dist[200], rdist[200], pdist[200], angle[200];
multiset<ll> H[201];
ll ans = -1;
//functions
ll hext(ll h, ll ch) {
	return (1ll * h * HA + ch + HB) % HM;
}
int getLength(pii X, pii Y) {
	ll xDiff = X.first - Y.first;
	ll yDiff = X.second - Y.second;
	return xDiff * xDiff + yDiff * yDiff;
}
void calculateAngle(int i, pii A, pii B, pii C) {
	// Square of lengths be a2, b2, c2
	ll a2 = getLength(B, C);
	ll b2 = getLength(A, C);
	ll c2 = getLength(A, B);

	// length of sides be a, b, c
	float a = sqrt(a2);
	float b = sqrt(b2);
	float c = sqrt(c2);

	// From Cosine law
	float alpha = acos((b2 + c2 - a2) / (2 * b * c));

	// Converting to degree
	alpha = alpha * 180 / PI;

	// printing all the angles
	int na = alpha;
	if (B.x < A.x || B.y < A.y) {

		na = 360 - na;
	}
	angle[i] = (na);
//	cout << "angle[" << i << "] = " << na << "\n";
}
int main() {
//  local variables
//  fstream
	ifstream fin("lightsout.in");
	ofstream fout("lightsout.out");

//  initialize
	fin >> N;
	for (int i = 0; i < N; i++) {
		fin >> barn[i].x >> barn[i].y;
	}
	for (int i = 0; i < N; i++) {
		int pi = max(0, i - 1), ni = (i + 1) % N;
		dist[ni] = abs(barn[ni].x - barn[i].x) + abs(barn[ni].y - barn[i].y);
		d[ni] = pii(barn[ni].x - barn[i].x, barn[ni].y - barn[i].y);
		pdist[i] = pdist[pi] + dist[i];
//		cout << "dist[" << ni << "] = " << dist[ni] << endl;
	}
//	cout << pdist[0] << " pdist0" << endl;
//	for (int i = 0; i < N; i++) {
//		cout << pdist[i] << " vs " << pdist[N - 1] + dist[0] - pdist[i] << endl;
//	}
//	for (int i = 0; i < N; i++) {
//		int pi = (i + N - 1) % N, ni = (i + 1) % N;
//		calculateAngle(i, barn[i], barn[pi], barn[ni]);
//	}
	for (int i = 0; i < N; i++) {
		int last = (i - 1 + N) % N;
		int next = (i + 1) % N;
		double x1 = barn[i].x - barn[last].x;
		double y1 = barn[i].y - barn[last].y;
		double x2 = barn[next].x - barn[i].x;
		double y2 = barn[next].y - barn[i].y;
		double theta1 = atan2(y1, x1) * 180 / 3.1415926358979323;
		double theta2 = atan2(y2, x2) * 180 / 3.1415926358979323;
		angle[i] = (180 + theta1 - theta2 + 360);
		while (angle[i] > 360)
			angle[i] -= 360;
//		cout << "angle[" << i << "] = " << angle[i] << endl;
	}
//  main
	for (int i = 1; i < N; i++) {
		ll chsh = hext(0, angle[i]);
//		H.insert(chsh);
//		cout << "1hsh = " << chsh << endl;
		int sz = 0;
		for (int j = i + 1; j != i; j++) {
			j %= N;
			if (j == 0) {
				break;
			}
//			chsh = hext(chsh, dist[j]);
			chsh = hext(chsh, d[j].x);
			chsh = hext(chsh, d[j].y);
//			cout << "2hsh = " << chsh << endl;
			chsh = hext(chsh, angle[j]);
//			cout << "2hsh = " << chsh << endl;
//			cout << i << " to " << j << " = " << chsh << endl;
			H[sz].insert(chsh);
			if (j == 0) {
				break;
			}
			sz++;
		}
	}
//	for (multiset<ll>::iterator it = H.begin(); it != H.end(); ++it) {
//		cout << *it << " c: " << H.count(*it) << endl;
//	}
	for (int i = 1; i < N; i++) {
		ll cdist = 0;
		ll chsh = hext(0, angle[i]);
//		cout << "0" << endl;
		int sz = 0;

		for (int j = i + 1; j != i; j++, j %= N) {
			j %= N;
//			chsh = hext(chsh, dist[j]);
			chsh = hext(chsh, d[j].x);
			chsh = hext(chsh, d[j].y);
			chsh = hext(chsh, angle[j]);
			cdist += dist[j];
//			cout << i << " to " << j << " dist = " << cdist << endl;
//			cout << "cdist: " << cdist << " hsh: " << chsh << endl;
			if (H[sz].count(chsh) <= 1 || j == 0) {
//				if (j == 0) {
//					cout << "hi" << endl;
//				}
				ll odist = min(pdist[i], pdist[N - 1] + dist[0] - pdist[i]);
				cdist = min(cdist + pdist[j],
						cdist + pdist[N - 1] + dist[0] - pdist[j]);
//				cout << i << " to " << j << endl;
//				cout << cdist << " vs " << odist << endl;
				ans = max(ans, cdist - odist);
//				cout << i << " " << j << " " << ans << " " << cdist - odist
//						<< endl;
				break;
			}
			if (j == 0) {
				break;
			}
			sz++;
		}
	}
//  output
	fout << ans << endl;
	return 0;
}
