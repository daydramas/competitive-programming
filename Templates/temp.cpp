/**
 * $1
 * Created on $CURRENT_YEAR-$CURRENT_MONTH-$CURRENT_DATE
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N (1 << 18) // 2e5

template <class T> void read(T &x) { cin >> x; }
template <class T, class... U> void read(T &x, U &...y) { read(x), read(y...); }
template <class T> void write(const T &x) { cout << x; }
template <class T, class... U> void write(T x, U... y) { write(x, y...); }
template <class T> void print(T x) { write(x, '\n'); }
template <class T, class... U> void print(T x, U... y) { write(x, ' '), print(y...); }

int main() {
	cin.tie(0)->sync_with_stdio(0);

	$0
}