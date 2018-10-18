#include <cstdio>
#include <algorithm>
using namespace std;
int N,sol,maxx;
int card[1010];
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &card[i]);
		sol += card[i];
		maxx = max(maxx, card[i]);
	}
	sol += (maxx*(N - 2));
	printf("%d", sol);
}