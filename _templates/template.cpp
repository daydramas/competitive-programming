#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

#define f         first
#define s        second
#define pb    push_back

#define sz(x)                     (x).size()
#define all(x)              begin(x), end(x)
#define mem(a, x)    memset(a, x, sizeof(a))

#define FOR(i, a, b)    for (int i = (a); i <= (b); ++i)
#define F0R(i, x)          for (int i = 0; i < (x); ++i)
#define ROF(i, a, b)    for (int i = (b); i >= (a); --i)
#define R0F(i, x)     for (int i = (x) - 1; i >= 0; --i)
#define each(x, a)                     for (auto& x : a)

template <class T> bool ckmin(T& a, const T& b) { return (a > b ? a = b, 1 : 0); }
template <class T> bool ckmax(T& a, const T& b) { return (a < b ? a = b, 1 : 0); }

void read(double &x) { string s; cin >> s; x = stod(s); }
void read(long double &x) { string s; cin >> s; x = stold(s); }
template <class T> void read(T &x) { cin >> x; }
template <class T, class... U> void read(T &x, U &...y) { read(x), read(y...); }
template <class T> void write(const T &x) { cout << x; }
template <class T, class... U> void write(T x, U... y) { write(x, y...); }
template <class T> void print(T x) { write(x, '\n'); }
template <class T, class... U> void print(T x, U... y) { write(x, ' '), print(y...); }

const int MOD = 1000000007;
const int INF = 1000000000;
const int N   = 100005;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
}