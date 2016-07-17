#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int> > adj;
vector<int> dist;
int N, M;
int main()
{
	scanf("%d", &N);
	dist.resize(N + 1);
	adj.resize(N + 1);
	priority_queue<pair<int, int> > q;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &M);
		dist[i] = i - 1;
		q.push(make_pair(-dist[i], i));
		if (i == M) continue;
		adj[i].push_back(M);
	}
	while (!q.empty())
	{
		int d = -q.top().first, here = q.top().second;
		q.pop();
		if (here<N && dist[here + 1]>d + 1)
		{
			dist[here + 1] = d + 1;
			q.push(make_pair(-dist[here + 1], here + 1));
		}
		if (here > 1 && dist[here - 1] > d + 1)
		{
			dist[here - 1] = d + 1;
			q.push(make_pair(-dist[here - 1], here - 1));
		}
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i];
			if (dist[there] > d + 1)
			{
				dist[there] = d + 1;
				q.push(make_pair(-dist[there], there));
			}
		}
	}
	for (int i = 1; i <= N; i++)
		printf("%d ", dist[i]);
}