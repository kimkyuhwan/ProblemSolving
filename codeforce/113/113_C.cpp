#include <cstdio>
#include <algorithm>
using namespace std;
int N, K,sol;
int arr[510];
int l,s, r;
int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] == K)
			s++;
		else if (arr[i] < K)
			l++;
		else
			r++;
	}
	if (s == 0)
	{
		sol = 1;
		if (l > r)
			sol += (l - r);
		else if (r > l)
			sol += (r - l) - 1;
	}
	else
	{
		sol = 0;
		if (l > r)
		{
			int temp = l - r;
			temp = max(-1, temp - s);
			sol = temp + 1;
		}
		else if (r > l)
		{
			int temp = r - l;
			temp = max(0, temp - s);
			sol = temp;
		}
	}
	printf("%d", sol);
}