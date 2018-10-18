#include <cstdio>
#include <cstring>
#define LEFT 1
#define EMPTY 0
#define RIGHT 2
#define MOD 9901
int N;

int dp[100010][3];
int solution(int y,int state)
{
	if (y == 0) return 1;
	int &ret = dp[y][state];
	if (ret != -1) return ret;
	ret = 0;
	if (state == LEFT)
		ret += solution(y - 1, RIGHT);
	if (state == RIGHT)
		ret += solution(y - 1, LEFT);
	if (state == EMPTY)
		ret += solution(y - 1, LEFT) + solution(y - 1, RIGHT);
	ret += solution(y - 1, EMPTY);
	return ret%=MOD;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	printf("%d", (solution(N-1, EMPTY)+solution(N-1,LEFT)+solution(N-1,RIGHT))%MOD);
}