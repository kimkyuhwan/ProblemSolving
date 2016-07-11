#include <cstdio>
int N, K,sol;
int arr[11];
int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	for (int i = N - 1; i >= 0; i--)
	{
		while (arr[i] <= K)
		{
			K -= arr[i];
			sol++;
		}
	}
	printf("%d", sol);
}