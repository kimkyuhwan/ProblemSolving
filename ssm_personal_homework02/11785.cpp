#include <cstdio>
#include <algorithm>
using namespace std;
int T, N, L;
int arr[110];
int main()
{
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		scanf("%d %d", &N, &L);
		for (int j = 0; j < N; j++)
			scanf("%d", &arr[j]);
		sort(arr, arr + N);
		int lasttime = 0;
		int cnt = 0;
		int totaltime = 0;
		int psum = 0;
		for (int j = 0; j < N; j++) {
			if (L - arr[j] >= 0)
			{
				cnt++;
				psum += arr[j];
				totaltime += psum;
				lasttime += arr[j];
				L -= arr[j];
			}
			else
				break;


		}
		printf("Case %d: %d %d %d\n", i, cnt, lasttime, totaltime);

	}



}