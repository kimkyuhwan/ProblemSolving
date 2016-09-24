#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
pair<int, int> arr[1000010];
int val[1000010],N;
int minn[2000010];
int maxx[2000010];
int main()
{
	for (int i = 1; i <= 2000000; i++)
		minn[i] = 20000000;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d %d", &arr[i].second, &arr[i].first);
	sort(arr+1, arr + N+1);
	val[0] = 1000000;
	minn[1000000] = 0;
	for (int i = 1; i <= N; i++)
	{
		val[i] = val[i - 1];
		if (arr[i].second == 0) val[i]--;
		else val[i]++;
		int here = val[i];
		minn[here] = min(minn[here], i);
		maxx[here] = max(minn[here], i);
	}
	int sol = 0;
	for (int i = 0; i <= 2000000; i++)
	{
		int a = minn[i]+1;
		int b = maxx[i];
		if (a >= b) continue;
		sol = max(sol, arr[b].first - arr[a].first);
	}
	printf("%d", sol);
}