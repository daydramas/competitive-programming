int dd[N];
// memset(dd, -1, sizeof(dd));

int get(int x) { return dd[x] < 0 ? x : dd[x] = get(dd[x]); }
void merge(int x, int y) { x = get(x), y = get(y); if (x != y) dd[x] += dd[y], dd[y] = x; }