<div align="center"> <a href="#BigNumcpp">BigNum.cpp</a> | <a href="#BinomialCoefficientcpp">BinomialCoefficient.cpp</a> | <a href="#ConvexHullcpp">ConvexHull.cpp</a> | <a href="#FenwickTreecpp">FenwickTree.cpp</a> | <a href="#Geometrycpp">Geometry.cpp</a> | <a href="#SegTree-Lazycpp">SegTree-Lazy.cpp</a> | <a href="#SegTreecpp">SegTree.cpp</a> | <a href="#Spathcpp">Spath.cpp</a> | <a href="#Treescpp">Trees.cpp</a> | <a href="#UnionFindcpp">UnionFind.cpp</a> </div>

# [BigNum.cpp](#0)
```cpp
struct bignum {
    vi v;
    bignum(vector<int> v) : v(v) {}
    bignum(int x) {
        v.resize(MX, 0);
        for (int i=0; i<MX && x!=0; i++) {
            v[i] = x % 10;
            x /= 10;
        }
    }
    bignum operator+(const bignum &x) {
        vi out(MX, 0);
        int carry = 0;
        for0(i, MX) {
            out[i] = v[i] + x.v[i] + carry;
            carry = out[i] / 10;
            out[i] %= 10;
        }
        return bignum(out);
    }
    bignum operator-(const bignum &x) {
        vi out = v;
        for0(i, MX) {
            if (out[i] < x.v[i]) {
                out[i + 1]--;
                out[i] += 10;
            }
            out[i] -= x.v[i];
        }
        return bignum(out);
    }
    bignum operator*(const int x) {
        vi out = v;
        int carry = 0;
        for0(i, MX) {
            out[i] = out[i]*x + carry;
            carry = out[i]/10;
            out[i] %= 10;
        }
        return bignum(out);
    }
    void print() {
        int in = MX-1;
        while (in > 0 && v[in] == 0) in--;
        while (in >= 0) cout << v[in--];
        cout <<"\n";
    }
};
```

# [BinomialCoefficient.cpp](#1)
```cpp
struct nCr {

	int n;
	vector<vector<int> > dp;

	nCr(int n_) {
		n = n_;
		dp.assign(n+1, vector<int> (n+1, -1));
		build();
	}

	void build() {
		for(int i=0; i<=n; i++) {
			dp[i][i] = dp[i][0] = 1;
		}
	}

	int get(int a, int b) {
		if (dp[a][b]!=-1) return dp[a][b];
		return (dp[a][b] = get(a-1, b-1)+get(a-1, b));
	}
};

```

# [ConvexHull.cpp](#2)
```cpp
int orientation(ii p, ii q, ii r) { 
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
} 
  
// Prints convex hull of a set of n points. 
vii convexHull(vii points) { 
    if (n < 3) return; 
    vector<ii> hull; 
  
    // Find the leftmost point 
    int l=0; 
    for (int i=1; i<sz(points); i++) 
        if (points[i].x < points[l].x)  l = i; 
  
    int p = l, q; 
    do { 
        hull.push_back(points[p]); 
        q = (p+1)%n; 
        for0(i, sz(points)) { 
           if (orientation(points[p], points[i], points[q])==2) 
               q = i; 
        } 
        p=q; 
  
    } while (p!=l);  
  
    return hull;
} 
```

# [FenwickTree.cpp](#3)
```cpp
struct BIT {

	int n;
	vector<int> t;

	BIT(int n_) {
		n = n_;
		t.assign(n+1, 0);
	}

	void update(int i, int value) {
		for (; i<=n; i+=i&(-i)) t[i] += value;
	}

	int get(int i) {
		int sum = 0;
		for(; i>0; i-=i&(-i)) sum += t[i];
		return sum;
	}

};

```

# [Geometry.cpp](#4)
```cpp

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
```

# [SegTree-Lazy.cpp](#5)
```cpp
struct lazySegTree {

	int n;
	vector<int> st, lz;

	lazySegTree(int n_) {
		n = n_;
		st.assign(4*n, 0);
		lz.assign(4*n, 0);
		build(1, 1, n);
	}

	int left(int i) { return i*2; }
	int right(int i) { return i*2+1; }

	void build(int id, int L, int R) {
		if (L == R) {
			st[id] = a[L];
			return;
		}
		build(left(id), L, (L+R)/2);
		build(right(id), (L+R)/2+1, R);
		st[id] = st[left(id)] + st[right(id)];
	}

	void propagate(int id, int L, int R) {
		st[id] += lz[id] * (R-L+1);
		if (L!=R) {
			lz[left(id)] += lz[id];
			lz[right(id)] += lz[id];
		}
		lz[id] = 0;
	}

	void update(int id, int L, int R, int l, int r, int value) {
		if (lz[id]!=0) propagate(id, L, R);
		if (l > R || r < L) return;
		if (l <= L && R <= r) {
			lz[id] += value;
			propagate(id, L, R);
			return;
		}
		if (L == R) return;
		update(left(id), L, (R+L)/2, l, r, value);
		update(right(id), (R+L)/2+1, R, l, r, value);
		st[id] = st[left(id)] + st[right(id)];
	}

	void update(int L, int R, int value) {
		update(1, 1, n, L, R, value);
	}

	int get(int id, int L, int R, int l, int r) {
		if (lz[id]!=0) propagate(id, L, R);
		if (l > R || r < L) return 0;
		if (l <= L && R <= r) return st[id];
		return get(left(id), L, (R+L)/2, l, r) + get(right(id), (R+L)/2+1, R, l, r);
	}

	int get(int L, int R) {
		return get(1, 1, n, L, R);
	}
};

```

