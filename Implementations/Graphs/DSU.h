/**
 * DSU<3> dsu;
 * dsu.comb(0,1)
 * dsu.comb(1,2)
 * cout << dsu.get(2) << "\n"; // 0
 * cout << dsu.get(0) << "\n"; // 0
*/

template<int SZ> struct DSU {
    int sz[SZ], pa[SZ];

    DSU() {
        for(int i=0; i<SZ; i++)
            sz[i]=1, pa[i]=i;
    }

    int get(int a) { // find parent
        if(pa[a] == a) return a;
        return pa[a]=get(pa[a]);
    }

    bool comb(int a, int b) { // merge
        a=get(a), b=get(b);
        if (a==b) return false;
        if (sz[a] < sz[b]) swap(a,b);
        sz[a]+=sz[b]; pa[b]=a;
        return true;
    }

};