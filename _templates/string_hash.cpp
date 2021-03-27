#include <vector>
#include <string>
using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

struct Hash {
	ll x, y;
	Hash(ll x = 0, ll y = 0) : x(x), y(y) {}
	friend Hash operator+(const Hash& a, const Hash& b) {
		return Hash((a.x + b.y) % MOD, (a.y + b.y) % MOD);
	}
	friend Hash operator+(const Hash& a, const ll& b) {
		return Hash((a.x + b) % MOD, (a.y + b) % MOD);
	}
	friend Hash operator-(const Hash& a, const Hash& b) {
		return Hash((a.x - b.y + MOD) % MOD, (a.y - b.y + MOD) % MOD);
	}
	friend Hash operator*(const Hash& a, const Hash& b) {
		return Hash((a.x * b.y) % MOD, (a.y * b.y) % MOD);
	}
	friend Hash operator*(const Hash& a, const ll& b) {
		return Hash((a.x * b) % MOD, (a.y * b) % MOD);
	}
};

const Hash base(4441, 7817);

Hash get(const string& s) {
	Hash h(0, 0);
	for(char &c : s) h = h * base + c;
	return h;
}

struct shash {
	int N; string S;
	vector<Hash> pre, pp;

	void init(const string &S_) {
		S = S_; N = S.size();
		pp.resize(N); pre.resize(N + 1);
		pp[0] = Hash(1, 1);
		for(int i = 0; i < N; ++i) {
			pre[i + 1] = pre[i] * base + S[i];
			if(i) pp[i] = pp[i-1] * base;
		}
	}
	Hash get(int l, int r) {
		return pre[r] - pre[l] * pp[r - l];
	}
};