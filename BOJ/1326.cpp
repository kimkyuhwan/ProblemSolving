#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
int jump[10010];
int dist[10010];
int N, a, b;
queue<int> q;
int main()
{
	memset(dist, -1, sizeof(dist));
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &jump[i]);
	scanf("%d %d", &a, &b);
	dist[a] = 0;
	q.push(a);
	while (!q.empty())
	{
		int here = q.front();
		int di = dist[here];
		int j = abs(jump[here]);
		q.pop();
		for (int i = here - j; i > 0; i -= j)
		{
			if (dist[i] != -1) continue;
			dist[i] = di + 1;
			q.push(i);
		}
		for (int i = here + j; i <= N; i += j)
		{
			if (dist[i] != -1) continue;
			dist[i] = di + 1;
			q.push(i);
		}
	}
	printf("%d\n", dist[N]);

}