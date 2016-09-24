#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N, M,A,B,cost,sol;
int parent[1010];
vector<pair<int, pair<int, int> >  > adj;
vector<pair<int,int> > vec;
int find(int pos)
{
	if (parent[pos] == pos) return pos;
	return parent[pos] = find(parent[pos]);
}
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 2; i <= N; i++)
		parent[i] = i;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &A, &B);
		int u = find(A);
		int v = find(B);
		if (u == v) continue;
		parent[u] = v;
	}
	for(int i=1;i<=N;i++)
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &cost);
			adj.push_back(make_pair(cost, make_pair(i, j)));
		}
	sort(adj.begin(), adj.end());
	for (int i = 0; i < adj.size(); i++)
	{
		cost = adj[i].first;
		int u = adj[i].second.first;
		int v = adj[i].second.second;
		if (u == 1 || v == 1) continue;
		int pu = find(u);
		int pv = find(v);
		if (pu == pv)continue;
		sol += cost;
		parent[pv] = pu;
		vec.push_back(make_pair(u, v));
	}
	printf("%d %d\n", sol, vec.size());
	for (int i = 0; i < vec.size(); i++)
		printf("%d %d\n", vec[i].first, vec[i].second);
}