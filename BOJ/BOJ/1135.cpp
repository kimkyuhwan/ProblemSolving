#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N,P;
vector< vector<int> > adj;
int solution(int pos)
{
	int ret = 0;
	vector<int> child;
	for (int i = 0; i < adj[pos].size(); i++)
	{
		int there = adj[pos][i];
		child.push_back(solution(there));
	}
	sort(child.rbegin(), child.rend());
	for (int i = 0; i < child.size(); i++)
		ret = max(ret, child[i] + i + 1);
	return ret;
}
int main()
{
	scanf("%d", &N);
	adj.resize(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &P);
		if (P == -1) continue;
		adj[P].push_back(i);
	}
	int sol = solution(0);
	printf("%d", sol);
}