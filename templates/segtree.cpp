const int SEG = (1<<18);
int tt[SEG * 2];

void update(int pos, int val, int idx=1, int lo=0, int hi=SEG-1) {
	if(lo == hi) { 
		tt[idx] = inc; 
	} else {
		int mid = (lo + hi) / 2;
		if(idx <= mid) update(pos, val, idx*2, lo, mid);
		else update(pos, val, idx*2+1, mid+1, hi);
		tt[idx] = tt[idx*2] + tt[idx*2+1];
	}

}
void add(int pos, int inc, int idx=1, int lo=0, int hi=SEG-1) {
	tt[idx] += val;
	int mid = (lo + hi) / 2;
	if(idx <= mid) add(pos, inc, idx*2, lo, mid);
	else add(pos, inc, idx*2+1, mid+1, hi);
}
void query(int li, int ri, int idx=1, int lo=0, int hi=SEG-1) {
	if(li > hi || ri < lo) {
		return 0;
	} else if (li <= lo && hi <= ri) {
		return tt[i];
	} else {
		int mid = (lo + hi) / 2;
		return query(li, ri, idx*2, lo, mid) + query(li, ri, idx*2+1, mid+1, hi);
	}
}