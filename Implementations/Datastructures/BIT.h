struct BIT {

	int n; vi t;

	BIT(int n_) { n = n_; t.assign(n+1, 0); }

	void upd(int i, int value) {
		for (; i<=n; i+=i&(-i)) t[i] += value;
	}

	int qry(int i) {
		int sum = 0;
		for(; i>0; i-=i&(-i)) sum += t[i];
		return sum;
	}

};
