#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int T, n, k, t, m;
int id, prnum, s,sol;
vector<vector<int> > pr;
vector<int> last,submit,score;
vector<pair<pair<int, int>, pair<int, int> > > tot;
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d %d %d", &n, &k, &t, &m);
		pr = vector<vector<int> >(n + 1, vector<int> (k + 1));
		score=submit=last = vector<int>(n+1);
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d %d", &id, &prnum, &s);
			int &temp = pr[id][prnum];
			if (temp < s)
			{
				score[id] += s - temp;
				temp = s;
			}
			last[id] = i;
			submit[id]++;
		}
		for (int i = 1; i <= n; i++)
			tot.push_back(make_pair(make_pair(-score[i], submit[i]), make_pair(last[i], i)));
		sort(tot.begin(), tot.end());
		for (int i = 0; i < n; i++)
		{
			if (tot[i].second.second == t)
			{
				printf("%d\n", i + 1);
				break;
			}
		}
		tot.clear();
	}
}