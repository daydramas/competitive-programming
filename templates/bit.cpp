const int BIT = (1<<18);
int bb[BIT];

int sum(int pos) {
	int res = 0;
	while(pos > 0) {
		res += bb[pos];
		pos -= pos & (-pos);
	}
	return res;
}
void query(int lo, int hi) {
	return sum(hi) - sum(lo-1);
}
void add(int pos, int inc) {
	while(pos < BIT) {
		bb[pos] += inc;
		pos += pos & (-pos);
	}
}
void update(int pos, int val) {
	add(pos, val - query(pos, pos));
}