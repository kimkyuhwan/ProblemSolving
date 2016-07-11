#include <cstdio>
typedef long long ll;
#define MAXX(a,b) (a>b) ? a : b
int N, K;
int cost[100010];
ll sol,sum;
int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &cost[i]);
		if (i < K)
			sum += cost[i];
	}
	sol = sum;
	for (int i = K; i < N; i++)
	{
		sum += cost[i];
		sum -= cost[i - K];
		sol = MAXX(sol, sum);
	}
	printf("%lld", sol);
}