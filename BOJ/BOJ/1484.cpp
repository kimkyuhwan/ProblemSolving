#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
int cnt, G;
ll sum;
int main()
{
	scanf("%d", &G);
	for (int i = sqrt(G) + 1; i <G; i++)
	{
		sum = i*i - G;
		double A = sqrt(sum);
		int a = A;
		if (a == A)
		{
			printf("%d\n", i);
			cnt++;
		}
	}
	if (cnt == 0)
		puts("-1");
}