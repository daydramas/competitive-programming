int ll[N], tt[N][M];

void init() {
	ll[0] = 1;
	for (int i = 1; i < N; ++i)
		ll[i] = ll[i / 2] + 1;
	for (int i = 0; i < n; i++)
    	tt[i][0] = aa[i];

	for (int j = 1; j <= K; j++)
		for (int i = 0; i + (1 << j) <= N; i++)
			tt[i][j] = min(tt[i][j-1], tt[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r) {
	int j = ll[r - l + 1];
	return min(tt[l][j], tt[r - (1 << j) + 1][j]);
}