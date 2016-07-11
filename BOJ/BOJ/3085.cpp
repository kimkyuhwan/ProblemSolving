#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
vector<vector<char> > candy;
int N,sol;
int dy[2] = { 1.0 };
int dx[2] = { 0,1 };
int getMax(vector < vector<char> > &a)
{
	int ret = 0;
	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		char cur = 0;
		for (int j = 1; j <= N; j++)
		{
			if (cur == a[i][j])
				cnt++;
			else
			{
				cnt = 1;
				cur = a[i][j];
			}
			ret = max(cnt, ret);
		}
	}
	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		char cur = 0;
		for (int j = 1; j <= N; j++)
		{
			if (cur == a[j][i])
				cnt++;
			else
			{
				cnt = 1;
				cur = a[j][i];
			}
			ret = max(cnt, ret);
		}
	}
	return ret;
}
int solution(int y, int x)
{
	vector<vector<char> > temp=candy;
	int ret = 0;
	for (int i = 0; i < 2; i++)
	{
		int nextY = y + dy[i], nextX = x + dx[i];
		temp = candy;
		if (candy[nextY][nextX] == 0) continue;
		swap(temp[y][x], temp[nextY][nextX]);
		ret = max(ret, getMax(temp));
		swap(temp[y][x], temp[nextY][nextX]);
	}
	return ret;
}

int main()
{
	scanf("%d", &N);
	candy.resize(N+2, vector<char>(N+2));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf(" %c", &candy[i][j]);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			sol = max(sol, solution(i, j));
	printf("%d", sol);
}