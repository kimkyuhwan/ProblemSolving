#include <cstdio>
using namespace std;
#define mod 1000000007
typedef long long ll;
ll a, b;
ll A[128][2][2] = {};
void zegop()
{
	for (int N = 0; N < 127; N++)
	{
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
					A[N + 1][i][j] += A[N][i][k] * A[N][k][j];
				A[N + 1][i][j] %= mod;
			}
	}
}
int main()
{
	A[0][1][0] = A[0][0][1] = A[0][0][0] = 1;
	zegop();
	scanf("%lld", &b);
	if(b%2==1)
		b -= 1;
	ll fibo[2] = { 1, 0 }, cnt = 0;
	while (b)
	{
		if (b % 2)
		{
			ll temp[2];
			temp[0] = (fibo[0] * A[cnt][0][0]) + (fibo[1] * A[cnt][0][1]);
			temp[1] = (fibo[0] * A[cnt][1][0]) + (fibo[1] * A[cnt][1][1]);
			fibo[0] = temp[0] % mod;
			fibo[1] = temp[1] % mod;
		}
		cnt++, b >>= 1;
	}
	printf("%lld", fibo[0]-1);
}