#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll a, b, l;
vector<int> A, B, L, P;
bool isNotPrime[1000010];
int main() {
	for (int i = 2; i <= 1000000; i++)
	{
		if (isNotPrime[i]) continue;
		P.push_back(i);
		for (int j = i * 2; j <= 1000000; j+=i)
			isNotPrime[j] = 1;
	}
	scanf("%lld %lld %lld",&a,&b,&l);
	ll sol = 1;
	int sz = P.size();
	A.resize(sz);
	B.resize(sz);
	L.resize(sz);
	for (int i = 0; i < sz; i++)
	{
		while (l%P[i] == 0)
		{
			l /= P[i];
			L[i]++;
		}
		while (a%P[i] == 0)
		{
			a /= P[i];
			A[i]++;
		}
		while (b%P[i] == 0)
		{
			b /= P[i];
			B[i]++;
		}
		L[i] -= max(A[i], B[i]);
		if (L[i] < 0)
		{
			puts("-1");
			return 0;
		}
	}
	if (l != 1)
	{
		puts("-1");
		return 0;
	}
	for (int i = 0; i < sz; i++)
	{
		if (L[i] > 0)
		{
			int g = max(A[i], B[i]) + L[i];
			while (g--)
				sol *= P[i];
		}
	}
	printf("%lld", sol);
}