# [SegTree.cpp](#6)
```cpp
struct segTree {

	int n;
	vector<int> st;

	segTree(int n_) {
		n = n_;
		st.assign(4*n, 0);
		build(1, 1, n);
	}

	int left(int i) { return i*2; }
	int right(int i) { return i*2+1; }

	void build(int id, int L, int R) {
		if (L == R) {
			st[id] = a[L];
			return;
		}
		build(left(id), L, (L+R)/2);
		build(right(id), (L+R)/2+1, R);
		st[id] = st[left(id)] + st[right(id)];
	}

	void update(int id, int L, int R, int P, int value) {
		if (P > R || P < L) return;
		if (P >= L && P <= R) st[id] += value;
		if (L == R) return;
		update(left(id), L, (R+L)/2, P, value);
		update(right(id), (R+L)/2+1, R, P, value);
	}

	void update(int P, int value) {
		update(1, 1, n, P, value);
	}

	int get(int id, int L, int R, int l, int r) {
		if (l > R || r < L) return 0;
		if (l <= L && R <= r) return st[id];
		return get(left(id), L, (R+L)/2, l, r) + get(right(id), (R+L)/2+1, R, l, r);
	}

	int get(int L, int R) {
		return get(1, 1, n, L, R);
	}
};

```

# [Spath.cpp](#7)
```cpp
// Dijkstra
#define pii pair<int, int>
#define INF 1000000000
int dist[100]; vector<pii> adj[100];
void dijkstra(int src) {
	fill(dist+2, dist+101, INF);
	queue<int> Q;
	dist[src] = 0; Q.push(src);
	while(!Q.empty()) {
		int f = Q.front(); Q.pop();
		for (pii d : adj[src]) if (dist[d.first] > dist[f]+d.second) {
				dist[d.first] = dist[f.first]+d.second;
				Q.push(d.first, dist[d.first]);
		}
	}
}

// Floyd Warshall
int dist[100][100];
void floydWarshall() {
	for (int k=1; k<=100; k++) 
	for (int i=1; i<=100; i++) 
	for (int j=1; j<=100; j++)
		dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
}

// Bellman Ford
#define INF 1000000000
struct node {
	int to, from, weight;
	node(int to, int from, int weight) : to(to), from(from), weight(weight) {}
}
int dist[100];
vector<node> adj;
void bellmanFord(int src) {
	for (int i = 1; i <= N; i++) dist[i] = INF;
	dist[src] = 0;
	for (int i = 1; i < N; i++) for (node j : adj) 
		if (dist[j.to] > dist[j.from] + j.weight) 
			dist[j.to] = dist[j.from] + j.weight;
	
}
```

# [Trees.cpp](#8)
```cpp
struct tree {

	int n, logN;
	vector<vector<int> > adj, lca;
	vector<int> sz, depth;

	tree(int n_) {
		n = n_;
		logN = log2(n)+5;
		sz.assign(n+1, 1);
		lca.assign(n+1, vector<int>(logN+5, 0));
		depth.assign(n+1, 0);
		adj.resize(n+1);
	}

	void addEdge(int a, int b) {
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	void build(int source, int parent) {
		lca[source][0] = parent;
		sz[parent] += sz[source];
		if (source-1) depth[source] = depth[parent]+1;
		for (int child : adj[source]) if (parent != child) {
			build(child, source);
		}
	}

	void buildLCA() {
		for (int i=1; i<logN; i++) {
			for (int j=1; j<=n; j++) {
				lca[j][i] = lca[lca[j][i-1]][i-1];
			}
		}
	}

	int LCA(int u, int v) {
		if(depth[u] > depth[v]) swap(v, u);
		int d = depth[v] - depth[u];
		for(int i = 0; i < logN; i++) {
			if(d & (1 << i)) {
				v = lca[v][i];
			}
		}
		if(u == v) return u;
		for(int i=logN-1; i>=0; i--) {
			if(lca[u][i] != lca[v][i]) {
				u = lca	[u][i];
				v = lca[v][i];
			}
		}
		return lca[u][0];
	}

	void build() {
		build(1, 0);
		buildLCA();
	}

	int getDist(int a, int b) {
		return depth[a]+depth[b]-(2*depth[LCA(a, b)]);
	}

	int getCentroid(int source, int parent, int size) {
		for (int child : adj[source])
			if (source != parent && sz[child] > n/2) return getCentroid(child, source, size);
		return source;
	}
	
	int centroidDecomp(int source) {
		int centroid = getCentroid(source, source, sz[source]);
		for (int child : adj[centroid]) {
			adj[child].erase(find(adj[child].begin(),adj[child].end(), centroid));
		}
		
		// do whatever you need to do
		
		for (int child : adj[centroid]) {
			adj[centroidDecomp(child)] = centroid;
		}
		return centroid;
	}

};

```

# [UnionFind.cpp](#9)
```cpp
struct uf { 
    vector<int> pa;
    uf(int n) {
        pa = vector<int>(n+10, -1);
    }
    int find(int i) {
        if (pa[i] == -1) return i;
        return pa[i]=find(pa[i]);
    } 
    void merge(int x, int y) {
        int x2=find(x), y2=find(y);
        if (x2!=y2) {
            pa[x2]=y2, pa[x]=y2, pa[y]=y2;
        }
    }
};

```

