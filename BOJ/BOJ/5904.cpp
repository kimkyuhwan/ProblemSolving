#include <cstdio>
int N,i;
int dp[310];
int makeDP(int n)
{
	int &ret = dp[n];
	if (ret != 0) return ret;
	return ret=(n+2) + makeDP(n - 1) + makeDP(n - 1);
}
int solution(int pos)
{
	int P1 = dp[pos - 1];
	int P2 = P1 + pos + 2;
	if (N <= P1)
	{
		return solution(pos - 1);
	}
	else if (N <= P2)
	{
		if (N - P1 == 1) return 1;
		else return 0;
	}
	else
	{
		N -= P2;
		return solution(pos - 1);
	}
}
int main()
{
	dp[1] = 3;
	makeDP(28);
	scanf("%d", &N);
	for (i = 1; i <= 28 && dp[i] <= N; i++);
	int sol=solution(i);
	if (sol)
		puts("m");
	else
		puts("o");
}