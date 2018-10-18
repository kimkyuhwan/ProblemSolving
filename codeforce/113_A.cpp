#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, k,sol;
pair<int, int> temp;
int main()
{
	scanf("%d %d", &n, &k);
	vector<pair<int, int> > team(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &team[i].first, &team[i].second);
		team[i].first = -team[i].first;
	}
	sort(team.begin(), team.end());
	temp = team[k - 1];
	for (int i = 0; i < n; i++)
		if (team[i] == temp)
			sol++;
	printf("%d", sol);
}