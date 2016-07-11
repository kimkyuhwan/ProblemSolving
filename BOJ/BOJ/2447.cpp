#include<cstdio>
#include<cstring>

char s[2500][2500];
int n;
void dfs(int depth, int h, int w)
{
	if (depth == 1)
	{
		s[h][w] = '*';
		return;
	}
	int next = depth / 3;

	for (int i = 0, y = h; i < 3; i++, y += next)
	{
		for (int j = 0, x = w; j < 3; j++, x += next)
		{
			if (i == 1 && j == 1) continue;
			dfs(depth / 3, y, x);
		}
	}
}
int main()
{
	memset(s, ' ', sizeof(s));
	scanf("%d", &n);
	dfs(n, 1, 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) printf("%c", s[i][j]);
		printf("\n");
	}
}