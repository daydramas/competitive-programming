struct uf { 
    vector<int> pa;
    uf(int n) {
        pa = vector<int>(n+10, -1);
    }
    int find(int i) {
        if (pa[i] == -1) return i;
        return pa[i]=find(pa[i]);
    } 
    void merge(int x, int y) {
        int x2=find(x), y2=find(y);
        if (x2!=y2) {
            pa[x2]=y2, pa[x]=y2, pa[y]=y2;
        }
    }
};
