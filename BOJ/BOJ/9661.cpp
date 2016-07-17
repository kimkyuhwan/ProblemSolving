#include <cstdio>
#include <cstring>
typedef long long ll;
ll dp[13][2016];
int T,N,K;

ll solution(int cnt, int pos)
{
	if (cnt == 1) 
		return 1;
	ll &ret = dp[cnt][pos];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = pos / 2; i >= 1; i--)
		ret += solution(cnt - 1, i);
	return ret;
}
int main()
{
	scanf("%d", &T);
	memset(dp, -1, sizeof(dp));
	while (T--)
	{
		scanf("%d %d", &N, &K);
		ll sol = 0;
		for (int i = K; i >= 1; i--)
			sol += solution(N, i);
		printf("%lld\n", sol);
	}
}