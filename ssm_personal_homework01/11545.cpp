#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define PPP 100
int D, P, R, B,u,v;
int cost[210];
int visited[210];
vector<vector<int> > adj;
vector<pair<int, int> > vA,vB;
int dp[210][10010];
pair<int,int> dfs(int pos)
{
	visited[pos] = 1;
	pair<int, int> ret; 
	ret.first=cost[pos];
	if (pos >= PPP)
		ret.second = 1;
	else
		ret.second = -1;
	for (int i = 0; i < adj[pos].size(); i++)
	{
		int there = adj[pos][i];
		if (visited[there]) continue;
		pair<int, int> temp = dfs(there);
		ret.first += temp.first;
		ret.second += temp.second;
	}
	return ret;
}
int solutionA(int pos, int cost)
{
	if (pos==vA.size()) return 0;
	int &ret = dp[pos][cost];
	if (ret != -1) return ret;
	ret = solutionA(pos + 1, cost);
	if(cost-vA[pos].first>=0)
		ret = max(ret, solutionA(pos + 1, cost - vA[pos].first) + vA[pos].second);
	return ret;
}
int solutionB(int pos, int cost)
{
	if (cost <= 0 || pos == vB.size()) return 0;
	int &ret = dp[pos][cost];
	if (ret != -1) return ret;
	ret = solutionB(pos + 1, cost);
	if (cost - vB[pos].first >= 0)
		ret = max(ret, solutionB(pos + 1, cost - vB[pos].first) + vB[pos].second);
	return ret;
}
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d %d", &D, &P, &R, &B);
	adj.resize(PPP + P+1);
	for (int i = 0; i < D; i++)
	{
		scanf("%d", &cost[i]);
	}
	for (int i = 0; i < P; i++)
		scanf("%d", &cost[i + PPP]);
	for (int i = 0; i < R; i++)
	{
		scanf("%d %d", &u, &v);
		u--, v--;
		v += PPP;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < D; i++)
	{
		if (visited[i]) continue;
		pair<int, int> d = dfs(i);
		if (d.second > 0)
			vA.push_back(d);
		else if (d.second < 0)
		{
			d.second = -d.second;
			vB.push_back(d);
		}
	}
	for (int i = 0; i < P; i++)
	{
		int here = i + PPP;
		if (visited[here]) continue;
		pair<int, int> d = dfs(here);
		if (d.second > 0)
			vA.push_back(d);
		else if (d.second < 0)
		{
			d.second = -d.second;
			vB.push_back(d);
		}
	}
	int sol = 0;
	memset(dp, -1, sizeof(dp));
	sol=max(sol,solutionA(0, B));
	printf("%d ", D + sol);

	memset(dp, -1, sizeof(dp));
	sol = 0;
	sol = max(sol, solutionB(0, B));
	printf("%d ", P + sol);
}