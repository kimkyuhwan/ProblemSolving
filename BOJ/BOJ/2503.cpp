#include <cstdio>
#include <algorithm>
using namespace std;
int N,num,s,b,sol;
pair<int, pair<int, int> > sb[110];
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", &num, &s, &b);
		sb[i] = make_pair(num,make_pair(s, b));
	}
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (i == j) continue;
			for (int k = 1; k <= 9; k++)
			{
				if (i == k || j == k) continue;
				bool isPossible = true;
				for (int a = 0; a < N && isPossible; a++)
				{
					int n = sb[a].first;
					int S = 0, B = 0;
					if (n % 10 == k)
						S++;
					else if (n % 10 == i || n % 10 == j)
						B++;
					n /= 10;
					if (n % 10 == j)
						S++;
					else if (n % 10 == i || n % 10 == k)
						B++;
					n /= 10;
					if (n % 10 == i)
						S++;
					else if (n % 10 == k || n % 10 == j)
						B++;
					if (S != sb[a].second.first || B != sb[a].second.second)
						isPossible = false;
				}
				if (isPossible)
					sol++;
			}
		}
	}
	printf("%d", sol);
}