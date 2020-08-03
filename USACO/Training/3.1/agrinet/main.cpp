/*
 ID: dongliu3
 TASK: agrinet
 LANG: C++
 */

#include <bits/stdc++.h>

using namespace std;

// structures/defines
#define INF 1000000000

// global variables
int N;
int d[105][105];
int dist[105];

// functions

int main() {
	// local variables

	// fstream
	ifstream fin("agrinet.in");
	ofstream fout("agrinet.out");

	// input
	fin >> N;
	for (int i=1; i<=N; i++)
	for (int j=1; j<=N; j++)
		fin >> d[i][j];
	// main
	for (int k=1; k<=N; k++)
	for (int i=1; i<=N; i++)
	for (int j=1; j<=N; j++)
		d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

	fill(dist, dist+N+1, INF);

	int src = 1, ans = 0;
	for (int i=1; i<N; i++) {
		dist[src] = -1;
		for (int j=1; j<=N; j++)
			dist[j] = min(dist[j], d[src][j]);
		int ns = -1, nc = INF;
		for (int j=1; j<=N; j++)
			if (dist[j] != -1 && dist[j] < nc)
				ns = j, nc = dist[j];
		src = ns;
		ans += nc;

	}
	// output
	fout << ans << endl;
	return 0;
}