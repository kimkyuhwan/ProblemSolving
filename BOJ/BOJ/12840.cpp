#include <cstdio>
#include <vector>
using namespace std;
int T, N;
int col[1010][1010];
int a[1010], b[1010];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		int sol = 0;
		scanf("%d", &N);
		sol = (N*(N - 1)*(N - 2)) / 6;
		for (int i = 0; i < N-1; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				scanf("%d", &col[i][j]);
				col[j][i] = col[i][j];
				if (col[i][j])
					a[i]++, a[j]++;
				else
					b[i]++, b[j]++;
			}
		}
		int sum = 0;
		for (int i = 0; i < N; i++)
			sum += (a[i] * b[i]);
		sum /= 2;
		printf("%d\n", sol-sum);
	}

}