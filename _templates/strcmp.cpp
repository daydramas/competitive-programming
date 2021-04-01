bool compare(char *a, char *b) {
	int n = strlen(a), m = strlen(b);
	for (int i = 0; i < min(n, m); ++i)
		if (a[i] < b[i]) return 1;
		else if (a[i] > b[i]) return 0;
	return n < m;
}