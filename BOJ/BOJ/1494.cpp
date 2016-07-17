#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll> num;
ll f, s, N, val, sz = 2, zero = 0;
int main()
{
	scanf("%lld %lld %lld", &f, &s, &N);
	num.push_back(f), num.push_back(s);
	while (num.back() != 0)
	{
		ll next = abs(num[sz - 2] - num[sz - 1]);
		num.push_back(next);
		sz++;
	}
	zero = (sz - 1) % 3;
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &val);
		if (val < sz)
			printf("%lld\n", num[val]);
		else if (val % 3 == zero)
			puts("0");
		else
			printf("%lld\n", num[sz - 2]);
	}

}