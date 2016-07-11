#include <cstdio>
#include <limits.h>
#include <vector>
using namespace std;
#define INF 98765432123432
typedef long long ll;
int t[100010];
int n, s, m, rest;
vector<int> sol;
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &s);
	rest = n - s;
	scanf("%d", &m);
	if (rest < m)
	{
		printf("%d", rest);
		return 0;
	}
	rest -= m;
	for (int i = 0; i < m; i++)
		scanf("%d", &t[i]);
	ll L = 0, R = INF;
	ll eat = 0;
	while (L < R)
	{
		ll mid = (L + R) >> 1;
		eat = 0;
		for (int i = 0; i < m; i++)
			eat += mid / t[i];
		if (eat < rest)
			L = mid + 1;
		else
			R = mid;
	}
	for (int i = 0; i < m; i++)
	{
		if (L % t[i] == 0)
		{
			sol.push_back(i);
		}
	}
	eat = 0;
	for (int i = 0; i < m; i++)
		eat += L / t[i];
	int A = sol.size() - 1;
	for (int i = 0; i < eat - rest; i++)
		A--;
	printf("%d", sol[A] + 1);
}