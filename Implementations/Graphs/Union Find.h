#include <vector>
using namespace std;

struct DSU {
	int N; vector<int> dsu;
	DSU(int N = 0) : N(N), dsu(N+1, -1) {}
	int find(int x) {
		if(dsu[x] < 0) return x;
		return dsu[x] = find(dsu[x]);
	}
	bool comb(int x, int y) {
		x = find(x), y = find(y);
		if(x == y) return false;
		dsu[x] += dsu[y]; dsu[y] = 0;
		return true;
	}
};