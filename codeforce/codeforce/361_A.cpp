#include <cstdio>
int N;
int num[12];
int checked[10];
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%1d", &num[i]);
		checked[num[i]] = 1;
	}
	int sol = 0;
	if (checked[1] && checked[9])
		sol = 1;
	else if (checked[3] && checked[7])
		sol = 1;
	else if ((checked[1] || checked[2] || checked[3]) && checked[0])
		sol = 1;
	else if (checked[2] && (checked[7] || checked[4]) && checked[9])
		sol = 1;
	else if (checked[2] && checked[6] && checked[7])
		sol = 1;
	else if (checked[3] && checked[9] && checked[4])
		sol = 1;
	else if (checked[1] && checked[7] && checked[6])
		sol = 1;
	if (sol)
		puts("YES");
	else
		puts("NO");
}