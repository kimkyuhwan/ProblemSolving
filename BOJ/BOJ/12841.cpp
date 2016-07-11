#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll sol=987654321234567;
int n,idx;
ll road[100010];
ll left[100010], right[100010];
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &road[i]);
	for (int i = 2; i <= n; i++)
		scanf("%d", &left[i]);
	for (int i = 1; i < n; i++)
		scanf("%d", &right[i]);
	for (int i = 2; i <= n; i++)
		left[i] += left[i - 1];
	for (int i = n - 1; i >= 1; i--)
		right[i] += right[i + 1];
	for (int i = 1; i <= n; i++)
	{
		ll dist = road[i] + left[i] + right[i];
		if (dist < sol)
		{
			sol = dist;
			idx = i;
		}
	}
	printf("%d %lld",idx, sol);
}