#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int C, N;
int dp[110][110], val[110][110];
int solution(int y, int x)
{
	if (y == N) return 0;
	int &ret = dp[y][x];
	if (ret != -1) return ret;
	ret = val[y][x];
	ret += max(solution(y + 1, x), solution(y + 1, x + 1));
	return ret;
}
int main()
{
	scanf("%d", &C);
	while (C--)
	{
		memset(dp, -1, sizeof(dp));
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			for (int j = 0; j <= i; j++)
				scanf("%d", &val[i][j]);
		printf("%d\n", solution(0, 0));
	}
}