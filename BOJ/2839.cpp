#include <cstdio>
typedef long long ll;
int r[5] = { 0,2,4,1,3 };
int cost[5] = { 0,6,12,3,9 };
ll N,sol;
int main()
{
	scanf("%lld", &N);
	sol += r[N % 5];
	N -= cost[N % 5];
	if (N < 0) sol = -1;
	else sol += N / 5;
	printf("%lld", sol);
}