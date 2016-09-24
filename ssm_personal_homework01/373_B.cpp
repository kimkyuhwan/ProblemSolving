#include <cstdio>
#include <algorithm>
using namespace std;
int N;
int val[100010];
char temp;
int r[2], b[2];
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf(" %c", &temp);
		if (temp == 'r')
			val[i] = 0;
		else
			val[i] = 1;
	}
	int sol = 10000000;
	for (int i = 0; i < N; i++)//rbrbr
	{
		int pos = i % 2;
		if (val[i] != pos)
		{
			if (i % 2 == 0)
				r[0]++;
			else
				b[0]++;
		}
	}
	int sw = min(r[0], b[0]);
	sol = r[0] + b[0] - sw;
	for (int i = 0; i < N; i++)//rbrbr
	{
		int pos = i % 2;
		if (val[i] == pos)
		{
			if (i % 2 == 0)
				r[1]++;
			else
				b[1]++;
		}
	}
	sw = min(r[1], b[1]);
	sol = min(sol, r[1] + b[1] - sw);
	printf("%d", sol);
}