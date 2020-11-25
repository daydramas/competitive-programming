/**
 * Dijkstra<3> d;
 * d.edge(1, 2, 5);
 * d.edge(1, 3, 10);
 * d.edge(2, 3, 3);
 * d.solve(1);
 * cout << d.dist[1] << "\n"; // 0
 * cout << d.dist[2] << "\n"; // 5
 * cout << d.dist[3] << "\n"; // 8
*/

template<int SZ> struct Dijkstra {
    using Node = pair<long long, int>;

    vector<Node> adj[SZ];
    long long dist[SZ];

    Dijkstra() {}
    void edge(int i, int j, long long weight) {
        adj[i].pb({weight, j});
        adj[j].pb({weight, i});
    }
    void calc(int src) {
        for(int i=0; i<SZ; i++) dist[i]=1e18;

        priority_queue<Node, vector<Node>, greater<Node> > PQ;
        PQ.push({dist[src]=0,src});
        while(!PQ.empty()) {
            Node F = PQ.top(); PQ.pop();
            if (F.f > dist[F.s]) continue;
            for(auto &e : adj[F.s]) {
                if (dist[F.s]+e.f < dist[e.s])
                    PQ.push({dist[e.s]=dist[F.s]+e.f, e.s});
            }
        }

    }
};