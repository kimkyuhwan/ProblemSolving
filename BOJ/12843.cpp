#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int a,b,cnt;
char c;
vector<int> lec;
vector<vector<int> > adj;
vector<int> visited;
int dp[2010][2];

int dfs(int pos, int sel)
{
	int &ret = dp[pos][sel];
	if (ret != -1) return ret;
	ret = sel;
	for (int i = 0; i < adj[pos].size(); i++)
	{
		int there = adj[pos][i];
		if (lec[there] == lec[pos]) continue;
		if (sel == 0)
			ret += dfs(there, 1);
		else
			ret += min(dfs(there, 1), dfs(there, 0));
	}
	return ret;

}
int main()
{
	freopen("input.txt", "r", stdin);
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &m);
	lec.resize(n + 1);
	adj.resize(n + 1);
	for (int i = 0; i < n; i++)
	{
		scanf(" %d %c", &a, &c);
		if (c == 'c') lec[a] = 0;
		else lec[a] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int sol = 0;
	for (int i = 1; i <= n;i++)
	{
		if (dp[i][1] == -1)
			sol += min(dfs(i, 1), dfs(i, 0));
	}
	printf("%d", n-sol);
}