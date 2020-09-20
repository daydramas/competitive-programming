struct nCr {

	int n;
	vector<vector<int> > dp;

	nCr(int n_) {
		n = n_;
		dp.assign(n+1, vector<int> (n+1, -1));
		build();
	}

	void build() {
		for(int i=0; i<=n; i++) {
			dp[i][i] = dp[i][0] = 1;
		}
	}

	int get(int a, int b) {
		if (dp[a][b]!=-1) return dp[a][b];
		return (dp[a][b] = get(a-1, b-1)+get(a-1, b));
	}
};
