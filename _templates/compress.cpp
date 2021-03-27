// coordinate compression

struct D {
	int x; // the value
	int p; // position
} aa[N];

int a[N]; // new, reordered

for (int i = 0; i < n; ++i) {
	cin >> aa[i].x;
	aa[i].p = i;
}

sort(aa, aa + n, [](const D &i, const D &j) {
	return i.x < j.x; // compare
});

a[aa[0].p] = 0;
for (int i = 1; i < n; ++i) {
	a[aa[i].p] = a[aa[i - 1].p];
	if (aa[i].x != aa[i - 1].x) // diff element
		a[aa[i].p]++;
}

