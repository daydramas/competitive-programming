struct L {
	int x;
	struct L *next;
};
struct L *gg[N];

void link(int i, int j) {
	struct L *l = new L();
	l->x = j;
	l->next = gg[i];
	gg[i] = l;
};