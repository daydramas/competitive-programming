// Dijkstra
#define pii pair<int, int>
#define INF 1000000000
int dist[100]; vector<pii> adj[100];
void dijkstra(int src) {
	fill(dist+2, dist+101, INF);
	queue<int> Q;
	dist[src] = 0; Q.push(src);
	while(!Q.empty()) {
		int f = Q.front(); Q.pop();
		for (pii d : adj[src]) if (dist[d.first] > dist[f]+d.second) {
				dist[d.first] = dist[f.first]+d.second;
				Q.push(d.first, dist[d.first]);
		}
	}
}

// Floyd Warshall
int dist[100][100];
void floydWarshall() {
	for (int k=1; k<=100; k++) 
	for (int i=1; i<=100; i++) 
	for (int j=1; j<=100; j++)
		dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
}

// Bellman Ford
#define INF 1000000000
struct node {
	int to, from, weight;
	node(int to, int from, int weight) : to(to), from(from), weight(weight) {}
}
int dist[100];
vector<node> adj;
void bellmanFord(int src) {
	for (int i = 1; i <= N; i++) dist[i] = INF;
	dist[src] = 0;
	for (int i = 1; i < N; i++) for (node j : adj) 
		if (dist[j.to] > dist[j.from] + j.weight) 
			dist[j.to] = dist[j.from] + j.weight;
	
}