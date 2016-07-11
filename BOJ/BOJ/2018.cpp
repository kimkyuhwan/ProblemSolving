#include <cstdio>
int N,f=1,b;
int sum,sol;
int main()
{
	scanf("%d", &N);
	for (b = 1; sum < N; b++)
		sum += b;
	while (true)
	{
		if (sum == N)
		{
			sol++;
			sum += b++;
		}
		else if (sum > N)
			sum -= f++;
		else
			sum += b++;
		if (f >= b) break;
	}
	printf("%d", sol);
}