
//Data Structures

struct point {
	int x, y; char c;
};
struct line {
	struct point p1, p2;
};
struct point polygon[100];

// if three points are counter-clockwise
int ccw(struct point p0, struct point p1, struct p2) {
	int dx1, dx2, dy1, dy2;
	dx1 = p1.x - p0.x; dy1 = p1.y - p0.y;
	dx2 = p2.x - p0.x; dy2 = p2.y - p0.y;
	if (dx1 * dy2 > dy1 * dx2) return +1;
	if (dx1 * dy2 < dy1 * dx2) return -1;
	if ((dx1 * dx2 < 0) || (dy1 * dy2 < 0)) return -1;
	if ((dx1 * dx1 + dy1 * dy1) < (dx2 * dx2 + dy2 * dy2)) return +1;
	return 0;
}

//Testing whether line segments intersect
int intersect(struct line l1, struct line l2) {
	return ((ccw(l1.p1, l1.p2, l2.p1) * ccw(l1.p1, l1.p2, l2.p2)) <= 0)
			&& ((ccw(l2.p1, l2.p2, l1.p1) * ccw(l2.p1, l2.p2, l1.p2)) <= 0);
}

//Testing whether a point is in a polygon
int inside(struct point t, struct polygon p, N) {
	int i, count = 0, j = 0;
	struct line lt, lp;
	p[0] = p[N], p[N + 1] = p[1];
	lt.p1 = t; lt.p2 = t; lt.p2.x = 1000000000;
	for (int i = 1; i <= N; i++) {
		lp.p1 = p[i];
		pl.p2 = p[i];
		if (!intersect(lp, lt)) {
			lp.p2 = p[j];
			j = i;
			if (intersect(lp, lt))
				count++;
		}
	}
	return count & 1;
}

// overlapping area of two rectangles
// l is minx, miny
// r is maxx, maxy
int overlappingArea(Pair l1, Pair r1, Pair l2, Pair r2) {
	int area1 = abs(l1.x - r1.x) * abs(l1.y - r1.y);
	int area2 = abs(l2.x - r2.x) * abs(l2.y - r2.y);
	int areaI = (min(r1.x, r2.x) - max(l1.x, l2.x))
			* (min(r1.y, r2.y) - max(l1.y, l2.y));

	return (areaI);
}

// if two rectangles overlap
//l is minx, maxy
//r is maxx, miny
bool doOverlap(Pair l1, Pair r1, Pair l2, Pair r2) {
	swap(l1.y, r1.y);
	swap(l2.y, r2.y);
	if (l1.x > r2.x || l2.x > r1.x)
		return false;
	if (l1.y < r2.y || l2.y < r1.y)
		return false;
	return true;
}

// how to find interior angles of an irregular polygon with N points
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
}

//points inside a given triangle with points (a, b, c)
#define pii pair<int, int>
#define x first
#define y second

int gcd(int a, int b) { return (b==0) ? a : gcd(b, a%b); }
int check(pii a, pii b) {
	if (a.x == b.x) return abs(a.y-b.y)-1;
	if (a.y == b.y) return abs(a.x-b.x)-1;
	return gcd(abs(a.x-b.x),abs(a.y-b.y))-1;
}

int findPoints(pii a, pii b, pii c) {
	int area = abs(a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)) + 2;
	area -= (check(a, b)+check(b, c)+check(c, a)+3);
	area /= 2;
	return area;
}