#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
ll N;
int M,L,R;
pair<int, int> child[500010];
ll LR[500010];
int ind[500010];
char temp;
ll sol[500010];
void dfs(int pos,ll val)
{
	sol[pos] += val;
	if (ind[pos] > 1)
	{
		ind[pos]--;
		return;
	}
	if (sol[pos] % 2 == 0)
	{

		if (child[pos].first != 0)
		{
			dfs(child[pos].first, sol[pos]/2);
		}
		if (child[pos].second != 0)
			dfs(child[pos].second, sol[pos] / 2);
	}
	else if(LR[pos]==0)//Left
	{
		if (child[pos].first != 0)
			dfs(child[pos].first, sol[pos] / 2 +1);
		if (child[pos].second != 0)
			dfs(child[pos].second, sol[pos] / 2);
	}
	else if (LR[pos] == 1)//Right
	{
		if (child[pos].second != 0)
			dfs(child[pos].second, sol[pos] / 2 + 1);
		if (child[pos].first != 0)
			dfs(child[pos].first, sol[pos] / 2);
	}
}


int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%lld %d", &N, &M);
	for (int i = 1; i <= M; i++)
	{
		char str[3];
		scanf("%s %d %d", str, &L, &R);
		if (str[0] == 'L')
			LR[i] = 0;
		else
			LR[i] = 1;
		child[i].first = L;
		child[i].second = R;
		ind[L]++;
		ind[R]++;
	}
	queue<int> q;
	sol[1] = N;
	for (int i = 1; i <= M; i++)
		if (ind[i] == 0)
			q.push(i);
	//q.push(1);
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		L = child[here].first;
		R = child[here].second;
		if (sol[here] % 2 == 0)
		{

			if (L != 0)
			{
				sol[L] += sol[here] / 2;
				ind[L]--;
				if (ind[L] == 0) q.push(L);
			}
			if (R != 0)
			{
				sol[R] += sol[here] / 2;
				ind[R]--;
				if (ind[R] == 0) q.push(R);
			}
		}
		else if (LR[here] == 0)//Left
		{
			if (L != 0)
			{
				sol[L] += sol[here] / 2 + 1;
				ind[L]--;
				if (ind[L] == 0) q.push(L);
			}
			if (R != 0)
			{
				sol[R] += sol[here] / 2;
				ind[R]--;
				if (ind[R] == 0) q.push(R);
			}
		}
		else if (LR[here] == 1)//Right
		{
			if (L != 0)
			{
				sol[L] += sol[here] / 2;
				ind[L]--;
				if (ind[L] == 0) q.push(L);
			}
			if (R != 0)
			{
				sol[R] += sol[here] / 2 + 1;
				ind[R]--;
				if (ind[R] == 0) q.push(R);
			}
		}
	}
	for (int i = 1; i <= M; i++)
	{
		ll ans = LR[i]+sol[i];
		if (ans % 2 == 0)
			printf("L");
		else
			printf("R");
	}
}