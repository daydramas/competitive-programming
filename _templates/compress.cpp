// coordinate compression

struct D {
	int x; // the value
	int p; // position
} aa[N];

int b[N]; // new, reordered

for (int i = 0; i < n; ++i) {
	cin >> aa[i].x;
	aa[i].p = i;
}

sort(p, p + n, [](int i, int j) {
	return aa[i].x < aa[j].x; // compare
});

b[aa[0].p] = 0;
for (int i = 1; i < n; ++i) {
	b[aa[i].p] = b[aa[i - 1].p];
	if (aa[i].x != aa[i - 1].x) // diff element
		b[aa[i].p]++;
}

