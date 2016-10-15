#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
#define mp(x,y) make_pair(x,y)
#define MOD 1000000007
int D;
pair<int, int> E[12] = { mp(0,1),mp(0,2),mp(1,2),mp(1,3),mp(2,3),mp(2,5),mp(3,5),mp(3,4),mp(4,5),mp(5,7),mp(4,6),mp(6,7) };
vector<int> adj[8];
int dp[8][2];
int main()
{
	scanf("%d", &D);
	for (int i = 0; i < 12; i++)
	{
		int u = E[i].first;
		int v = E[i].second;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dp[0][1] = 1;
	for (int i = 1; i <= D; i++)
	{
		for (int k = 0; k < 8; k++)
		{
			dp[k][0] = dp[k][1];
			dp[k][1] = 0;
		}
		for (int here = 0; here < 8; here++)
		{
			for (int j = 0; j < adj[here].size(); j++)
			{
				int there = adj[here][j];
				dp[there][1] = (dp[there][1]+dp[here][0])%MOD;
			}
		}
	}
	printf("%d", dp[0][1]);
}