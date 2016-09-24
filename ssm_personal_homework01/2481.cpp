#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
using namespace std;
int N, K,M,u,val;
map<int,int> s;
map<int, int>::iterator it;
vector<vector<int> > adj;
vector<int> parent;
stack<int> st;
char temp;
void solution(int start)
{
	queue<int> q;
	q.push(start);
	parent[start] = 0;
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i];
			if (parent[there] != -1) continue;
			parent[there] = here;
			q.push(there);
		}
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &K);
	adj.resize(N + 1);
	parent.resize(N + 1, -1);
	for (int i = 1; i <= N; i++)
	{
		val = 0;
		for (int j = K - 1; j >= 0; j--)
		{
			scanf(" %c", &temp);
			if(temp=='1')
				val += (1 << j);
		}
		s[val] = i;
	}
	for (it=s.begin(); it!=s.end(); it++)
	{
		int here = it->second;
		for (int j = 0; j < K; j++)
		{
			val = it->first;
			val ^= (1 << j);
			if (s.count(val))
			{
				int there = s[val];
				adj[here].push_back(there);
			}
		}
	}
	solution(1);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &u);
		for (int here = u; parent[here] != -1; here = parent[here])
			st.push(here);
		if (st.empty())
			puts("-1");
		else
		{
			while (!st.empty())
			{
				printf("%d ", st.top());
				st.pop();
			}
			puts("");
		}
	}
}