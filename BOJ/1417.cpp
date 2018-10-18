#include <cstdio>
#include <algorithm>
using namespace std;
int N,sol;
int Vote[1010];

int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &Vote[i]);
	while (true)
	{
		int ds = Vote[0];
		bool isFInish = true;
		sort(Vote + 1, Vote + N);
		for (int i = N-1; i >=1; i--)
		{
			if (Vote[i] >= ds)
			{
				isFInish = false;
				Vote[0]++;
				Vote[i]--;
				break;
			}
		}
		if (isFInish)
			break;
		sol++;
	}
	printf("%d", sol);
}