#include "DSU.h"

template<int SZ> struct MST {
    using Edge = pair<int, pair<int, int> >;
    DSU<SZ> dsu;
    vector<Edge> edges;

    void ae(int a, int b, int c) {
        edges.pb({c, {a, b}});
    }
    ll calc(int n) {
        ll res=0;
        sort(all(edges));
        trav(E, edges) {
            if (dsu.comb(E.s.f, E.s.s)) res += E.f;
        }
        return res;
    }
};