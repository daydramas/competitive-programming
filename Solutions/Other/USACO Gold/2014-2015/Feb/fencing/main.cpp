/*
 ID: dongliu3
 TASK: fencing
 LANG: C++
 */

//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

// structures/defines
#define Point pair<int, int>
#define x first
#define y second

// global variables
int N, Q;
Point points[200000];
Point p0;
vector<Point> polygon;
pair<Point,
Point> side[200000];
vector<pair<double,
pair<Point, Point> > > v;
//functions
int distSq(Point p1, Point p2) {
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}
double getSlope(Point p1, Point p2) {
	if (p2.x - p1.x == 0) {
		return 0;
	}
	if (p2.y - p1.y == 0) {
		return -10000000;
	}
	return -1 / ((p2.y - p1.y) * 1.0 / (p2.x - p1.x) * 1.0);
}
int orientation(Point p, Point q, Point r) {
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

	if (val == 0)
		return 0;  // colinear
	return (val > 0) ? 1 : 2; // clock or counterclock wise
}
int compare(const void *vp1, const void *vp2) {
	Point *p1 = (Point*) vp1;
	Point *p2 = (Point*) vp2;

	int o = orientation(p0, *p1, *p2);
	if (o == 0)
		return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;

	return (o == 2) ? -1 : 1;
}
Point nextToTop(stack<Point> &S) {
	Point p = S.top();
	S.pop();
	Point res = S.top();
	S.push(p);
	return res;
}
void convexHull() {
	int ymin = points[0].y, min = 0;
	for (int i = 1; i < N; i++) {
		int y = points[i].y;
		if ((y < ymin) || ((ymin == y && points[i].x < points[min].x))) {
			ymin = points[i].y, min = i;
		}
	}
	swap(points[0], points[min]);
	p0 = points[0];
	qsort(&points[1], N - 1, sizeof(Point ), compare);
	int m = 1;
	for (int i = 1; i < N; i++) {
		while (i < N - 1 && orientation(p0, points[i], points[i + 1]) == 0)
			i++;
		points[m] = points[i];
		m++;
	}
	if (m < 3) {
		return;
	}
	stack<Point> S;
	S.push(points[0]);
	S.push(points[1]);
	S.push(points[2]);
	for (int i = 3; i < m; i++) {
		while (orientation(nextToTop(S), S.top(), points[i]) != 2)
			S.pop();
		S.push(points[i]);
	}
	while (!S.empty()) {
		polygon.push_back(Point(S.top().x, S.top().y));
		S.pop();
	}
}
void calculateSide() {
//	cout << N << " " << Q << endl;
	for (int i = 0; i < N; i++) {
		int nxt = (i + 1) % N;
//		cout << points[i].x << " " << points[i].y << "  to " << points[nxt].x
//				<< " " << points[nxt].y << endl; //"  is "
//				<< getSlope(points[i], points[nxt]) << endl;
		v.push_back(
				make_pair(getSlope(points[i], points[nxt]),
						make_pair(points[i], points[nxt])));
	}
//	cout << N << " " << Q << endl;
	sort(v.begin(), v.end());
//	cout << N << " " << Q << endl;
	double m = 1000000000, M = -1000000000;
	Point mi, Mi;
	for (int i = 0; i < N; i++) {
		double temp = points[i].y * v[0].first + points[i].x;
//		cout << points[i].x << " " << points[i].y << " with slope "
//				<< v[0].first << " : " << temp << endl;
		if (temp < m) {
			m = temp;
			mi = points[i];
		}
		if (temp > M) {
			M = temp;
			Mi = points[i];
		}
	}
//	cout << "0: " << mi.x << " " << mi.y << " and " << Mi.x << " " << Mi.y
//			<< endl;
	side[0] = { mi, Mi };
	for (int j = 1; j < v.size(); j++) {
//		double t1 = mi.second - v[j].first * mi.first;
//		double t2 = Mi.second - v[j].first * Mi.second;
//		double t3 = v[j].second.first.second
//				- v[j].first * v[j].second.first.first;
//		double t4 = v[j].second.second.second
//				- v[j].first * v[j].second.second.first;
		double t1 = mi.second * v[j].first + mi.first;
		double t2 = Mi.second * v[j].first + Mi.first;
		double t3 = v[j].second.first.second * v[j].first
				+ v[j].second.first.first;
		double t4 = v[j].second.second.second * v[j].first
				+ v[j].second.second.first;
//		cout << t1 << " " << t2 << " " << t3 << " " << t4 << endl;
		if (t3 < t1 && t3 < t2 && t3 < t4) {
			m = t3;
			mi = v[j].second.first;
		} else if (t4 < t4 && t4 < t2 && t4 < t3) {
			m = t4;
			mi = v[j].second.second;
		}

		if (t3 > t1 && t3 > t2 && t3 > t4) {
			M = t3;
			Mi = v[j].second.first;
		} else if (t4 > t4 && t4 > t2 && t4 > t3) {
			M = t4;
			Mi = v[j].second.second;
		}
		side[j] = { mi, Mi };
	}
}
int binarySearch(double slope) {
	int s = 0, b = v.size();
	while (s < b) {
		int m = (s + b) / 2;
		if (s == m) {
			break;
		}
		if (slope < v[m].first) {
			b = m - 1;
		} else {
			s = m;
		}
	}
	return s;
}
int main() {
// local variables

// fstream
	ifstream fin("3.in");
	ofstream fout("fencing.out");
// input
	fin >> N >> Q;
	for (int i = 0; i < N; i++) {
		fin >> points[i].x >> points[i].y;
	}
// main
//	cout << N << " " << Q << endl;
	convexHull();
//	cout << N << " " << Q << endl;
	calculateSide();
// output
//	cout << N << " " << Q << endl;
	for (int i = 1; i <= Q; i++) {
		int a;
		fin >> a;
		if (a == 1) {
			int b, c;
			fin >> b >> c;
			points[N++] = make_pair(b, c);
			convexHull();
			calculateSide();
		} else {
			long long A, B, C;
			fin >> A >> B >> C;
			double slope;
			if (A == 0) {
				slope = -10000000;
			} else if (B == 0) {
				slope = 0;
			} else {
				slope = 1 / (A * (1.0) / B * (1.0));
			}
//			cout << A << " " << B << " " << C << " = " << slope << endl;
			int in = binarySearch(slope);
			double A1 = A * side[in].first.x + B * side[in].first.y - C;
			double A2 = A * side[in].second.x + B * side[in].second.y - C;

//			cout << side[in].first.x << " " << side[in].first.y << endl;
//			cout << side[in].second.x << " " << side[in].second.y << endl;
			if (A1 * A2 > 0) {
				cout << "YES" << endl;
			} else
				cout << "NO" << endl;
		}
	}
	return 0;
}
