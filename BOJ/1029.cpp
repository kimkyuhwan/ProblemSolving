#include <cstdio>
#include <algorithm>
using namespace std;
int N,sol;
int cost[15][15];
int dp[15][1 << 15][10];
int solution(int pos, int state,int cur_cost)
{
	int &ret = dp[pos][state][cur_cost];
	if (ret != 0) return ret;
	ret = 1;
	for (int i = 0; i < N; i++)
	{
		if (cur_cost > cost[pos][i] || (state & (1 << i) )) continue;
		ret = max(ret, solution(i, state | (1 << i), cost[pos][i])+1);
	}
	return ret;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%1d", &cost[i][j]);
	int sol = solution(0, 1,0);
	printf("%d", sol);
}