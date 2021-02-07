#include <vector>
using namespace std;

const int MOD = 1e9+7;

template<class T> struct Factorial {
	vector<T> fact, ifact;
	T exp(T b, T p) {
		T r = 1;
		for(; p; p /= 2, b *= b) if(p & 1) r *= b;
		return r;
	}
	Factorial(int N = 0) fact(N + 1), ifact(N + 1) {
		fact[0] = 1, ifact[0] = 1;
		for(int i=1; i<=N; i++) {
			fact[i] = fact[i-1] * i % MOD;
			ifact[i] = exp(fact[i], MOD - 2);
		}
	}
};