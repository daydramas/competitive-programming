struct L {
	int x;
	L *next;
} *gg[N];

void link(int i, int j) {
	L *l = new L();
	l->x = j;
	l->next = gg[i];
	gg[i] = l;
};