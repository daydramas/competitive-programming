#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int n, a[N], c[N], o[N];

long long d1[N], d2[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", a + i, c + i);
		o[i] = i;
	}
	sort(o + 1, o + n + 1, [&](int i, int j) {
		return a[i] < a[j];
	});
	memset(d1, 0x3f3f, sizeof(d1)); d1[1] = 0;
	for (int i, _i = 1; _i <= n; ++_i) {
		i = o[i];
		
	}
	
}