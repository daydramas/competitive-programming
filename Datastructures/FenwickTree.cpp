struct BIT {

	int n;
	vector<int> t;

	BIT(int n_) {
		n = n_;
		t.assign(n+1, 0);
	}

	void update(int i, int value) {
		for (; i<=n; i+=i&(-i)) t[i] += value;
	}

	int get(int i) {
		int sum = 0;
		for(; i>0; i-=i&(-i)) sum += t[i];
		return sum;
	}

};
