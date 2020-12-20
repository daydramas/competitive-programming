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