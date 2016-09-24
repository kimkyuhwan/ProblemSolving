#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int N, M, sy, sx, cnt = 1;
char miro[52][52];
int vec[52][52];
int parent[310];
int visited[52][52];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
queue<pair<int, int> > kq;
vector<pair<int, pair<int, int> > > adj;
int find(int pos)
{
	if (pos == parent[pos]) return pos;
	return parent[pos] = find(parent[pos]);
}
bool isPossible(int y, int x)
{
	return y >= 0 && y < N && x >= 0 && x < N;
}
void bfs(int sy, int sx, int A)
{
	memset(visited, -1, sizeof(visited));
	queue<pair<int, int> > q;
	q.push(make_pair(sy, sx));
	visited[sy][sx] = 0;
	while (!q.empty())
	{
		int hereY = q.front().first;
		int hereX = q.front().second;
		int hereW = visited[hereY][hereX];
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nY = hereY + dy[i];
			int nX = hereX + dx[i];
			if (isPossible(nY, nX) && visited[nY][nX] == -1 && miro[nY][nX] != '1')
			{
				visited[nY][nX] = hereW + 1;
				q.push(make_pair(nY, nX));
				if (miro[nY][nX] == 'K')
					adj.push_back(make_pair(hereW + 1, make_pair(A, vec[nY][nX])));
			}
		}
	}
}
int solution()
{
	int sol = 0;
	while (!kq.empty())
	{
		int y = kq.front().first;
		int x = kq.front().second;
		kq.pop();
		bfs(y, x, vec[y][x]);
	}
	sort(adj.begin(), adj.end());
	for (int i = 0; i < cnt; i++)
		parent[i] = i;
	for (int i = 0; i < adj.size(); i++)
	{
		int u = adj[i].second.first;
		int v = adj[i].second.second;
		int d = adj[i].first;
		u = find(u);
		v = find(v);
		if (u == v) continue;
		if (u < v) swap(u, v);
		parent[u] = v;
		sol += d;
	}
	for (int i = 0; i < cnt; i++)
		if (parent[i] != 0)
			return -1;
	return sol;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			scanf(" %c", &miro[i][j]);
			if (miro[i][j] == 'S')
			{
				sy = i, sx = j;
				kq.push(make_pair(i, j));
			}
			else if (miro[i][j] == 'K')
			{
				vec[i][j] = cnt++;
				kq.push(make_pair(i, j));
			}
		}
	printf("%d", solution());
}